#include <stdio.h>
#include <vector>
#include <cstring>
#include <cmath>
using namespace std;
#define pb push_back
#define ll long long
const int N=500050;
const int mod=998244353;
int powmod(int x, int k)
{
	int ret=1;
	for(;k;k>>=1,x=(ll)x*x%mod) if(k&1) ret=(ll)ret*x%mod;
	return ret;
}
vector<int> v;
void fft(vector<int> &a, bool inv)
{
	v.clear();v.resize(a.size());
	int i,j,k;
	for(i=2;i<=a.size();i<<=1)
	{
		int block=a.size()/i;
		int ang=powmod(3,(mod-1)/i);
		if(inv) ang=powmod(ang,mod-2);
		for(j=0;j<block;j++)
		{
			for(k=0;k<i;k++)
			{
				v[k]=a[j+k*block];
			}
			int cur=1;
			for(k=0;k<i/2;k++)
			{
				int tmp1=v[k*2],tmp2=(ll)cur*v[k*2+1]%mod;
				a[j+k*block]=(tmp1+tmp2)%mod;
				int id=j+k*block+a.size()/2;
				a[id]=tmp1-tmp2;
				if(a[id]<0) a[id]+=mod;
				cur=(ll)cur*ang%mod;
			}
		}
	}
	if(inv)
	{
		int mul=powmod(a.size(),mod-2);
		for(i=0;i<a.size();i++) a[i]=(ll)a[i]*mul%mod;
	}
}
vector<int> operator * (vector<int> a, vector<int> b)
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
char s[N];
vector<int> a,b,c,sol;
bool bad[N];
void Solve()
{
	int n,i,j;
	scanf("%i",&n);
	scanf("%s",s+1);
	a.clear();b.clear();
	a.resize(n);
	b.resize(n);
	for(i=1;i<=n;i++)
	{
		if(s[i]=='V') a[i-1]=1;
		if(s[i]=='K') b[n-i]=1;
	}
	for(i=0;i<=n;i++) bad[i]=0;
	c=a*b;
	//for(i=0;i<n;i++) printf("%i ",a[i]);printf("\n");
	//for(i=0;i<n;i++) printf("%i ",b[i]);printf("\n");
	//printf("FFT:\n");
	//for(i=0;i<2*n;i++) printf("%i ",c[i]);
	for(i=0;i<2*n;i++)
	{
		if(c[i]>0) bad[abs(n-i-1)]=1;
	}
	sol.clear();
	for(i=1;i<=n;i++)
	{
		bool was=0;
		for(j=i;j<=n;j+=i) was|=bad[j];
		if(!was) sol.pb(i);
	}
	printf("%i\n",sol.size());
	for(i=0;i<sol.size();i++) printf("%i ",sol[i]);
	printf("\n");
}
int main()
{
	int t;scanf("%i",&t);
	while(t--) Solve();
	return 0;
}