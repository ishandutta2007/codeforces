#include<bits/stdc++.h>
using namespace std;
const int N=105;
int n;
char s[N][N],t[]="theseus";
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%s",s[i]+1);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j+6<=n;j++)
		{
			int f=1;
			for(int k=0;k<=6;k++)
				if(s[i][j+k]!=t[k])
					f=0;
			if(f)
			{
				puts("YES");
				return 0;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j+6<=n;j++)
		{
			int f=1;
			for(int k=0;k<=6;k++)
				if(s[j+k][i]!=t[k])
					f=0;
			if(f)
			{
				puts("YES");
				return 0;
			}
		}
	}
	for(int i=1;i+6<=n;i++)
	{
		for(int j=1;j+6<=n;j++)
		{
			int f=1;
			for(int k=0;k<=6;k++)
				if(s[i+k][j+k]!=t[k])
					f=0;
			if(f)
			{
				puts("YES");
				return 0;
			}
		}
	}
	puts("NO");
	return 0;
}