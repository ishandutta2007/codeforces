#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
const int N=200050;
int a[N],b[N];
bool Has(int x, int y){ return a[x]==y || b[x]==y;}
int main()
{
	int n,i;
	vector<int> ans;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i %i",&a[i],&b[i]);
	ans.pb(1);
	if(Has(a[1],b[1])) ans.pb(a[1]);
	else ans.pb(b[1]);
	while(ans.size()<n)
	{
		int sz=ans.size();
		int f=ans[sz-2];
		int s=ans[sz-1];
		if(Has(f,a[s])) ans.pb(a[s]);
		else ans.pb(b[s]);
	}
	for(int f:ans) printf("%i ",f);
	return 0;
}