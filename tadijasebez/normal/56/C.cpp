#include <stdio.h>
#include <string>
#include <map>
#include <vector>
#include <cstring>
using namespace std;
#define pb push_back
const int N=1005;
vector<int> E[N];
map<string,int> id;
int tsz=1,root=1,a[N],cnt;
char s[N];int sz,lvl;
void DFS(int u)
{
	string t="";
	for(;s[lvl]!=':' && s[lvl]!='.';lvl++) t+=s[lvl];
	a[u]=id[t]?id[t]:id[t]=++cnt;
	while(s[lvl]!='.')
	{
		E[u].pb(++tsz);
		//printf("%i %i\n",u,tsz);
		lvl++;
		DFS(tsz);
	}
	lvl++;
}
int c[N],sol;
void Solve(int u)
{
	sol+=c[a[u]];
	c[a[u]]++;
	for(int i=0;i<E[u].size();i++)
	{
		int v=E[u][i];
		Solve(v);
	}
	c[a[u]]--;
}
int main()
{
	scanf("%s",s+1);
	sz=strlen(s+1);
	lvl=1;
	DFS(root);
	Solve(root);
	printf("%i\n",sol);
	return 0;
}