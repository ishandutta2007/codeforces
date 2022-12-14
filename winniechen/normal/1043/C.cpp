#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
using namespace std;
#define N 1005
#define ll long long
char s[N],tmp[N];
int n,flag,ans[N];
int main()
{
	scanf("%s",s+1);n=strlen(s+1);
	for(int i=1;i<=n;i++)
	{
		if(s[i]<=s[1])
		{
			char tmp=s[i];
			for(int j=i-1;j;j--)s[j+1]=s[j];
			s[1]=tmp;
			ans[i]^=1,ans[i-1]^=1;
		}
		// for(int j=1;j<=i;j++)tmp[i-j+1]=s[j];tmp[i+1]='\0';
		// if(strcmp(tmp+1,s+1)>0&&flag)flag^=1,ans[i]=1;
		// if(strcmp(tmp+1,s+1)<0&&!flag)flag^=1,ans[i]=1;
	}
	for(int i=1;i<=n;i++)printf("%d ",ans[i]);puts("");
}