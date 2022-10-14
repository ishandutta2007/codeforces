//
//  main.cpp
//  Round 469
//
//  Created by  on 2018/4/22.
//  Copyright  2018 . All rights reserved.
//

#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>

using namespace std;
typedef long long ll;
vector<ll> G[100010],rG[100010],vs;
ll cmp[100010] = {0},vis[100010] = {0},n,m,r,ans[100010] = {0},qlt[100010] = {0},epp[100010],rd[100010];
ll price[5000],cur,cup;
void add_edge(ll from,ll to){
	G[from].push_back(to);
	rG[to].push_back(from);
}
void dfs(ll num){
	vis[num] = 1;
	for(ll i=0;i<G[num].size();i++) if(!vis[G[num][i]])dfs(G[num][i]);
	vs.push_back(num);
}
void rdfs(ll num,ll k){
	ans[k] = min(ans[k],price[num]);
	cmp[num] = k;
	epp[k] = min(num,epp[k]);
	for(ll i=0;i<rG[num].size();i++) {
		if(cmp[rG[num][i]] == 0){
			rdfs(rG[num][i],k);
		}
	}
}
ll scc(){
	vs.clear();
	for(ll i=0;i<n;i++)if(!vis[i])dfs(i);
	ll cnt=0;
	for(ll i=(ll)(vs.size()-1);i>=0;--i){
		if(!cmp[vs[i]]){
			rdfs(vs[i],cnt+1);
			cnt+=1;
		}
	}
	return cnt;
}
int h,ti[100010],u,v;
ll ct[100010] = {0};
int main() {
	memset(ans,7,sizeof(ans));
	memset(epp,7,sizeof(epp));
	cin>>n>>m>>h;
	for(int i=0;i<n;i++) cin>>ti[i];
	for(int i=0;i<m;i++){
		cin>>u>>v;
		u-=1;
		v-=1;
		if((ti[u]+1)%h == ti[v]) add_edge(u, v);
		if((ti[v]+1)%h == ti[u]) add_edge(v, u);
	}
	ll fans = 0,sc=scc(),minn,mi = 100000000;
	for(ll i=0;i<n;i++){
		ct[cmp[i]]+=1;
		//cout<<cmp[i]<<endl;
	}
	for(ll i=0;i<n;i++){
		for(ll j=0;j<G[i].size();j++){
			if(cmp[i]!=cmp[G[i][j]]){
				rd[cmp[i]]+=1;
			}
		}
	}
	for(ll i=1;i<=sc;i++){
		//cout<<i<<' '<<rd[i]<<endl;
		if(rd[i]!=0)continue;
		if(ct[i]<mi){
			mi = ct[i];
			minn = i;
		}
	}
	cout<<mi<<endl;
	for(ll i=0;i<n;i++){
		if(cmp[i] == minn)cout<<i+1<<' ';
	}
	cout<<endl;
	return 0;
}