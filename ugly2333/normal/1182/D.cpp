//CF1182D
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
typedef double DB;
const int N = 111111;
const int B = 223333;
const int MO = 1e9+33;
int n,h[N];
vector<int> v[N];
void dfs(int u,int fa){
	int i,x,o=-1;
	for(i=0;i<v[u].size();i=i+1){
		x=v[u][i];
		if(x==fa)
			continue;
		dfs(x,u);
		if(h[x]==-1)
			h[u]=-1;
		else{
			if(o==-1)
				o=h[x];
			if(o!=h[x])
				h[u]=-1;
		}
	}
	if(!h[u])
		h[u]=((LL)o*B+v[u].size()+MO)%MO;
}
void solve(int u,int fa,int hh){
	int i,x,y=-1;
	for(i=0;i<v[u].size();i=i+1){
		x=v[u][i];
		if(x==fa)
			continue;
		if(hh!=h[x]){
			if(y==-1)
				y=x;
			else
				y=-2;
		}
	}
	if(y==-1){
		cout<<u;
		exit(0);
	}
	if(y==-2)
		return;
	solve(y,u,((LL)hh*B+v[u].size()+MO)%MO);
}
int main()
{
	int i,x,y,o;
	scanf("%d",&n);
	for(i=1;i<n;i=i+1){
		scanf("%d%d",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	if(n==1){
		cout<<1;
		return 0;
	}
	for(i=1;i<=n;i=i+1)
		if(v[i].size()==1)
			break;
	dfs(i,0);
	if(h[i]>=0){
		cout<<i;
		return 0;
	}
	solve(v[i][0],i,((LL)-1*B+1+MO)%MO);
	cout<<-1;
	return 0;
}