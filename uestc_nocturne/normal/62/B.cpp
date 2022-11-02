#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
typedef __int64 LL;
int n,m,len,i;
char ch[120000],no[210000];
int le[210000][30],ri[210000][30],j;
__int64 ans;
int main()
{
	scanf("%d%d",&n,&m);
	scanf("%s",ch);
	for(i=0;i<26;i++)
	{le[0][i]=-1;}
	le[0][(int)(ch[0]-'a')]=0;
	for(i=1;i<m;i++)
	{
		for(j=0;j<26;j++)
		le[i][j]=le[i-1][j];
		le[i][(int)(ch[i]-'a')]=i;
	}
	for(i=0;i<26;i++)
	{ri[m-1][i]=-1;}
	ri[m-1][(int)(ch[m-1]-'a')]=m-1;
	for(i=m-2;i>=0;i--)
	{
		for(j=0;j<26;j++)
		ri[i][j]=ri[i+1][j];
		ri[i][(int)(ch[i]-'a')]=i;
	}
/*	for(i=0;i<m;i++)
	{
		for(j=0;j<26;j++)
		printf("%d %d  ",le[i][j],ri[i][j]);puts("");
	}*/
	while(n--)
	{
		scanf("%s",no);
		len=strlen(no);ans=0;
		if(len>m)
		{
			for(i=m;i<len;i++)
			for(j=0;j<26;j++)
			{ri[i][j]=-1;le[i][j]=le[i-1][j];}
		}
		for(i=0;i<len;i++)
		{
			if(le[i][no[i]-'a']==-1&&ri[i][no[i]-'a']==-1)
			{ans+=(LL)len;continue;}
			if(le[i][no[i]-'a']==-1)
			ans+=(LL)(ri[i][no[i]-'a']-i);
			else if(ri[i][no[i]-'a']==-1)
			ans+=(LL)(i-le[i][no[i]-'a']);
			else ans+=(LL)min(ri[i][no[i]-'a']-i,i-le[i][no[i]-'a']);
		}
		printf("%I64d\n",ans);
	}
}