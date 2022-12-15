#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MN=1e5+5;
ll bit[12][MN], N, K, i, j, x, arr[MN];
map<int,int> mp;

void upd(ll idx,ll p,ll v){for(;p<=N;p+=p&-p)bit[idx][p]+=v;}
ll qu(ll idx,ll p){ll r=0;for(;p;p-=p&-p)r+=bit[idx][p]; return r;}

int main(){
	for(scanf("%d%d",&N,&K),i=1;i<=N;i++)
		scanf("%d",&arr[i]),mp[arr[i]]=0;
	K++; i = 1; upd(0,1,1);
	for(auto it=mp.begin();it!=mp.end();it++)
		it->second = i++;
	for(i=1;i<=N;i++){
		ll idx = mp[arr[i]];
		for(j=K;j>=1;j--)
			upd(j,idx,qu(j-1,idx));
	}
	printf("%lld\n",qu(K,N));
	return 0;
}