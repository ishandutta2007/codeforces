#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<iostream>
using namespace std;
typedef __int64 LL;
char ch1[11000],ch2[1001000];
int ne[11000][30];
int i,j,n,m,te,has[120],ans,po;
int main()
{
	while(~scanf("%s%s",ch1,ch2))
	{
		n=strlen(ch1);
		m=strlen(ch2);
		memset(has,0,sizeof(has));
		for(i=0;i<n;i++)
		has[ch1[i]-'a']=1;
		bool can=true;
		for(i=0;i<m;i++)
		{
			if(has[ch2[i]-'a']==0)
			{can=false;break;}
		}
		if(!can){puts("-1");continue;}
		memset(ne,-1,sizeof(ne));
		for(i=n-1;i>=0;i--)
		{
			for(j=0;j<26;j++)
			ne[i][j]=ne[i+1][j];
			ne[i][ch1[i]-'a']=i;
		}
		ans=1;po=0;
		for(i=0;i<m;i++)
		{
	//		printf("%d %d %d\n",ans,po,ne[po][ch2[i]-'a']);
			if(po>=n)
			{
				po=ne[0][ch2[i]-'a']+1;ans++;
			}
			else if(ne[po][ch2[i]-'a']==-1)
			{
				po=ne[0][ch2[i]-'a']+1;ans++;
			}
			else
			{
				po=ne[po][ch2[i]-'a']+1;
			}
		}
		printf("%d\n",ans);
	}
}