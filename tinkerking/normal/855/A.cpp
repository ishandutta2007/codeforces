#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

unordered_map<string,int>vis;

int main()
{
	int N;
	string s;
	scanf("%d",&N);
	for (int i=1;i<=N;i++)
	{
		cin >> s;
		if (vis[s]) puts("YES");
		else puts("NO");
		vis[s] = 1;
	}
}