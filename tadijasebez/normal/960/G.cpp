#include <stdio.h>
#include <vector>
using namespace std;
#define ll long long
#define pb push_back
const int mod=998244353;
int pow(int x, int k){ int ret=1;for(;k;k>>=1,x=(ll)x*x%mod) if(k&1) ret=(ll)ret*x%mod;return ret;}
void fft(vector<int> &a, bool inv)
{
	vector<int> v;v.resize(a.size());
	int i,j,k;
	for(i=1;i<=a.size();i<<=1)
	{
		int ang=pow(3,(mod-1)/i);
		if(inv) ang=pow(ang,mod-2);
		int block=a.size()/i;
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
vector<int> StirlingNumbers(int l, int r)
{
	if(l==r)
	{
		vector<int> ret;
		ret.pb(l);ret.pb(1);
		return ret;
	}
	int mid=l+r>>1;
	return StirlingNumbers(l,mid)*StirlingNumbers(mid+1,r);
}
const int N=200050;
int F[N],I[N];
void Calc()
{
	int i;
	F[0]=1;for(i=1;i<N;i++) F[i]=(ll)F[i-1]*i%mod;
	I[N-1]=pow(F[N-1],mod-2);for(i=N-2;i>=0;i--) I[i]=(ll)I[i+1]*(i+1)%mod;
}
int GetB(int n, int k){ return (ll)F[n]*I[k]%mod*I[n-k]%mod;}
int GetS(int k, int n)
{
	if(k>n) return 0;
	vector<int> ret=StirlingNumbers(0,n-1);
	return ret[k];
}
int main()
{
	Calc();
	int n,a,b,i;
	scanf("%i %i %i",&n,&a,&b);
	if(!a || !b) return printf("0\n"),0;
	if(n==1) return printf("%i\n",(a+b==2)),0;
	printf("%i\n",(ll)GetS(a+b-2,n-1)*GetB(a+b-2,a-1)%mod);
	return 0;
}