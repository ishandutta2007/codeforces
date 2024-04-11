#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
#define PB push_back

queue<int> Q;

int ins[100003], out[100003], W[100003], N[100003];
vector<int> V[100003];
bool h[100004], g[100003];

int main()
{
	int n;
	scanf("%d", &n);
	for(int i=1; i<=n; i++)
	{
		int a;
		scanf("%d", &a);
		if(a) h[i]=1;
	}
	for(int i=1; i<=n; i++)
	{
		int a;
		scanf("%d", &a);
		if(a!=0)
		{
			ins[i]++;
			out[a]++;
			V[i].PB(a);
		}
	}
	for(int i=1; i<=n; i++) if(out[i]>1) g[i]=1;
	for(int i=1; i<=n; i++)
	{
		if(h[i]==1) {W[i]=1; Q.push(i);}
	}
	while(!Q.empty())
	{
		int v=Q.front();
		Q.pop();
		for(int i=0; i<V[v].size(); i++)
		{
			out[V[v][i]]--;
			if(out[V[v][i]]==0 && g[V[v][i]]!=1)
			{
				Q.push(V[v][i]);
				if(W[v]+1>W[V[v][i]])
				{
					W[V[v][i]]=W[v]+1;
					N[V[v][i]]=v;
				}
			}
			
		}
	}
	int m=0, pos=0;
	for(int i=1; i<=n; i++)
	{
		if(W[i]>m)
		{
			m=W[i];
			pos=i;
		}
	}
	printf("%d\n%d ", m, pos);
	while(N[pos]!=0)
	{
		printf("%d ", N[pos]);
		pos=N[pos];
	}
	return 0;
}