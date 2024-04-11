#include<bits/stdc++.h>
using namespace std;
const int max_n=100+5;
char L[max_n][max_n];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%s",L[i]+1);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
		{
			if(i+6<=n)
			{
				string S;
				for(int k=0;k<=6;++k)
					S+=L[i+k][j];
				if(S=="theseus")
				{
					puts("YES");
					return 0;
				}
			}
			if(j+6<=n)
			{
				string S;
				for(int k=0;k<=6;++k)
					S+=L[i][j+k];
				if(S=="theseus")
				{
					puts("YES");
					return 0;
				}
			}
			if(i+6<=n&&j+6<=n)
			{
				string S;
				for(int k=0;k<=6;++k)
					S+=L[i+k][j+k];
				if(S=="theseus")
				{
					puts("YES");
					return 0;
				}
			}
		}
	puts("NO");
	return 0;
}