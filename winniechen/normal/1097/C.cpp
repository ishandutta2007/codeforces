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
#define ll long long
char s[N];
int n,a[N][2],tmp;long long ans;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s+1);int len=strlen(s+1),now=0,hav=0;
		for(int j=1;j<=len;j++)
		{
			if(s[j]=='(')now++;
			else
			{
				if(!now)hav++;
				else now--;
			}
		}
		if(hav&&now)continue;
		if(now)a[now][0]++;
		else if(hav)a[hav][1]++;
		else tmp++;
	}
	ans=tmp>>1;
	for(int i=1;i<=500000;i++)ans+=min(a[i][0],a[i][1]);
	printf("%lld\n",ans);
}