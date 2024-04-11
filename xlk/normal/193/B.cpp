#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

typedef long long ll;

int a[33];
int b[33];
int k[33];
int p[33];

int n = 0;
int u = 0;
int r = 0;
ll ans = -0x7FFFFFFFFFFFFFFFLL;

int updateAns()
{
	ll tans = 0;
	for(int i = 1;i <= n;i++) tans += (ll)a[i]*k[i];
	if(tans > ans) ans = tans;
	return 0;
}

inline int op1()
{
	for(int i = 1;i <= n;i++) a[i] ^= b[i];
	return 0;
}

inline int op2()
{
	int na[33];
	for(int i = 1;i <= n;i++) na[i] = a[p[i]]+r;
	memcpy(a,na,sizeof(na));
	return 0;
}

int dfs(int remain,int last)
{
	if((remain&1) == 0) // all op1
	{
		updateAns();
	}
	if(!remain) return 0;
	
	int oa[33];
	memcpy(oa,a,sizeof(oa));
	if(last != 1)
	{
		op1();
		dfs(remain-1,1);
		memcpy(a,oa,sizeof(oa));
	}
	op2();
	dfs(remain-1,2);
	memcpy(a,oa,sizeof(oa));
	return 0;
}

int main(void)
{
	scanf("%d %d %d",&n,&u,&r);
	for(int i = 1;i <= n;i++) scanf("%d",&a[i]);
	for(int i = 1;i <= n;i++) scanf("%d",&b[i]);
	for(int i = 1;i <= n;i++) scanf("%d",&k[i]);
	for(int i = 1;i <= n;i++) scanf("%d",&p[i]);
	
	dfs(u,-1);
	printf("%I64d\n",ans);
	while(getchar() != EOF);
	return 0;
}