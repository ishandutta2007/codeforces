#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,ans=0;
	scanf("%i",&n);
	vector<int> a(n);
	for(int &i:a) scanf("%i",&i);
	sort(a.begin(),a.end());
	for(int i=1,j=0;j<n;i++,j++)
	{
		for(;j<n && a[j]<i;j++);
		if(j<n) ans++;
	}
	printf("%i\n",ans);
	return 0;
}