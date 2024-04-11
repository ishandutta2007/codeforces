#include<bits/stdc++.h>
#define maxn 100005
#define ll long long
using namespace std;
int n,m;
char a[maxn],b[maxn];
const ll bas1=37,bas2=131;
const ll mod1=998244353,mod2=1000000009;
ll h1[maxn],xp1[maxn],h2[maxn],xp2[maxn];
ll H1,H2;
void pre()
{
	xp1[0]=1;xp2[0]=1;
	for(int i=1;i<=n;++i)xp1[i]=xp1[i-1]*bas1%mod1;
	for(int i=1;i<=n;++i)xp2[i]=xp2[i-1]*bas2%mod2;
	for(int i=1;i<=n;++i)h1[i]=(h1[i-1]*bas1%mod1+a[i]-'0')%mod1;
	for(int i=1;i<=n;++i)h2[i]=(h2[i-1]*bas2%mod2+a[i]-'0')%mod2;
	for(int i=1;i<=m;++i)H1=(H1*bas1%mod1+b[i]-'0')%mod1;
	for(int i=1;i<=m;++i)H2=(H2*bas2%mod2+b[i]-'0')%mod2;
}
ll gethash1(int l,int r)
{
	return (h1[r]-h1[l-1]*xp1[r-l+1]%mod1+mod1)%mod1;
}
ll gethash2(int l,int r)
{
	return (h2[r]-h2[l-1]*xp2[r-l+1]%mod2+mod2)%mod2;
}
bool issame(int l,int r)
{
	return (gethash1(l,r)==H1)&&(gethash2(l,r)==H2);
}
const ll mod = 1000000007;
ll dp[maxn],s1[maxn],s2[maxn];
int main()
{
	scanf("%s%s",a+1,b+1);
	n=strlen(a+1),m=strlen(b+1);
	pre();
	for(int l=1,r=m;r<=n;++l,++r)
	{
		if(!issame(l,r))dp[r]=dp[r-1];
		else dp[r]=(l+s2[l-1])%mod;
		s1[r]=s1[r-1]+dp[r];s1[r]%=mod;
		s2[r]=s2[r-1]+s1[r];s2[r]%=mod;
	}
	printf("%I64d\n",s1[n]);
	return 0;
}