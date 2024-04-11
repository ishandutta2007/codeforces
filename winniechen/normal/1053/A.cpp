#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
using namespace std;
int n,m,k,ans[3][2];long long S;
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	if(k==1)return puts("NO"),0;
	S=1ll*n*m;
	int gcd=__gcd(S,(long long)k);
	int p=k/gcd;
	if(p>2)return puts("NO"),0;
	if(p==1)
	{
		ans[0][0]=0,ans[0][1]=0;
		int tmp=__gcd(gcd,m);
		if(tmp>=2)
		{
			ans[1][0]=0,ans[1][1]=(m/tmp)*2;
			ans[2][0]=n/(gcd/tmp),ans[2][1]=0;
		}else
		{
			ans[1][0]=0,ans[1][1]=m;
			ans[2][0]=n/gcd*2,ans[2][1]=0;
		}
	}else
	{
		ans[0][0]=0,ans[0][1]=0;
		int tmp=__gcd(gcd,m);
		ans[1][0]=0,ans[1][1]=m/tmp;
		ans[2][0]=n/(gcd/tmp),ans[2][1]=0;
	}
	puts("YES");
	for(int i=0;i<=2;i++)printf("%d %d\n",ans[i][0],ans[i][1]);
}