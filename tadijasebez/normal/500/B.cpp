#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
const int N=305;
int p[N],r[N];
int Find(int x)
{
	if(p[x]!=x) p[x]=Find(p[x]);
	return p[x];
}
void Union(int x, int y)
{
	x=Find(x);
	y=Find(y);
	if(x==y) return;
	if(r[x]>r[y]) p[y]=x;
	if(r[x]<r[y]) p[x]=y;
	if(r[x]==r[y]) r[x]++,p[y]=x;
}
int a[N],sol[N];
vector<int> pos[N],val[N];
char ch[N];
int main()
{
	int n,i,j;
	scanf("%i",&n);
	for(i=1;i<=n;i++) p[i]=i,scanf("%i",&a[i]);
	for(i=1;i<=n;i++)
	{
		scanf("%s",ch+1);
		for(j=1;j<=n;j++)
		{
			if(ch[j]=='1') Union(i,j);
		}
	}
	for(i=1;i<=n;i++)
	{
		int x=Find(i);
		pos[x].push_back(i);
		val[x].push_back(a[i]);
	}
	for(i=1;i<=n;i++)
	{
		sort(val[i].begin(),val[i].end());
		for(j=0;j<val[i].size();j++)
		{
			sol[pos[i][j]]=val[i][j];
		}
	}
	for(i=1;i<=n;i++) printf("%i ",sol[i]);
	printf("\n");
	return 0;
}