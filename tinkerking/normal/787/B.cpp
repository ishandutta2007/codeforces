#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int N,M;
bool vis[2][10010];
int v[100010];

int main()
{
	bool cancel = false;
	scanf("%d%d",&N,&M);
	memset(vis,false,sizeof(vis));
	while(M--)
	{
		int K;
		scanf("%d",&K);
		bool ok = false;
		for (int i=1;i<=K;i++)
		{
			scanf("%d",&v[i]);
			if (v[i]<0)
			{
				v[i] = -v[i];
				vis[0][v[i]] = true;
			}
			else
				vis[1][v[i]] = true;
			
			if (vis[0][v[i]] && vis[1][v[i]]) ok = true;
		}
		for (int i=1;i<=K;i++)
			vis[0][v[i]] = vis[1][v[i]] = false;
		if (!ok) cancel = true;
	}
	puts(cancel?"YES":"NO");
}