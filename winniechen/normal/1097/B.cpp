#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
using namespace std;
#define N 16
int a[N],now,ans,n;
void dfs(int dep,int now)
{
	if(dep==n+1){if(!now)ans=1;return ;}
	dfs(dep+1,(now+a[dep])%360),dfs(dep+1,(now-a[dep]+360)%360);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);dfs(1,0);
	puts(ans?"YES":"NO");
}