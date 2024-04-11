#include<bits/stdc++.h>
using namespace std;
const int N=100005;
vector<int>e[N];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	for(int i=1;i<=n;i++)
	{
		if(e[i].size()==2)
		{
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	return 0;
}