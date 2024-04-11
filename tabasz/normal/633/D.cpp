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

int n, res=2;
int T[1005];
multiset<int> se;
multiset<int>::iterator it;
vector<int> V;

int main()
{
	//ios_base::sync_with_stdio(0);
	scanf("%d", &n);
	for(int i=0; i<n; i++)
	{
		scanf("%d", T+i);
		se.insert(T[i]);
	}
	sort(T, T+n);
	for(int i=0; i<n; i++)
	{
		if(i>0 && T[i]==T[i-1])
			continue;
		for(int j=0; j<n; j++)
		{
			if((j>0 && T[j]==T[j-1] && j!=i+1) || j==i)
				continue;
			se.erase(se.find(T[i]));
			se.erase(se.find(T[j]));
			int a=T[i]+T[j], prev=T[j], r=2;
			it=se.find(a);
			while(it!=se.end())
			{
				V.PB(*it);
				se.erase(it);
				r++;
				int qwe=a;
				a=a+prev;
				prev=qwe;
				it=se.find(a);
			}
			res=max(res, r);
			while(!V.empty())
			{
				se.insert(V[V.size()-1]);
				V.pb();
			}
			se.insert(T[i]);
			se.insert(T[j]);
		}
	}
	printf("%d\n", res);
	return 0;
}