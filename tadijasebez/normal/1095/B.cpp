#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair

int main()
{
	int n,i;vector<int> a;
	scanf("%i",&n);a.resize(n);
	for(i=0;i<n;i++) scanf("%i",&a[i]);
	sort(a.begin(),a.end());
	printf("%i\n",min(a[n-1]-a[1],a[n-2]-a[0]));
	return 0;
}