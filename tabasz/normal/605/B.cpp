#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<cmath>
#include<iostream>
#include<string>
using namespace std;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define LL long long
#define PII pair<int, int>
#define PLL pair<LL, LL>
#define pb pop_back

struct edge
{
	int w, ind;
	bool b;
};

int n, m, tmp, tmp2=1;
PII T[100005];
vector<edge> V;
vector<PII> X;

bool cmp(edge x, edge y)
{
	if(x.w==y.w)
	{
		if(!x.b && y.b)
			return false;
		if(x.b && !y.b)
			return true;
		return x.ind<y.ind;
	}
	return x.w<y.w;
}

int main()
{
	//ios_base::sync_with_stdio(0);
	scanf("%d%d", &n, &m);
	tmp=m;
	for(int i=0; i<m; i++)
	{
		edge x;
		scanf("%d%d", &x.w, &x.b);
		x.ind=i;
		V.PB(x);
	}
	sort(V.begin(), V.end(), cmp);
	for(int i=0; i<(int)V.size(); i++)
	{
		if(V[i].b)
		{
			tmp2++;
			T[V[i].ind]=MP(1, tmp2);
			tmp--;
			for(int j=2; j<tmp2; j++)
			{
				if(tmp<=0)
					break;
				tmp--;
				X.PB(MP(j, tmp2));
			}
		}
		else
		{
			if(X.empty())
			{
				printf("-1\n");
				return 0;
			}
			T[V[i].ind]=X[X.size()-1];
			X.pb();
		}
	}
	for(int i=0; i<m; i++)
		printf("%d %d\n", T[i].F, T[i].S);
	return 0;
}