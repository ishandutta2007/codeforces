//CF 963B
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
typedef double DB;
const int N = 222222;
int n,p[N],f[N];
vector<int> v[N];
void dfs0(int u){
	int i=v[u].size();
	while(i--){
		dfs0(v[u][i]);
		f[u]^=f[v[u][i]];
	}
	f[u]^=1;
}
void dfs(int u){
	int i=v[u].size(),x;
	while(i--){
		x=v[u][i];
		if(!f[x])
			dfs(x);
	}
	cout<<u<<endl;
	i=v[u].size();
	while(i--){
		x=v[u][i];
		if(f[x])
			dfs(x);
	}
}
int main()
{
	int i,rt;
	scanf("%d",&n);
	for(i=1;i<=n;i=i+1){
		scanf("%d",p+i);
		if(p[i])
			v[p[i]].push_back(i);
		else
			rt=i;
	}
	dfs0(rt);
	if(!f[rt])
		cout<<"NO\n";
	else{
		cout<<"YES\n";
		dfs(rt);
	}
	return 0;
}