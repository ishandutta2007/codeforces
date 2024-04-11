#include<bits/stdc++.h>
using namespace std;
#define N 7001
#define MOD 998244353
#define LL long long
#define rep(i,a,b) for(int i=(a);i<=(b);++i)

bitset<N> a[100010],t1[N],t4[N];
int n,q,x,y,z,type,j,mu[N];
int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	scanf("%d%d",&n,&q);
	mu[1] = 1;
	rep(i,1,N-1) for(t1[i][i]=1,j=i+i;j<N;j+=i){
		t1[j][i] = 1;
		mu[j] -= mu[i];
	}
	rep(i,1,N-1) rep(j,1,(N-1)/i)
		if(mu[j]) t4[i][j*i] = 1;
	rep(i,1,q){
		scanf("%d%d%d",&type,&x,&y);
		if(type==1)
			a[x] = t1[y];
		else if(type==2){
			scanf("%d",&z);
			a[x] = a[y] ^ a[z];
		}else if(type==3){
			scanf("%d",&z);
			a[x] = a[y] & a[z];
		}else
			printf("%d",(a[x]&t4[y]).count()&1);
	} 
	return 0;
}