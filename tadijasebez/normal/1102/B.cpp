#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,k,i;
	scanf("%i %i",&n,&k);
	vector<int> a(n),c(n);
	vector<pair<int,int>> work;
	map<int,int> cnt;
	for(int i=0;i<n;i++)
	{
		scanf("%i",&a[i]);
		cnt[a[i]]++;
		if(cnt[a[i]]>k) return 0*printf("NO\n");
		work.push_back(make_pair(a[i],i));
	}
	sort(work.begin(),work.end());
	for(int i=0;i<work.size();i++)
	{
		c[work[i].second]=i%k+1;
	}
	printf("YES\n");
	for(int i=0;i<n;i++) printf("%i ",c[i]);
	return 0;
}