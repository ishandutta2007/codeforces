#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
const int N=1050;
int a[N];
int main()
{
	int n,i,j;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i",&a[i]);
	for(i=n;i>=1;i--) a[i]-=a[i-1];
	vector<int> ans;
	for(j=1;j<=n;j++)
	{
		bool ok=1;
		for(i=j+1;i<=n;i++) if(a[i]!=a[i-j]) ok=0;
		if(ok) ans.pb(j);
	}
	printf("%i\n",ans.size());
	for(i:ans) printf("%i ",i);
	printf("\n");
	return 0;
}