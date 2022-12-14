#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
using namespace std;
#define N 500005
int a[N],b[N],n,c,ans,bac[N];
int main()
{
	scanf("%d%d",&n,&c);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=n;i;i--)bac[i]=bac[i+1]+(a[i]==c);
	for(int i=1;i<=n;i++)
	{
		if(a[i]==c)b[c]++,ans=max(b[c],ans);
		else
		{
			if(b[a[i]]<b[c])b[a[i]]=b[c]+1;
			else b[a[i]]++;
			ans=max(b[a[i]]+bac[i+1],ans);
		}
	}
	printf("%d\n",ans);
}