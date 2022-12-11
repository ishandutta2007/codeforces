#include<bits/stdc++.h>
#define maxn 1505
using namespace std;
int n,q;
char s[maxn];
int f[27][maxn];
int main()
{
	scanf("%d",&n);
	scanf("%s",s+1);
	for(int i=1;i<=n;++i)
	{
		for(int c=0;c<26;++c)
		{
			char col=c+'a';
			int num=0;
			for(int j=i;j<=n;++j)
			{
				if(s[j]!=col)num++;
				f[c][num]=max(f[c][num],j-i+1);
			}
		}
	}
	for(int c=0;c<26;++c)
		for(int j=1;j<=n;++j)f[c][j]=max(f[c][j],f[c][j-1]);
	scanf("%d",&q);
	while(q--)
	{
		int x;
		char col[3];
		scanf("%d%s",&x,col);
		printf("%d\n",f[col[0]-'a'][x]);
	}
	return 0;
}