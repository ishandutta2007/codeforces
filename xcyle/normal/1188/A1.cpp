#include <iostream>
#include <cstdio>
#include <vector>
#define maxn 100005
using namespace std;
int n, a, b;
vector<int> G[maxn];
int main()
{
	scanf("%d", &n);
	for (int i = 1; i < n; i++)
	{
		scanf("%d%d", &a, &b);
		G[a].push_back(b);
		G[b].push_back(a);
	}
	for (int i = 1; i <= n; i++)
	{
		if(G[i].size() == 2) 
		{
			printf("NO");
			return 0;
		}
	}
	printf("YES");
	return 0;
}