#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
using namespace std;
#define N 1000005
int n,x,b[N],ans;
int main()
{
	scanf("%d%d",&n,&x);ans=1<<30;memset(b,0x3f,sizeof(b));
	for(int i=1,y;i<=n;i++)
	{
		scanf("%d",&y);
		ans=min(ans,b[y]);ans=min(ans,b[y&x]+1);
		b[y]=0;b[y&x]=min(1,b[y&x]);
	}printf("%d\n",ans>=3?-1:ans);
}