#include <bits/stdc++.h>
using namespace std;

const int MN = 1e5+5;
map<string,int> idx;
int cost[MN], id[MN], mc[MN], N, M, K, i, j;
long long ans;

int main(){
	for(scanf("%d%d%d",&N,&K,&M),i=1;i<=N;i++){
		string s; cin >> s, idx[s] = i;
	}
	for(i=1;i<=N;i++) scanf("%d",&cost[i]);
	for(i=1;i<=K;i++) mc[i]=1<<30;
	for(i=1;i<=K;i++){
		int y; scanf("%d",&y);
		while(y--){
			int x;scanf("%d",&x);
			mc[i]=min(mc[i],cost[x]);
			id[x] = i;
		}
	}
	for(i=1;i<=M;i++){
		string s; cin >> s;
		ans += mc[id[idx[s]]];
	}
	printf("%lld\n",ans);
	return 0;
}