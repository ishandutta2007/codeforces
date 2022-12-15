#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,ssse3,sse3,sse4,popcnt,avx,mmx,abm,tune=native")
#include <bits/stdc++.h>
using namespace std;

const int MN = 2e5+5;
typedef long long ll;
ll ans[MN], N, i, x, y, k, d[MN], last, cnt;
pair<ll,ll> arr[2*MN], idk[MN];

int main(){
	for(scanf("%lld",&N),i=1;i<=N;i++){
		scanf("%lld%lld",&x,&y);
		arr[2*i-1]={x,i};
		arr[2*i]={y+1,i};
		//idk[i] = {x, y};
	}
	sort(arr+1,arr+2*N+1,[](pair<ll,ll> i,pair<ll,ll>j){return i.first<j.first;});
	last = arr[2*N].first;
	for(i=1;i<=2*N;i++){
		pair<ll,ll> cur=arr[i];
		if(d[cur.second]) k--;
		else k++,d[cur.second]=1;
		ans[k]+=arr[i+1].first-arr[i].first;
	}
	for(i=1;i<=N;i++)
		printf("%lld ",ans[i]);
	getchar(); getchar();
}