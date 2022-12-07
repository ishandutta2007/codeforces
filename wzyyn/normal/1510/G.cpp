#include<bits/stdc++.h>
using namespace std;

const int inf=1000000000;
int T,n,k,f[110][110],g[110][110],siz[110],x,ff[110],gg[110];
vector<int> v[110],ansf[110][110],ansg[110][110],ansff[110],ansgg[110];

void dfs(int x)
{
	siz[x]=1;
	g[x][1]=f[x][1]=0,ansf[x][1].push_back(x),ansg[x][1].push_back(x);
	for (int i=0,sz=v[x].size(); i<sz; i++)
	{
		int t=v[x][i]; dfs(t);
		for (int j=0; j<=n; j++) ff[j]=f[x][j],gg[j]=g[x][j],ansff[j]=ansf[x][j],ansgg[j]=ansg[x][j];
		for (int j=1; j<=siz[x]; j++)
			for (int k=1; k<=siz[t]; k++)
			{
				if (f[x][j]+2+g[t][k]<ff[j+k])
				{
					ff[j+k]=f[x][j]+2+g[t][k];
					ansff[j+k].clear();
					ansff[j+k].push_back(x);
					for (int l=0,sz=ansg[t][k].size(); l<sz; l++) ansff[j+k].push_back(ansg[t][k][l]);
					for (int l=0,sz=ansf[x][j].size(); l<sz; l++) ansff[j+k].push_back(ansf[x][j][l]);
				}
				if (f[t][k]+1+g[x][j]<ff[j+k])
				{
					ff[j+k]=f[t][k]+1+g[x][j];
					ansff[j+k].clear();
					for (int l=0,sz=ansg[x][j].size(); l<sz; l++) ansff[j+k].push_back(ansg[x][j][l]);
					for (int l=0,sz=ansf[t][k].size(); l<sz; l++) ansff[j+k].push_back(ansf[t][k][l]);
				}
				if (gg[j+k]>g[x][j]+2+g[t][k])
				{
					gg[j+k]=g[x][j]+2+g[t][k];
					ansgg[j+k].clear();
					ansgg[j+k].push_back(x);
					for (int l=0,sz=ansg[t][k].size(); l<sz; l++) ansgg[j+k].push_back(ansg[t][k][l]);
					for (int l=0,sz=ansg[x][j].size(); l<sz; l++) ansgg[j+k].push_back(ansg[x][j][l]);
				}
			}
		siz[x]+=siz[t];
		for (int j=1; j<=siz[x]; j++) f[x][j]=ff[j],g[x][j]=gg[j],ansf[x][j]=ansff[j],ansg[x][j]=ansgg[j];
	}
}

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d",&n,&k);
		for (int i=1; i<=n; i++) v[i].clear();
		for (int i=2; i<=n; i++) scanf("%d",&x),v[x].push_back(i);
		for (int i=0; i<=n; i++)
			for (int j=0; j<=n; j++) f[i][j]=g[i][j]=inf,ansf[i][j].clear(),ansg[i][j].clear();
		dfs(1),printf("%d\n",f[1][k]);
		for (int i=0,sz=ansf[1][k].size(); i<sz; i++) printf("%d%c",ansf[1][k][i],(i==sz-1?'\n':' '));
	}
	return 0;
}