#include <stdio.h>
#include <vector>
using namespace std;
vector<int> roots;
int color[100050];
int u[100050],v[100050];
int cnt[100050];
int main()
{
	int n,i,j;
	scanf("%i",&n);
	for(i=0;i<n-1;i++) scanf("%i%i",&u[i],&v[i]);
	for(i=1;i<=n;i++) scanf("%i",&color[i]);
	for(i=0;i<n-1;i++)
	{
		if(color[u[i]]!=color[v[i]])
		{
			roots.push_back(u[i]);
			roots.push_back(v[i]);
			cnt[u[i]]++;
			cnt[v[i]]++;
		}
	}
	for(i=0;i<roots.size();i++)
	{
		if(cnt[roots[i]]==roots.size()/2)
		{
			printf("YES\n%i\n",roots[i]);
			return 0;
		}
	}
	if(roots.empty()) printf("YES\n1\n");
	else printf("NO\n");
	return 0;
}