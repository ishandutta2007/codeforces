#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
using namespace std;
#define ll long long
const int Base = 131;
const int N = 500005;
const int mod = 7000007;
char s[N];int n,ans,has[N];bool b[mod+5],f[N],g[N];
int main()
{
	scanf("%d%s",&n,s+1);b[0]=1;memset(g,1,sizeof(g));ans=1;
	for(int i=1;i<=n;i++)has[i]=s[i];
	for(int i=2;i<=1000;i++)
	{
		if(ans!=i-1)break;
		memset(b,0,sizeof(b));memcpy(f,g,sizeof(g));memset(g,0,sizeof(g));
		for(int j=n-i+1;j;j--)
		{
			if(j+i<=n&&f[j+i])b[has[j+i]]=1;
			if(b[has[j]]||b[has[j+1]])ans=i,g[j]=1;
		}
		for(int j=1;j<=n-i+1;j++)has[j]=(has[j]*Base+s[i+j-1])%mod;
	}
	printf("%d\n",ans);
}