#include <stdio.h>
#include <map>
using namespace std;
#define ll long long
map<int,ll> now,last,sol;
map<int,ll>::iterator it;
int gcd(int x, int y)
{
	if(y==0) return x;
	return gcd(y,x%y);
}
int main()
{
	int n,q,x,i;
	scanf("%i",&n);
	while(n--){
		scanf("%i",&x),now.clear(),now[x]++,sol[x]++;
		for(it=last.begin();it!=last.end();it++)
		{
			int k=gcd(x,it->first);
			now[k]+=it->second;
			sol[k]+=it->second;
		}
		now.swap(last);
	}
	scanf("%i",&q);
	while(q--) scanf("%i",&x),printf("%lld\n",sol[x]);
	return 0;
}