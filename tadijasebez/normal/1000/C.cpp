#include <stdio.h>
#include <map>
using namespace std;
#define ll long long
const int N=200050;
map<ll,int> add;
ll sol[N];
int main()
{
	int n,i;
	ll l,r;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%lld %lld",&l,&r),add[l]++,add[r+1]--;
	ll last=-1,val=0;
	for(map<ll,int>::iterator it=add.begin();it!=add.end();it++)
	{
		ll cur=it->first;
		ll sz=cur-last;
		sol[val]+=sz;
		val+=it->second;
		last=cur;
	}
	for(i=1;i<=n;i++) printf("%lld ",sol[i]);
	return 0;
}