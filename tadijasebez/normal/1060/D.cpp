#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=100050;
int l[N],r[N];
int main()
{
	int n,i;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i %i",&l[i],&r[i]);
	sort(l+1,l+1+n);sort(r+1,r+1+n);
	ll sol=n;
	for(i=1;i<=n;i++) sol+=max(l[i],r[i]);
	printf("%lld\n",sol);
	return 0;
}