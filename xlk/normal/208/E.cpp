#include<stdio.h>
#include<vector>
using namespace std;
#define fe(i,n) for(__typeof(n.begin()) i=n.begin();i!=n.end();i++)
int n,m,x,y,t,f[100020][17];
int d[100020],l[100020],r[100020];
vector<int>e[100020];
vector<int>c[100020];
void dfs(int x,int y)
{
	d[x]=y;
	c[y].push_back(t);
	l[x]=t++;
	fe(i,e[x])
		dfs(*i,y+1);
	r[x]=t;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",f[i]);
	for(int i=1;i<=n;i++)
		e[f[i][0]].push_back(i);
	dfs(0,0);
	for(int i=1;i<17;i++)
		for(int j=1;j<=n;j++)
			f[j][i]=f[f[j][i-1]][i-1];
	scanf("%d",&m);
	for(;m--;)
	{
		scanf("%d %d",&x,&y);
		vector<int>&u=c[d[x]];
		for(int i=0;i<17;i++)
			if(y>>i&1)
				x=f[x][i];
		printf("%d ",x?lower_bound(u.begin(),u.end(),r[x])-lower_bound(u.begin(),u.end(),l[x])-1:0);
	}
	return 0;
}