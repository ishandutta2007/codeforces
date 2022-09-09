#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>
#include <cstring>
#include <map>
using namespace std;
#define pb push_back
const int N=100050;
map<string,int> id;
int cnt,sz[N],f[N],R[N],sol,ans;
char s[N];
vector<int> E[N];
int max(int a, int b){ return a>b?a:b;}
void DFS(int u)
{
	if(E[u].size()) sz[u]=1;
	if(E[u].empty()) f[u]=1;
	for(int i=0;i<E[u].size();i++)
	{
		int v=E[u][i];
		DFS(v);sz[u]+=sz[v];f[u]+=f[v];
	}
	sol=max(sol,sz[u]-1);
	ans=max(ans,f[u]);
}
int main()
{
	while(~scanf("%s",s+1))
	{
		int n=strlen(s+1),i;
		string t;
		for(i=1;i<=3;i++) t+=s[i];
		int par=0;
		while(i<=n)
		{
			for(;i<=n && s[i]!='\\';i++) t+=s[i];
			if(s[i]=='\\') t+=s[i],i++;
			if(!id[t])
			{	
				id[t]=++cnt;
				if(par) E[par].pb(id[t]),R[id[t]]++;
			}
			par=id[t];
		}
	}
	for(int i=1;i<=cnt;i++) if(!R[i]) DFS(i);
	printf("%i %i\n",sol,ans);
	return 0;
}