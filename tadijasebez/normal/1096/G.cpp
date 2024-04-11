#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod=998244353;
int powmod(int x, int k){ int ans=1;for(;k;k>>=1,x=(ll)x*x%mod) if(k&1) ans=(ll)ans*x%mod;return ans;}
namespace NTT
{
	void fft(vector<int> &a, bool inv)
	{
		vector<int> v(a.size());
		for(int i=2;i<=a.size();i<<=1)
		{
			int block=a.size()/i;
			int ang=powmod(3,(mod-1)/i);
			if(inv) ang=powmod(ang,mod-2);
			for(int j=0;j<block;j++)
			{
				for(int k=0;k<i;k++) v[k]=a[k*block+j];
				int cur=1;
				for(int k=0;k<i/2;k++)
				{
					int tmp1=v[k<<1],tmp2=(ll)v[k<<1|1]*cur%mod;
					a[k*block+j]=(tmp1+tmp2)%mod;
					a[k*block+j+a.size()/2]=(tmp1-tmp2+mod)%mod;
					cur=(ll)cur*ang%mod;
				}
			}
		}
		if(inv)
		{
			int mul=powmod(a.size(),mod-2);
			for(int i=0;i<a.size();i++) a[i]=(ll)a[i]*mul%mod;
		}
	}
	vector<int> mul(vector<int> a, vector<int> b)
	{
		int sz=1;
		while(sz<a.size() || sz<b.size()) sz<<=1;
		sz<<=1;
		a.resize(sz);
		b.resize(sz);
		fft(a,0);
		fft(b,0);
		for(int i=0;i<sz;i++) a[i]=(ll)a[i]*b[i]%mod;
		fft(a,1);
		return a;
	}
}
int main()
{
	int n,i,k,p;
	scanf("%i %i",&n,&k);
	vector<int> x(10,0),ans(1,1);
	while(k--) scanf("%i",&p),x[p]=1;
	n/=2;
	int sz=1;
	while(sz<16*n) sz<<=1;
	x.resize(sz);
	NTT::fft(x,0);
	for(i=0;i<x.size();i++) x[i]=powmod(x[i],n);
	NTT::fft(x,1);
	ans=x;
	int sol=0;
	for(i=0;i<ans.size();i++) sol+=(ll)ans[i]*ans[i]%mod,sol%=mod;
	printf("%i\n",sol);
	return 0;
}