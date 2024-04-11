#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,i;
	scanf("%i",&n);
	vector<int> a;
	a.resize(n*2);
	for(i=0;i<n*2;i++) scanf("%i",&a[i]);
	sort(a.begin(),a.end());
	if(a[n-1]==a[n]) printf("NO\n");
	else printf("YES\n");
	return 0;
}