#include<stdio.h>
#include<string.h>
#include<set>
int n,m;
char s[1020][1020],g[1020][1020];
std::set<int>v,h;
int fil(int l,int r,int u,int d)
{
	for(int i=l;i<=r;i++)
		if(g[i][u]=g[i][d]='#',s[i][u]=='.'||s[i][d]=='.')
			return 0;
	for(int i=u;i<=d;i++)
		if(g[l][i]=g[r][i]='#',s[l][i]=='.'||s[r][i]=='.')
			return 0;
	return 1;
}
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%s",s[i]+1);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			if(s[i][j]=='#'&&s[i][j-1]=='#'&&s[i][j+1]=='#')
				v.insert(i);
			if(s[i][j]=='#'&&s[i-1][j]=='#'&&s[i+1][j]=='#')
				h.insert(j);
		}
	if(v.size()>4)
		v.erase(++++v.begin(),----v.end());
	if(h.size()>4)
		h.erase(++++h.begin(),----h.end());
	for(int vl:v)for(int vr:v)for(int hu:h)for(int hd:h)
	for(int vL:v)for(int vR:v)for(int hU:h)for(int hD:h)
	if(vr-vl>1&&hd-hu>1&&vR-vL>1&&hD-hU>1)
	{
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				g[i][j]='.';
		if(fil(vl,vr,hu,hd)&&fil(vL,vR,hU,hD)&&memcmp(s,g,sizeof s)==0)
			return printf("YES\n%d %d %d %d\n%d %d %d %d\n",vl,hu,vr,hd,vL,hU,vR,hD),0;
	}
	puts("NO");
	return 0;
}