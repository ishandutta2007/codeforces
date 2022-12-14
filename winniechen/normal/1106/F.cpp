#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <bitset>
#include <map>
using namespace std;
#define N 205
#define ll long long
#define mod 998244353
#define mmod 998244352
int a[N],b[N],mo[N],tmp[N],n,k,m,ans;
int q_pow(int x,int n){int ret=1;for(;n;n>>=1,x=(ll)x*x%mod)if(n&1)ret=(ll)ret*x%mod;return ret;}
void mul(int *a,int *b,int *ret)
{
	memset(tmp,0,sizeof(tmp));
	for(int i=0;i<k;i++)
		for(int j=0;j<k;j++)
			tmp[i+j]=(tmp[i+j]+(ll)a[i]*b[j])%mmod;
	for(int i=(k<<1)-2;i>=k;i--)if(tmp[i])for(int j=1;j<=k;j++)
			tmp[i-j]=(tmp[i-j]-(ll)tmp[i]*mo[k-j])%mmod;
	for(int i=0;i<k;i++)ret[i]=tmp[i];
}
map<int ,int >mp;
int ex_gcd(int a,int b,int &x,int &y)
{
	if(!b)return x=1,y=0,a;int ret=ex_gcd(b,a%b,y,x);
	y=y-a/b*x;return ret;
}
int BSGS(int x)
{
	int s=5000,t=1;
	for(int i=0;i<s;i++)mp[int((ll)t*x%mod)]=i,t=t*3ll%mod;
	for(int i=1,now=1;;i++)
	{
		now=(ll)now*t%mod;
		if(mp.find(now)!=mp.end())return i*s-mp[now];
	}
}
int main()
{
	scanf("%d",&k);
	for(int i=1;i<=k;i++)scanf("%d",&mo[k-i]),mo[k-i]=mmod-mo[k-i];
	scanf("%d%d",&n,&m);b[1]=1;a[0]=1;
	if(k==1)b[0]=mmod-mo[0],b[1]=0;
	for(n--;n;n>>=1){if(n&1)mul(a,b,a);mul(b,b,b);}
	int t=(a[k-1]+mmod)%mmod,x=0,y=0;
	int tt=ex_gcd(t,mmod,x,y),kk=BSGS(m);
	if(kk%tt)return puts("-1"),0;
	x=((ll)x*(kk/tt)%mmod+mmod)%mmod;
	printf("%d\n",q_pow(3,x));
}