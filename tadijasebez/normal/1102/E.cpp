#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
const int N=200050;
int a[N];
int main()
{
	int n,i;
	scanf("%i",&n);
	map<int,int> last;
	for(int i=1;i<=n;i++) scanf("%i",&a[i]),last[a[i]]=i;
	int j,ans=0;
	for(int i=1;i<=n;i=j+1)
	{
		int mx=last[a[i]];
		j=i;
		while(j<mx) j++,mx=max(mx,last[a[j]]);
		if(j<n) ans++;
	}
	int sol=1;
	while(ans--) sol=sol*2%mod;
	printf("%i\n",sol);
	return 0;
}