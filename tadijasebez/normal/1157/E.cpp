#include <bits/stdc++.h>
using namespace std;
const int N=200050;
multiset<int> all;
int Get(int x){ auto it=all.lower_bound(x);if(it==all.end()) it=all.begin();return *it;}
int a[N];
int main()
{
	int n,i,x,y;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i",&a[i]);
	for(i=1;i<=n;i++) scanf("%i",&x),all.insert(x);
	for(i=1;i<=n;i++)
	{
        x=Get(n-a[i]);
        all.erase(all.find(x));
        printf("%i ",(a[i]+x)%n);
	}
	return 0;
}