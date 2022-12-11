#include "bits/stdc++.h"
using namespace std;

char dat[200005];
bool visit[200005];
bool fall[200005];
int n;

void dfs(int t)
{
	visit[t] = true;
	fall[t] = false;
	int nxt = t + (dat[t] == '<' ? -1 : 1);

	if (nxt < 0 || nxt >= n)
	{
		fall[t] = true;
	}
	else
	{
		if (!visit[nxt]) dfs(nxt);
		fall[t] = fall[nxt];
	}
}

int main()
{
	scanf("%d%s", &n, dat);

	for (int i = 0; i < n; i++)
	{
		if (visit[i]) continue;
		dfs(i);
	}

	printf("%d", accumulate(fall, fall + n, 0));
}