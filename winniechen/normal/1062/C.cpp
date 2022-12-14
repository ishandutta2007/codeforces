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
#define ll long long
#define mod 1000000007
int a[N],n,Q,b[N],p[N],q[N];
int main()
{
	scanf("%d%d",&n,&Q);
	for(int i=1;i<=n;i++)scanf("%1d",&a[i]),a[i]?(b[i]=b[i-1]+1):(b[i]=b[i-1]);
	p[0]=1;for(int i=1;i<=n+1;i++)p[i]=(p[i-1]<<1)%mod;
	while(Q--)
	{
		int l,r;scanf("%d%d",&l,&r);
		int num=r-l+1,s=b[r]-b[l-1];
		num-=s;if(!s){puts("0");continue;}
		int ans=p[s]-1,now=p[s]-1;
		ans=(ans+(ll)now*(p[num]-1))%mod;
		printf("%d\n",(ans%mod+mod)%mod);
	}
}