#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
using namespace std;
#define N 105
char s[N];int n;
int main()
{
	int T;scanf("%d",&T);
	while(T--)
	{
		scanf("%d%s",&n,s+1);int vis=0;
		for(int i=1;i<=(n>>1);i++)if(abs(s[i]-s[n-i+1])!=2&&abs(s[i]-s[n-i+1])!=0)vis=1;
		if(!vis)puts("YES");else puts("NO");
	}return 0;
}