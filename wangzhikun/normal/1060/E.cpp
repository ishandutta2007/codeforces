//  Created by WangZhikun on 2018/10/4.

#include <cstdio>
#include <vector>
#include <iostream>
#define PB push_back
using namespace std;
typedef long long ll;

ll n,u,v,w,rt,ctsz,ans = 0;
ll kgb[200020] = {0},sz[200020] = {0},ccv[200020] = {0},mx[200020],depth[200020],suj,suo,csj,cso,snj,sno,cnj,cno;
vector<ll> G[200020];

void dfs1(ll num,ll fa){
	sz[num] = 1;mx[num]=0;
	for(ll i=0;i<G[num].size();i++){
		ll ct = G[num][i];
		if(kgb[ct]||ct == fa)continue;
		dfs1(ct,num);
		sz[num]+=sz[ct];
		mx[num] = max(mx[num],sz[ct]);
	}
	mx[num] = max(mx[num],ctsz-sz[num]);
	if(mx[num]<mx[rt])rt = num;
}
void dfs2(ll num,ll fa){
	depth[num] = depth[fa]+1;
	ans+=(depth[num]+1)/2;
	if(depth[num]%2){
		cnj+=1;csj+=depth[num];
		ans+=(depth[num]*snj+suj)/2;
		ans+=((depth[num]+1)*sno+suo)/2;
	}else{
		cno+=1;cso+=depth[num];
		ans+=((depth[num]+1)*snj+suj)/2;
		ans+=(depth[num]*sno+suo)/2;
	}
	for(ll ct:G[num]){
		if(kgb[ct]||ct == fa)continue;
		dfs2(ct,num);
	}
}
void solve(ll num){
	rt = 200005;mx[rt] = 10000005;
	dfs1(num,-1);
	depth[rt] = 0;
	kgb[rt] = 1;
	suj = suo = snj = sno = 0;
	for(auto ech:G[rt]){
		csj = cso = cnj = cno = 0;
		ll ct = ech;
		if(kgb[ct])continue;
		dfs2(ct,rt);
		suj+=csj;snj+=cnj;
		suo+=cso;sno+=cno;
	}
	for(auto ech:G[rt]){
		if(kgb[ech])continue;
		ctsz = sz[ech];
		solve(ech);
	}
}
int main(){
	cin>>n;
	for(ll i=1;i<n;i++){
		cin>>u>>v;
		G[u].PB(v);
		G[v].PB(u);
	}
	ctsz = n;solve(1);
	cout<<ans<<endl;;
	return 0;
}