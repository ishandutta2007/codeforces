#include <bits/stdc++.h>
using namespace std;
char a[110][110];
char type[110];
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>a[i][j];
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=1;j<m;j++)
		{
			if(a[i][j]!=a[i][j-1])
			{
				puts("NO");
				return 0;
			}
		}
		type[i]=a[i][0];
	}
	for(int i=1;i<n;i++)
	{
		if(type[i]==type[i-1])
		{
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	return 0;
}