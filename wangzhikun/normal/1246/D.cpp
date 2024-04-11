#include <set>
#include <queue>
#include <cmath>
#include <bitset>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#define debug(x) cerr<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
template<typename T> void read(T &x){
	x = 0;char ch = getchar();ll f = 1;
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}x*=f;
}

int n,p[100010],depth[100010],mdepth[100010];
vector<int> ops,ve,G[100010];

void dfs0(int num){
	mdepth[num] = depth[num];
	for(auto ct:G[num]){
		depth[ct] = depth[num]+1;
		dfs0(ct);
		mdepth[num] = max(mdepth[num],mdepth[ct]);
	}
}

int dfs1(int num){
	ve.push_back(num);
	int msz = 0,mi = -1;
	
	for(auto ct:G[num]){
		if(mdepth[ct]>msz){
			mi = ct;
			msz = mdepth[ct];
		}
	}
	if(mi == -1)return 1;
	int lsz = 0;
	for(auto ct:G[num]){
		if(ct == mi)continue;
		for(int j=0;j<lsz;j++)ops.push_back(ct);
		lsz = dfs1(ct);
	}
	for(int j=0;j<lsz;j++)ops.push_back(mi);
	return dfs1(mi)+1;
}

int main() {
	read(n);
	for(int i=1;i<=n-1;i++){
		read(p[i]);
		G[p[i]].push_back(i);
	}
	dfs0(0);
	//cout<<233<<endl;
	dfs1(0);
	for(int i=0;i<n;i++){
		cout<<ve[i]<<' ';
	}
	cout<<endl;
	cout<<ops.size()<<endl;
	for(auto ct:ops){
		cout<<ct<<' ';
	}
	cout<<endl;
	return 0;
}