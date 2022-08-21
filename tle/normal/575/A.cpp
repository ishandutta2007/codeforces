//zzq
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
#include <vector>
#include <limits>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
ll k,p,s[233333];
int q,n;
struct mat
{
	int n,m;
	ll a[2][2];
};
#define IL inline
IL mat operator * (mat a,mat b)
{
	mat ans; ans.n=a.n; ans.m=b.m;
	for(int i=0;i<a.n;i++)
	{
		for(int j=0;j<b.m;j++)
		{
			ll cur=0;
			for(int k=0;k<a.m;k++) cur+=a.a[i][k]*b.a[k][j]%p, cur%=p;
			ans.a[i][j]=cur;
		}
	}
	return ans;
}
IL mat dw(int n)
{
	mat ans; ans.n=ans.m=n;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++) ans.a[i][j]=i==j;
	}
	return ans;
}
IL mat qp(mat a,ll b)
{
	mat ans=dw(a.n);
	while(b)
	{
		if(b&1) ans=ans*a;
		a=a*a; b>>=1;
	}
	return ans;
}
IL mat zyg(ll a,ll b)
{
	mat zy; zy.n=zy.m=2;
	zy.a[0][0]=0; zy.a[0][1]=a%p;
	zy.a[1][0]=1; zy.a[1][1]=b%p;
	return zy;
}
IL mat gcs(ll a,ll b)
{
	mat cs; cs.n=1; cs.m=2;
	cs.a[0][0]=a; cs.a[0][1]=b;
	return cs;
}
IL void prt(ll x)
{
	printf("%d\n",int((x%p+p)%p));
}
struct pll {ll X,Y;};
bool operator < (pll a,pll b) {return a.X<b.X;}
pll ps[233333];
ll F[233333];
IL void force()
{
	F[0]=0; F[1]=1;
	for(int i=2;i<=n;i++)
	{
		F[i]=s[(i-1)%n]*F[i-1]%p+s[(i-2)%n]*F[i-2]%p;
		F[i]%=p;
	}
}
int M=65536;
mat seg[233333];
IL mat xzy(int i) {return zyg(s[(i-2+n)%n],s[(i-1+n)%n]);}
IL void ycl()
{
	for(int i=1;i<=n;i++) seg[M+i]=xzy(i-1);
	for(int i=n+1;i<=M;i++) seg[M+i]=dw(2);
	for(int i=M-1;i>=1;i--) seg[i]=seg[i+i]*seg[i+i+1];
}
int ln=0,ls[233333],rn=0,rs[233333];
mat zd,hz[66666],qz[66666];
IL mat query(int l,int r)
{
	++l; ++r;
	for(l+=M-1,r+=M+1;l^r^1;l>>=1,r>>=1)
	{
		if(~l&1) ls[++ln]=l^1;
		if(r&1) rs[++rn]=r^1;
	}
	mat cur=dw(2);
	for(int i=1;i<=ln;i++) cur=cur*seg[ls[i]]; ln=0;
	while(rn) cur=cur*seg[rs[rn--]];
	return cur;
}
IL mat gzy(ll l,ll r)
{
	if(l>r) return dw(2);
	if(l/n==r/n) return query(l%n,r%n);
	mat ans=hz[l%n];
	ans=ans*qp(zd,r/n-l/n-1);
	ans=ans*qz[r%n];
	return ans;
}
#define gc (getchar())
IL long long r_i()
{
	long long tmp=0; bool fu=0; char s;
	while(s=gc,s!='-'&&(s<'0'||s>'9')) ;
	if(s=='-') fu=1; else tmp=s-'0';
	while(s=gc,s>='0'&&s<='9') tmp=tmp*10+s-'0';
	if(fu) return -tmp; else return tmp;
}
#define ri r_i()
int main()
{
	//freopen("fibonotci.in","r",stdin);
	//freopen("fibonotci.out","w",stdout);
	k=ri, p=ri, n=ri;
	for(int i=0;i<n;i++) s[i]=ri;
	q=ri;
	if(k<=1) {prt(k); return 0;}
	if(k<=n) {force(); prt(F[k]); return 0;}
	ycl(); zd=query(0,n-1);
	for(int i=1;i<=q;i++) ps[i].X=ri, ps[i].Y=ri;
	sort(ps+1,ps+1+q); mat cc=gcs(0,1);
	for(int i=0;i<n;i++) hz[i]=query(i,n-1);
	for(int i=0;i<n;i++) qz[i]=query(0,i);
	bool havk=0;
	for(int i=1;i<=q;i++)
	{
		if(ps[q].X+2==k) havk=1;
		if(ps[i].X+1>k) {q=i-1; break;}
	}
	if(!havk)
	{
		++q; ps[q].X=k-2; ps[q].Y=s[(k-2)%n];
		if(q>1&&ps[q-1].X==k-1) swap(ps[q],ps[q-1]);
	}
	ll cu=1;
	for(int i=1;i<=q;i++)
	{
		int t;
		for(int j=i;j<=q;j++)
		{
			if(ps[j].X-ps[i].X!=j-i) break;
			t=j;
		}
		//zy(cu+1)~zy(ps[i].X)
		cc=cc*gzy(cu+1,ps[i].X);
		//zy(ps[i].X+1)~zy(ps[t].X+2)
		for(ll p=ps[i].X+1,cur=i;p<=ps[t].X+2;p++,cur++)
		{
			ll a=(cur==i)?s[(p-2)%n]:ps[cur-1].Y,b=(cur<=t)?ps[cur].Y:s[(p-1)%n];
			cc=cc*zyg(a,b);
		}
		cu=ps[t].X+2; i=t;
	}
	if(cu==k+1) prt(cc.a[0][0]);
	else prt(cc.a[0][1]);
}