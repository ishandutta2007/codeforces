//  Created by WangZhikun on 2019/5/31.
#include <map>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define PB push_back
#define debug(x) //cerr<<#x<<'='<<x<<endl
using namespace std;
typedef long long ll;

ll n,u,v,w,rt,ctsz;
ll kgb[200020] = {0},sz[200020] = {0},mx[200020],depth[200020],ans[200020];
vector<ll> G[200020];
char str[200020];
int Mp[1100010] = {0};
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

ll dfs2(ll num,ll fa,ll cv){
	ll ccnt = 0;
	cv^=(1<<(str[num]-'a'));
	for(ll ct:G[num]){
		if(kgb[ct]||ct == fa)continue;
		ccnt+=dfs2(ct,num,cv);
	}
	for(int i=0;i<20;i++) ccnt+=Mp[cv^(1<<i)];
	ccnt+=Mp[cv];
	ans[num]+=ccnt;
	//cout<<"  "<<num<<' '<<ccnt<<endl;
	return ccnt;
}


void dfs3(ll num,ll fa,ll cv,int cd){
	cv^=(1<<(str[num]-'a'));
	for(ll ct:G[num]){
		if(kgb[ct]||ct == fa)continue;
		dfs3(ct,num,cv,cd);
	}
	Mp[cv]+=cd;
}

void solve(ll num){
	rt = 200005;mx[rt] = 10000005;
	dfs1(num,-1);
	depth[rt] = 0;
	kgb[rt] = 1;
	debug(rt);
	ll ccnt = 0;
	Mp[(1<<(str[rt]-'a'))]+=1;
	for(auto ech:G[rt])if(!kgb[ech])dfs3(ech,rt,(1<<(str[rt]-'a')),1);
	for(auto ech:G[rt]){
		if(kgb[ech])continue;
		dfs3(ech,rt,(1<<(str[rt]-'a')),-1);
		ccnt+=dfs2(ech,rt,0);
		dfs3(ech,rt,(1<<(str[rt]-'a')),1);
	}
	//for(int i=0;i<10;i++)cout<<Mp[i]<<' ';cout<<endl;
	//cout<<"::"<<ccnt<<endl;
	for(int i=0;i<20;i++){
		if(Mp[1<<i]) debug((1<<i));
		ccnt+=Mp[(1<<i)];
	}ccnt+=Mp[0];
	for(auto ech:G[rt])if(!kgb[ech])dfs3(ech,rt,(1<<(str[rt]-'a')),-1);
	Mp[(1<<(str[rt]-'a'))]-=1;
	//cout<<"::"<<ccnt<<endl;
	ccnt/=2;
	ans[rt]+=ccnt+1;
	//cout<<"Ans : ";for(int i=0;i<10;i++)cout<<ans[i]<<' ';cout<<endl;
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
	
	cin>>(str+1);
	ctsz = n;solve(1);
	for(int i=1;i<=n;i++){
		cout<<ans[i]<<' ';
	}
	cout<<endl;
	return 0;
}