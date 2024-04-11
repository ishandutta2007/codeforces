#include<stdio.h>
#include<map>
using namespace std;
#define fe(i,n) for(__typeof(n.begin()) i=n.begin();i!=n.end();i++)
typedef long long ll;
ll f[100020]={1},z,d=1;
int x,n,m,t,p=1000000007;
map<int,int>c;
int F(int x)
{
	for(;x;x/=10)
		if(x%10!=4&&x%10!=7)
			return 0;
	return 1;
}
ll pw(ll x,ll y)
{
	ll _=1;
	for(;y;y>>=1)
	{
		if(y&1)
			_=_*x%p;
		x=x*x%p;
	}
	return _;
}
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
		scanf("%d",&x),F(x)?c[x]++:t++;
	fe(i,c)
		for(int j=min(m,(int)c.size());j;j--)
			f[j]=(f[j]+f[j-1]*i->second)%p;
	for(int i=0;i<=m;i++)
		z=(z+d*f[m-i])%p,d=d*(t-i)%p*pw(i+1,p-2)%p;
	printf("%I64d\n",z);
	return 0;
}