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

int n, m, k, size, tmp;
vector<int> V[300003];
set<int> X;
bool B[300003];
int vis[300003];
queue<int> Q;

int main()
{
	//ios_base::sync_with_stdio(0);
	scanf("%d%d%d", &n, &m, &k);
	size=n-1;
	for(int i=0; i<m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		V[a].PB(b);
		V[b].PB(a);
		if(a==1 || b==1)
		{
			size--;
			B[max(a, b)]=1;
		}
	}
	for(int i=1; i<=n; i++)
	{
		sort(V[i].begin(), V[i].end());
		V[i].PB(n+1);
	}
	if(size<k)
	{
		printf("impossible\n");
		return 0;
	}
	for(int i=2; i<=n; i++)
	{
		if(B[i]==0 && vis[i]==0)
		{
			tmp++;
			X.clear();
			for(int j=2; j<=n; j++)
				if(j!=i)
					X.insert(j);
			while(!Q.empty())
				Q.pop();
			Q.push(i);
			while(!Q.empty())
			{
				int v=Q.front();
				//printf("   %d\n", v);
				vis[v]=i;
				Q.pop();
				set<int>::iterator it=X.begin();
				vector<int> A;
				for(int j=0; j<(int)V[v].size(); j++)
				{
					while(it!=X.end() && *it<V[v][j])
					{
						//printf("lol %d\n", *it);
						Q.push(*it);
						A.PB(*it);
						it++;
					}
					if(it!=X.end() && *it==V[v][j])
						it++;
				}
				for(int i=0; i<(int)A.size(); i++)
					X.erase(A[i]);
			}
		}
	}
	for(int i=2; i<=n; i++)
	{
		if(vis[i]==0)
		{
			//printf("%d\n", i);
			printf("impossible\n");
			return 0;
		}
	}
	if(tmp<=k)
		printf("possible\n");
	else
		printf("impossible\n");
	return 0;
}