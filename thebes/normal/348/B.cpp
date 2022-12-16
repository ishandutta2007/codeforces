#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MN = 1e5+5;
ll gcd(ll a,ll b){return(a)?gcd(b%a,a):b;}
ll ch[MN], N, val[MN], i, x, y, tot, cnt[MN];
vector<int> adj[MN];

void dfs(int n,int p){
	for(auto v : adj[n]){
		if(v == p) continue;
		cnt[n]++; dfs(v, n);
	}
}

bool idk(int n,int p){
	ch[n] = 1LL;
	for(auto v : adj[n]){
		if(v == p) continue;
		if(idk(v,n)) return 1;
		ch[n]=ch[n]/gcd(ch[n],ch[v])*ch[v];
		if(ch[n]>tot) return 1;
	}
	if(cnt[n]) ch[n]*=cnt[n];
	return(ch[n]>tot);
}

bool solve(int n,int p,ll rem){
	if(!cnt[n]) return(rem<=val[n]);
	for(auto v : adj[n]){
		if(v == p) continue;
		if(!solve(v,n,rem/cnt[n])) return 0;
	}
	return 1;
}

int main(){
	for(scanf("%d",&N),i=1;i<=N;i++)
		scanf("%d",&val[i]),tot+=val[i];
	for(i=1;i<N;i++){
		scanf("%d%d",&x,&y);
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	dfs(1, 0);
	if(idk(1,0)) printf("%lld\n",tot);
	else{
		x=0; y=ceil(tot/(double)ch[1])+1;
		while(x<y){
			ll m=x+y>>1;
			if(solve(1,0,m*ch[1])) x=m+1;
			else y=m;
		}
		x--;
		printf("%lld\n",tot-x*ch[1]);
	}
	return 0;
}