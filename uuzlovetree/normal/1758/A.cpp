#include<bits/stdc++.h>
#define maxn 2005
using namespace std;
int T;
char s[maxn];
char Ans[maxn];
int c[30];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		memset(c,0,sizeof(c));
		memset(Ans,0,sizeof(Ans));
		scanf("%s",s+1);
		int n=strlen(s+1);
		for(int i=1;i<=n;++i)++c[s[i]-'a'];
		for(int i=1;i<=n;++i)
		{
			for(int j=0;j<26;++j)if(c[j])
			{
				--c[j];
				Ans[i]=Ans[n*2-i+1]='a'+j;
				break;
			}
		}
		printf("%s\n",Ans+1);
	}
}