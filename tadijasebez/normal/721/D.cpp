#include <stdio.h>
#include <set>
#include <cmath>
using namespace std;
#define ll long long
struct Number
{
	ll a;
	int i;
	Number(){}
	Number(ll b, int c){ a=b,i=c;}
	inline bool operator < (const Number &b) const
	{
		if(fabs(a)==fabs(b.a)) return i<b.i;
		return fabs(a)<fabs(b.a);
	}
};
set<Number> Set;
set<Number>::iterator it;
int br,x;
void Add()
{
	if(br%2==0)
	{
		it=Set.begin();
		Number tmp=*it;
		if(tmp.a<0)
		{
			tmp.a+=x;
			if(tmp.a>=0) br^=1;
		}
		else
		{
			tmp.a-=x;
			if(tmp.a<0) br^=1;
		}
		Set.erase(*it);
		Set.insert(tmp);
	}
	else
	{
		it=Set.begin();
		Number tmp=*it;
		if(tmp.a<0)
		{
			tmp.a-=x;
		}
		else
		{
			tmp.a+=x;
		}
		Set.erase(*it);
		Set.insert(tmp);
	}
}
const int N=200050;
ll sol[N],a[N];
int main()
{
	int n,k,i;
	scanf("%i %i %i",&n,&k,&x);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]),Set.insert(Number(a[i],i));
		if(a[i]<0) br^=1;
	}
	while(k--) Add();
	for(it=Set.begin();it!=Set.end();it++) sol[it->i]=it->a;
	for(i=1;i<=n;i++) printf("%lld ",sol[i]);
	printf("\n");
	return 0;
}