#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#include<ext/pb_ds/hash_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
const int N=200005,mod=1e9+7,iv2=(mod+1)/2,iv6=(mod+1)/6;
int rd()
{
	char c=getchar();int x=0;
	while(!(c>='0'&&c<='9'))
		c=getchar();
	while(c>='0'&&c<='9')
	{
		x=x*10+(c-'0');
		c=getchar();
	}
	return x;
}
int n,m,a[N],s[N],B,l=1,r,s0,s1,s2;
struct nd
{
	int b,l,r,k,d;
	bool operator<(const nd t)const
	{
		return (b<t.b)||(b==t.b&&((b&1)?(r<t.r):(r>t.r)));
	}
}q[N];
gp_hash_table<int,int>p;
int qp(int a,int b)
{
	int ans=1;
	while(b)
	{
		if(b&1)
			ans=1ll*ans*a%mod;
		a=1ll*a*a%mod;
		b>>=1;
	}
	return ans;
}
void add(int v)
{
	if(!p[v]++)
	{
		s0++;
		s1=(s1+v)%mod;
		s2=(s2+1ll*v*v%mod)%mod;
	}
}
void era(int v)
{
	if(!--p[v])
	{
		s0--;
		s1=(s1+mod-v)%mod;
		s2=(s2+mod-1ll*v*v%mod)%mod;
	}
}
long long zz(long long v){return v*(v+1)%mod*((v*2)+1)%mod*iv6%mod;}
int main()
{
	n=rd(),m=rd(),B=n/sqrt(m)+1;
	for(int i=1;i<=n;i++)
		a[i]=rd();
	for(int i=1;i<=m;i++)
	{
		q[i].l=rd(),q[i].r=rd(),q[i].k=rd();
		q[i].b=q[i].l/B,q[i].d=i;
	}
	sort(q+1,q+m+1);
	for(int i=1;i<=m;i++)
	{
		while(r<q[i].r)
			add(a[++r]);
		while(l>q[i].l)
			add(a[--l]);
		while(r>q[i].r)
			era(a[r--]);
		while(l<q[i].l)
			era(a[l++]);
		if(s0==1)
		{
			s[q[i].d]=1;
			continue;
		}
		int d=q[i].k,g=1ll*(s0-1)*iv2%mod,f=1ll*s1*qp(s0,mod-2)%mod,h=(f+mod-1ll*g*d%mod)%mod;
		int v=(1ll*h*h%mod*s0%mod+1ll*h*d%mod*s0%mod*(s0-1)%mod+zz(s0-1)*d%mod*d%mod)%mod;
		s[q[i].d]=(v==s2);
	}
	for(int i=1;i<=m;i++)
		puts(s[i]?"Yes":"No");
	return 0;
}