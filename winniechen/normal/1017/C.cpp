#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
using namespace std;
#define N 100005
int n,ans[N];
int main()
{
	scanf("%d",&n);int t=(int)ceil(sqrt(n)),i;
	for(i=1;i<=n;)
	{
		int x=t,tmp=i;
		while(x--)ans[i++]=x+tmp;
		if(i+t>n)break;
	}t=0;while(i<=n)ans[i++]=n-t,t++;
	for(int i=1;i<=n;i++)printf("%d ",ans[i]);puts("");
}