#include <iostream>
#include <cstdio>
using namespace std;
char a[70][70];
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int n,m;
		cin >> n >> m;
		for(int i=1;i<=n;i++)
			scanf("%s",a[i]+1);
		int flag=1;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(a[i][j]!='A')
				{
					flag=0;
					break;
				}
			}
			if(!flag) break;
		}
		if(flag)
		{
			puts("0");
			continue;
		}
		flag=1;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(a[i][j]!='P')
				{
					flag=0;
					break;
				}
			}
			if(!flag)
				break;
		}
		if(flag)
		{
			puts("MORTAL");
			continue;
		}
		flag=0;
		int t=1;
		for(int i=1;i<=n;i++)
			if(a[i][1]=='P') t=0;
		flag|=t;
		t=1;
		for(int i=1;i<=n;i++)
			if(a[i][m]=='P') t=0;
		flag|=t;
		t=1;
		for(int i=1;i<=m;i++)
			if(a[1][i]=='P') t=0;
		flag|=t;
		t=1;
		for(int i=1;i<=m;i++)
			if(a[n][i]=='P') t=0;
		flag|=t;
		if(flag)
		{
			puts("1");
			continue;
		}
		flag=0;
		for(int i=1;i<=n;i++)
		{
			t=1;
			for(int j=1;j<=m;j++)
			{
				if(a[i][j]=='P')
				{
					t=0;
					break;
				}
			}
			flag|=t;
		}
			for(int j=1;j<=m;j++)
			{
		for(int i=1;i<=n;i++)
		{
			t=1;
				if(a[i][j]=='P')
				{
					t=0;
					break;
				}
			}
			flag|=t;
		}
		if(a[1][1]=='A'||a[n][1]=='A'||a[1][m]=='A'||a[n][m]=='A'||n==1||m==1||flag)
		{
			puts("2");
			continue;
		}
		flag=0;
		for(int i=1;i<=n;i++)
			if(a[i][1]=='A') flag=1;
		for(int i=1;i<=n;i++)
			if(a[i][m]=='A') flag=1;
		for(int i=1;i<=m;i++)
			if(a[1][i]=='A') flag=1;
		for(int i=1;i<=m;i++)
			if(a[n][i]=='A') flag=1;
		if(flag)
		{
			puts("3");
			continue;
		}
		puts("4");
		continue;
	}
	return 0;
}