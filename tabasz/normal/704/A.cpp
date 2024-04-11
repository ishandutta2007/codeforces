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

set<int> se;
vector<int> V[300003];

int main()
{
	//ios_base::sync_with_stdio(0);
	int n, q, tmp=0;
	scanf("%d%d", &n, &q);
	for(int i=0; i<q; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		if(a==1)
		{
			tmp++;
			V[b].PB(tmp);
			se.insert(tmp);
		}
		if(a==2)
		{
			while(!V[b].empty())
			{
				int x=V[b][V[b].size()-1];
				V[b].pb();
				if(se.find(x)!=se.end())
					se.erase(se.find(x));
			}
		}
		if(a==3)
			while(!se.empty() && *se.begin()<=b)
				se.erase(se.begin());
		printf("%d\n", (int)se.size());
	}
	return 0;
}