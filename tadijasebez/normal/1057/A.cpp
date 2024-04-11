#include <bits/stdc++.h>
using namespace std;
const int N=200050;
int p[N],ans[N],sz;
int main()
{
	int n,i;
	scanf("%i",&n);
	for(i=2;i<=n;i++) scanf("%i",&p[i]);
	for(i=n;i;i=p[i]) ans[++sz]=i;
	reverse(ans+1,ans+1+sz);
	for(i=1;i<=sz;i++) printf("%i ",ans[i]);
	return 0;
}