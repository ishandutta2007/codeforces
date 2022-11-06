#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

vector<int>a[100010],up[100010];
int N,M,res[100010];

int main()
{
	scanf("%d%d",&N,&M);
	for (int i=0;i<N;i++)
	{
		res[i] = 10000000;
		int tmp;
		for (int j=0;j<M;j++)
		{
			scanf("%d",&tmp);
			a[i].push_back(tmp);
			if (i==0)
				up[i].push_back(0);
			else
			{
				if (a[i][j]>=a[i-1][j])
					up[i].push_back(up[i-1][j]);
				else
					up[i].push_back(i);
			}
			res[i]=min(res[i],up[i][j]);
		}
	}
	int Q;
	scanf("%d",&Q);
	while(Q--)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		l--;r--;
		puts(l>=res[r]?"Yes":"No");
	}
}