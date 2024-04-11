#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
char s[100020];
char w[3];
int g[30][30];
int f[100020][30];
int n,l,i,j,k;
int main()
{
	scanf("%s",s);
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%s",w);
		g[w[0]-'a'][w[1]-'a']=1;
		g[w[1]-'a'][w[0]-'a']=1;
	}
	l=strlen(s);
	memset(f,0x3f,sizeof(f));

	for(j=0;j<26;j++)
		f[0][j]=1;
	f[0][s[0]-'a']=0;
	for(i=1;i<l;i++)
	{
		for(j=0;j<26;j++)
		{
			if(s[i]==j+'a')
				for(k=0;k<26;k++)
				{
					if(!g[j][k])
						f[i][j]=min(f[i][j],f[i-1][k]);
				}
			else
				f[i][j]=f[i-1][j]+1;
		}
	}
	int ans=0x3ffffff;
	for(i=0;i<26;i++)
		ans=min(ans,f[l-1][i]);
	printf("%d",ans);
	return 0;
}