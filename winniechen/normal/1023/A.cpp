#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
#include <set>
#include <vector>
using namespace std;
#define N 200005
int n,m,p;char s[N],t[N];
int main()
{
	scanf("%d%d%s%s",&n,&m,s+1,t+1);
	for(int i=1;i<=n;i++)if(s[i]=='*')p=i;if(p&&n-1>m){puts("NO");return 0;}else if(!p&&n!=m){puts("NO");return 0;}
	for(int i=1;i<p;i++)if(s[i]!=t[i]){puts("NO");return 0;}
	for(int i=n;i>p;i--)if(s[i]!=t[m-n+i]){puts("NO");return 0;}
	puts("YES");return 0;
}