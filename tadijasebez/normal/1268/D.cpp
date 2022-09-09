#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2050;
const int inf=1e9+7;
const int mod=998244353;
int mat[N][N],deg[N],tmp[N],n;
bool Check()
{
	for(int i=1;i<=n;i++) deg[i]=tmp[i];
	sort(deg+1,deg+1+n);
	reverse(deg+1,deg+1+n);
	for(int i=1,sum=0;i<n;i++)
	{
		sum+=deg[i];
		if(sum==i*(i-1)/2+i*(n-i)) return 0;
	}
	return 1;
}
void Flip(int x)
{
	for(int i=1;i<=n;i++)
	{
		tmp[i]-=mat[i][x];
		mat[i][x]^=1;
		tmp[i]+=mat[i][x];
		tmp[x]-=mat[x][i];
		mat[x][i]^=1;
		tmp[x]+=mat[x][i];
	}
}
void BruteForce()
{
	int ans=inf,cnt=0;
	for(int mask=0;mask<1<<n;mask++)
	{
		for(int i=1;i<=n;i++) if(mask>>(i-1)&1) Flip(i);
		int pc=__builtin_popcount(mask);
		if(Check())
		{
			if(ans>pc) ans=pc,cnt=0;
			if(ans==pc) cnt++;
		}
		for(int i=1;i<=n;i++) if(mask>>(i-1)&1) Flip(i);
	}
	if(ans==inf){ printf("-1\n");return;}
	for(int i=1;i<=ans;i++) cnt=(ll)cnt*i%mod;
	printf("%i %i\n",ans,cnt);
}
void Solve()
{
	if(Check()){ printf("0 1\n");return;}
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		Flip(i);
		if(Check()) cnt++;
		Flip(i);
	}
	printf("1 %i\n",cnt);
}
char base[N][N];
int main()
{
	scanf("%i",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",base[i]+1);
		for(int j=1;j<=n;j++) mat[i][j]=base[i][j]-'0',tmp[i]+=mat[i][j];
	}
	if(n<=6) BruteForce();
	else Solve();
	return 0;
}