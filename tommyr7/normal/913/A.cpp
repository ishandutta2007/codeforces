#include <bits/stdc++.h>
using namespace std;
int n,m;
long long now=1;
int main()
{
	scanf("%d%d",&n,&m);
	if (n>30) printf("%d\n",m);
	else
	{
		while (n--) now=2LL*now;
		printf("%lld\n",m%now);
	}
	return 0;
}