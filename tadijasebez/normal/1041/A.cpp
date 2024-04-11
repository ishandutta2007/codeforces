#include <bits/stdc++.h>
using namespace std;
const int N=100050;
int a[N];
int main()
{
	int n,i,mx=-1e9+7,mn=1e9+7;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i",&a[i]),mx=max(mx,a[i]),mn=min(mn,a[i]);
	printf("%i\n",mx-mn+1-n);
	return 0;
}