#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define LL long long
#define PII pair<int, int>
#define PLL pair<LL, LL>
#define pb pop_back

int l, n, m;
vector<PII> V;
LL res;
priority_queue<PII> Q;

int main()
{
	//ios_base::sync_with_stdio(0);
	scanf("%d%d%d", &l, &m, &n);
	for(int i=0; i<n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		V.PB(MP(a, b));
	}
	sort(V.begin(), V.end());
	V.PB(MP(l, 0));
	int prev=0;
	for(int i=0; i<=n; i++)
	{
		if(V[i].F-prev>m)
		{
			printf("-1\n");
			return 0;
		}
		prev=V[i].F;
	}
	int pos=m, ind=0;
	while(pos!=l)
	{
		while(V[ind].F<=pos)
		{
			Q.push(MP(-V[ind].S, V[ind].F));
			ind++;
		}
		int x=V[ind].F-pos;
		while(x!=0)
		{
			PII y=MP(-Q.top().F, Q.top().S);
			y.S+=m;
			if(y.S<=pos)
			{
				Q.pop();
				continue;
			}
			int added=min(x, y.S-pos);
			res+=(LL)added*y.F;
			pos+=added;
			if(pos==y.S)
				Q.pop();
			x=V[ind].F-pos;
		}
	}
	printf("%lld\n", res);
	return 0;
}