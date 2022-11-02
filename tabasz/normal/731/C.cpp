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

int T[200005], X[200005], n, m, k, res;
vector<int> V[200005];
bool B[200005];

int find(int a)
{
	if(T[a]==a)
		return a;
	return T[a]=find(T[a]);
}

void onion(int a, int b)
{
	T[find(a)]=find(b);
}

int main()
{
	//ios_base::sync_with_stdio(0);
	scanf("%d%d%d", &n, &m, &k);
	for(int i=1; i<=n; i++)
	{
		scanf("%d", X+i);
		T[i]=i;
	}
	for(int i=0; i<m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		if(find(a)!=find(b))
			onion(a, b);
	}
	for(int i=1; i<=n; i++)
		V[find(i)].PB(X[i]);
	for(int i=1; i<=n; i++)
	{
		sort(V[i].begin(), V[i].end());
		int tmp=0, prev=-1, maxi=0;
		for(int j=0; j<(int)V[i].size(); j++)
		{
			if(V[i][j]!=prev)
			{
				prev=V[i][j];
				tmp=0;
			}
			tmp++;
			maxi=max(maxi, tmp);
		}
		res+=(int)V[i].size()-maxi;
	}
	printf("%d\n", res);
	return 0;
}