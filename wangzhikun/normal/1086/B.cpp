#include <queue>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iomanip>
#include <cstring>
#include <iostream>
#include <algorithm>
#define set0(x) memset(x,0,sizeof(x))
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
template<typename T> void read(T &x){
	x = 0;char ch = getchar();int f = 1;
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}x*=f;
}
double k;
ll n,m,u,v,sz[300030] = {0};
vector<ll> G[300030];
void dfs(int num,int f = -1){
	if(G[num].size() == 1)sz[num] = 1;
	for(auto ct:G[num]){
		if(ct==f)continue;
		dfs(ct,num);
		sz[num]+=sz[ct];
	}
}
int main() {
	cout<<setprecision(15)<<fixed;
	read(n);cin>>k;
	if(n == 2){
		cout<<k<<endl;
		return 0;
	}
	for(int i=1;i<n;i++){
		read(u);read(v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	int rt = 1;
	for(int i=1;i<=n;i++){
		if(G[i].size()>1)rt = i;
	}
	dfs(rt);
	cout<<k*2/(1.0*sz[rt])<<endl;
	return 0;
}