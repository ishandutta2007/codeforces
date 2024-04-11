#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#define ll long long
using namespace std;
ll n,m,inv;
ll b,g,x[200005],y[200005];
vector<ll>s[200005];
void exgcd(ll x,ll y,ll&a,ll&b)
{
	if(x==0)
	{
		a=0;
		b=1;
		return;
	}
	exgcd(y%x,x,b,a);
	a-=b*(y/x);
}
int main()
{
	ll ans=0,inv=0;
	scanf("%lld%lld",&n,&m);
	scanf("%lld",&b);
	for(int i=1;i<=b;i++)scanf("%lld",&x[i]);
	scanf("%lld",&g);
	for(int i=1;i<=g;i++)scanf("%lld",&y[i]);
	sort(x+1,x+b+1);
	sort(y+1,y+g+1);
	ll nowv=n-1;
	ll nowi=b;
	while(x[nowi]==nowv)nowi--,nowv--;
	ans=max(ans,nowv);
	nowv=m-1;
	nowi=g;
	while(y[nowi]==nowv)nowi--,nowv--;
	ans=max(ans,nowv);
	ll d=__gcd(n,m);
	if(n<m)
	{
		swap(n,m);
		swap(b,g);
		for(int i=1;i<=max(b,g);i++)swap(x[i],y[i]);
	}
	for(int i=1;i<=g;i++)x[++b]=y[i];
	sort(x+1,x+b+1);
	for(int i=1;i<b;i++)
	  if(x[i]==x[i+1])x[i]=1000000001;
	sort(x+1,x+b+1);
	while(x[b]==1000000001)b--;
	if(d>b)
	{
		printf("-1\n");
		return 0;
	}
	for(int i=1;i<=b;i++)
	  s[x[i]%d].push_back(x[i]/d);
	exgcd(n/d,m/d,nowv,inv);
	inv%=n/d;
	if(inv<0)inv+=n/d;
	for(int i=0;i<d;i++)
	{
		if(s[i].empty())
		{
			printf("-1\n");
			return 0;
		}
		int top=0;
		int ss=(int)s[i].size();
		for(int j=0;j<ss;j++)
		  x[++top]=(s[i][j]-s[i][0]+n/d)*inv%(n/d);
		x[++top]=n/d;
		sort(x+1,x+top+1);
		for(int j=2;j<=top;j++)
		  if(x[j]!=x[j-1]+1)
		    ans=max(ans,((x[j]-1-x[j-1])*(m/d)+(s[i][0]+x[j-1]*(m/d))%(n/d))*d+i);
	}
	printf("%lld\n",ans);
	return 0;
}