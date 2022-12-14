#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <cmath>
using namespace std;
#define N 1005
struct node
{
	char s[N];
	unsigned x;
}a[N],t[N];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		unsigned b,c,d,e;
		scanf("%s %d.%d.%d.%d",a[i].s,&b,&c,&d,&e);
		a[i].x=b<<24|c<<16|d<<8|e;
	}
	for(int i=1;i<=m;i++)
	{
		unsigned b,c,d,e;
		scanf("%s %d.%d.%d.%d;",t[i].s,&b,&c,&d,&e);
		unsigned u=b<<24|c<<16|d<<8|e;
		for(int j=1;j<=n;j++)
		{
			if(a[j].x==u)
			{
				printf("%s %d.%d.%d.%d; #%s\n",t[i].s,b,c,d,e,a[j].s);
				break;
			}
		}
	}
	puts("");
	return 0;
}