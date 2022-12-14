#include <cstdio>
#include <algorithm>
#include <iostream>
#include <queue>
#include <cstring>
#include <cmath>
#include <cstdlib>
using namespace std;
#define N 1005
char s[N];
int n;
struct node
{
	int c[30];
	int rot;
}a[N];
bool b[1<<26];
int main()
{
	int sum=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s+1);
		int len=strlen(s+1);
		for(int j=1;j<=len;j++)
		{
			int x=s[j]-'a';
			if(!a[i].c[x])
			{
				a[i].c[x]=1;
				a[i].rot|=(1<<x);
			}
		}
		if(!b[a[i].rot])
		{
			sum++;
			b[a[i].rot]=1;
		}
	}
	printf("%d\n",sum);
	return 0;
}