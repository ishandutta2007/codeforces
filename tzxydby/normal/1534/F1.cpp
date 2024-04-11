#include<bits/stdc++.h>
using namespace std;
const int N=400005;
int n,m,l[N],r[N],a[N],f[N],t,x;
char s[N];
inline int z(int x,int y){return x*m+y;}
void dfs(int x,int y,int b,int t)
{
	if((t?r[z(x,y)]:l[z(x,y)])!=-1)
		return;
	(t?r[z(x,y)]:l[z(x,y)])=b;
	if(x+1<n) dfs(x+1,y,b,t);
	if(x&&s[z(x-1,y)]=='#') dfs(x-1,y,b,t);
	if(y&&s[z(x,y-1)]=='#') dfs(x,y-1,b,t);
	if(y+1<m&&s[z(x,y+1)]=='#') dfs(x,y+1,b,t);
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
		scanf("%s",s+i*m);
	for(int i=0;i<m;i++)
		scanf("%d",&a[i]);
	memset(l,-1,sizeof(l));
	memset(r,-1,sizeof(r));
	for(int j=0;j<m;j++)
		for(int i=0;i<n;i++)
			if(s[z(i,j)]=='#')
				dfs(i,j,j,0);
	for(int j=m-1;j>=0;j--)
		for(int i=0;i<n;i++)
			if(s[z(i,j)]=='#')
				dfs(i,j,j,1);
	for(int i=0;i<=m+1;i++)
		f[i]=m+1;
	for(int j=0;j<m;j++)
	{
		if(!a[j])
			continue;
		for(int i=n-1;i>=0;i--)
		{
			if(s[z(i,j)]!='#')
				continue;
			a[j]--;
			if(!a[j])
			{
				f[l[z(i,j)]]=min(f[l[z(i,j)]],r[z(i,j)]+1);
				break;
			}
		}
	}
	for(int i=m;i>=0;i--)
		f[i]=min(f[i],f[i+1]);
	while(x<m+1)
		x=f[x],t++;
	printf("%d\n",t-1);
	return 0;
}