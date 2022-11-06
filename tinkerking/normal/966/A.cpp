#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int N,M,L,E,V;
set<int>e,l;

int main()
{
	//freopen("A.in","r",stdin);
	scanf("%d%d%d%d%d",&N,&M,&L,&E,&V);
	l.insert(-2e8);l.insert(2e8);
	e.insert(-2e8);e.insert(2e8);
	for (int i=1;i<=L;i++)
	{
		int tmp;
		scanf("%d",&tmp);
		l.insert(tmp);	
	}	
	for (int i=1;i<=E;i++)
	{
		int tmp;
		scanf("%d",&tmp);
		e.insert(tmp);
	}
	int Q;
	scanf("%d",&Q);
	while(Q--)
	{
		int x1,y1,x2,y2;
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		if (x1 == x2)
		{
			printf("%d\n",abs(y1 - y2));
			continue;
		}
		int ans1,ans2;
		if (y1 > y2) swap(y1,y2);
		int dy = y2 - y1;
		int dx = abs(x1 - x2);
		int dx2 = (dx + V - 1) / V;
		//L
		if (*l.lower_bound(y1) <= y2)
		{
			ans1 = dx + dy;
		}
		else
		{
			auto tmp = l.lower_bound(y1);
			tmp--;
			ans1 = 2 * (y1 - (*tmp)) + dx + dy;
			tmp = l.upper_bound(y2);
			ans1 = min(ans1,2 * ((*tmp) - y2) + dx + dy);
		}
		//E
		if (*e.lower_bound(y1) <= y2)
		{
			ans2 = dx2 + dy;
		}
		else
		{
			auto tmp = e.lower_bound(y1);
			tmp--;
			ans2 = 2 * (y1 - (*tmp)) + dx2 + dy;
			tmp = e.upper_bound(y2);
			ans2 = min(ans2,2 * ((*tmp) - y2) + dx2 + dy);
		}
		printf("%d\n",min(ans1,ans2));
	}
}