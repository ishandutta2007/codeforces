#include <stdio.h>
#define ll long long
const int N=100050;
const int M=43*N;
const int L=42;
ll j=1;
int x[M],ls[M],rs[M],clock,root;
void Set(int &c, int lvl, ll X, int val)
{
	if(!c) c=++clock;
	x[c]+=val;
	if(lvl==-1) return;
	if((X>>lvl)&1) Set(rs[c],lvl-1,X,val);
	else Set(ls[c],lvl-1,X,val);
}
ll A;
void Get(int &c, int lvl, ll X)
{
	if(lvl==-1) return;
	if((X>>lvl)&1)
	{
		if(x[ls[c]])
		{
			A+=j<<lvl;
			Get(ls[c],lvl-1,X);
		}
		else Get(rs[c],lvl-1,X);
	}
	else
	{
		if(x[rs[c]])
		{
			A+=j<<lvl;
			Get(rs[c],lvl-1,X);
		}
		else Get(ls[c],lvl-1,X);
	}
}
ll Get(int lvl ,ll X){ A=0;Get(root,lvl,X);return A;}
ll dp[N],a[N],sol;
ll max(ll a, ll b){ return a>b?a:b;}
int main()
{
	int i,n;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%lld",&a[i]);
	ll Xor=0,tmp;
	Set(root,L,0,1);
	for(i=n;i;i--) dp[i]=dp[i+1]^a[i],Set(root,L,dp[i],1);
	sol=Get(L,0);
	for(i=1;i<=n;i++)
	{
		Xor^=a[i];
		Set(root,L,dp[i],-1);
		tmp=Get(L,Xor);
		sol=max(sol,tmp);
	}
	sol=max(sol,Xor);
	printf("%lld\n",sol);
	return 0;
}