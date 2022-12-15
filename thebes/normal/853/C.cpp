#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,ssse3,sse3,sse4,popcnt,avx,mmx,abm,tune=native")
#include <bits/stdc++.h>
using namespace std;

const int MN=2e5+5;
int bit[MN], N, M, i, j, arr[MN], temp[MN];
struct qur{int x, y, a, b, id;}a[MN];
long long ans[MN];

void upd(int p){for(;p<=N;p+=p&-p)bit[p]++;}
int qu(int p){int r=0;for(;p>0;p-=p&-p)r+=bit[p]; return r;}

int main(){
	for(scanf("%d%d",&N,&M),i=1;i<=N;i++)
		scanf("%d",&arr[i]),temp[arr[i]]=i;
	for(i=1;i<=M;i++){
		scanf("%d%d%d%d",&a[i].y,&a[i].x,&a[i].b,&a[i].a);
		//a[i].x = N-a[i].x+1; a[i].a = N-a[i].a+1;
		//a[i].y = N-a[i].y+1; a[i].b = N-a[i].b+1;
		a[i].id = i; ans[i] = 1LL*N*(N-1)/2;
	}
	sort(a+1,a+M+1,[](qur i,qur j){return i.y<j.y;});
	for(i=j=1;i<=N;i++){
		for(;j<=M&&a[j].y<=i;j++){
			long long tmp = qu(a[j].x-1);
			ans[a[j].id] += tmp*(tmp-1)/2;
			tmp = qu(N)-qu(a[j].a);
			ans[a[j].id] += tmp*(tmp-1)/2;
		}
		upd(arr[i]);
	}
	memset(bit, 0, sizeof(bit));
	sort(a+1,a+M+1,[](qur i,qur j){return i.b<j.b;});
	for(i=N,j=M;i>=1;i--){
		for(;j>=1&&a[j].b>=i;j--){
			long long tmp = qu(a[j].x-1);
			ans[a[j].id] += tmp*(tmp-1)/2;
			tmp = qu(N)-qu(a[j].a);
			ans[a[j].id] += tmp*(tmp-1)/2;
		}
		upd(arr[i]);
	}
	for(i=1;i<=M;i++){
		long long tmp=a[i].x-1;
		ans[a[i].id]-=tmp*(tmp-1)/2;
		tmp=N-a[i].a;
		ans[a[i].id]-=tmp*(tmp-1)/2;
		tmp=a[i].y-1;
		ans[a[i].id]-=tmp*(tmp-1)/2;
		tmp=N-a[i].b;
		ans[a[i].id]-=tmp*(tmp-1)/2;
	}
	for(i=1;i<=M;i++)
		printf("%lld\n",ans[i]);
	return 0;
}