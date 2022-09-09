#include <stdio.h>
#include <vector>
using namespace std;
#define ll long long
#define pb push_back
const int N=1000050;
const int mod=998244353;
int pow(int x, int k)
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
		int ang=pow(3,(mod-1)/i);
		if(inv) ang=pow(ang,mod-2);
		for(j=0;j<block;j++)
		{
			for(k=0;k<i;k++) v[k]=a[j+k*block];
			int cur=1;
			for(k=0;k<i/2;k++)
			{
				int tmp1=v[k*2],tmp2=(ll)cur*v[k*2+1]%mod;
				a[j+k*block]=(tmp1+tmp2)%mod;
				a[j+k*block+a.size()/2]=(tmp1-tmp2+mod)%mod;
				cur=(ll)cur*ang%mod;
			}
		}
	}
	if(inv)
	{
		int mul=pow(a.size(),mod-2);
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
vector<int> pow(vector<int> x, int k)
{
	vector<int> ret;ret.pb(1);
	int i;
	for(;k;k>>=1,x=x*x)
	{
		for(i=0;i<x.size();i++) if(x[i]>1) x[i]=1;
		for(i=0;i<ret.size();i++) if(ret[i]>1) ret[i]=1;
		if(k&1) ret=ret*x;
	}
	return ret;
}
int main()
{
	vector<int> x;
	int n,i,y,k;
	scanf("%i %i",&n,&k);
	x.resize(1001);
	while(n--) scanf("%i",&y),x[y]=1;
	//for(i=0;i<10;i++) printf("%i ",x[i]);printf("\n");
	vector<int> sol=pow(x,k);
	for(i=1;i<sol.size();i++) if(sol[i]>0) printf("%i ",i);
	//printf("FFT:%i\n",sol.size());
	//for(i=0;i<10;i++) printf("%i ",sol[i]);printf("\n");
	return 0;
}