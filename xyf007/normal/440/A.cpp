#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int n;
bool f[100001];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		int x;
		scanf("%d",&x);
		f[x]=1;
	}
	for(int i=1;i<=n;i++)
	{
		if(!f[i])
		{
			printf("%d",i);
			return 0;
		}
	}
	return 0;
}