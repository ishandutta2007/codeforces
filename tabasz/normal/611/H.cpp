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

int n, deg[10], A[10][10], P[10], done, lef[100], vsum[100];
vector<int> V[10], X[10][10];
vector<PII> E;

int main()
{
	P[0]=1;
	for(int i=1; i<10; i++)
		P[i]=P[i-1]*2;
	for(int i=0; i<6; i++)
	{
		for(int j=0; j<6; j++)
		{
			//printf("%d %d: ", i, j);
			if(i==j)
			{
			//	printf("\n");
				continue;
			}
			for(int k=1; k<P[6]-1; k++)
			{
				if((k>>i)%2 && (k>>j)%2==0)
				{
					X[i][j].PB(k);
				//	printf("%d ", k);
				}
			}
		//	printf("\n");
		}
	}
	//ios_base::sync_with_stdio(0);
	cin>> n;
	for(int i=1; i<=n; i++)
	{
		int tmp=0, x=1;
		while(i/x>0)
		{
			tmp++;
			x*=10;
		}
		V[tmp-1].PB(i);
	}
	for(int i=1; i<n; i++)
	{
		string a, b;
		cin>> a >> b;
		if(a.size()>b.size())
			swap(a, b);
		if(a.size()==b.size())
		{
			if(V[a.size()-1].size()<2)
			{
				cout<< "-1\n";
				return 0;
			}
			E.PB(MP(V[a.size()-1][0], V[a.size()-1][V[a.size()-1].size()-1]));
			V[a.size()-1].pb();
			done++;
		}
		else
		{
			A[a.size()-1][b.size()-1]++;
			deg[a.size()-1]++;
			deg[b.size()-1]++;
		}
	}
	for(int i=0; i<6; i++)
	{
		if(V[i].empty() && deg[i]>0)
		{
			cout<< "-1\n";
			return 0;
		}
	}
	for(int i=1; i<P[6]; i++)
	{
		int v=0, e=0;
		for(int j=0; j<6; j++)
			if((i>>j)%2)
				v+=(int)V[j].size();
		for(int j=0; j<6; j++)
		{
			if((i>>j)%2==0)
				continue;
			for(int k=j+1; k<6; k++)
				if((i>>k)%2)
					e+=A[j][k];
		}
		//printf("%d %d %d\n", i, e, v);
		vsum[i]=v;
		if(v>0 && e>=v)
		{
			cout<< "-1\n";
			return 0;
		}
		lef[i]=v-e;
	}
	int tmp=0, qwe=0;
	while(done<n-1)
	{
		for(int i=0; i<6; i++)
		{
			if(i==tmp || A[min(tmp, i)][max(i, tmp)]==0)
				continue;
			//if(!(i==1 && tmp==0 && done==9))
			//	printf("%d %d %d %d %d %d %d %d\n", i, tmp, done, deg[i], deg[tmp], A[tmp][i], (int)V[tmp].size(), (int)V[i].size());
			bool boo=1;
			for(int j=0; j<(int)X[tmp][i].size(); j++)
			{
				if(vsum[X[tmp][i][j]]>1 && lef[X[tmp][i][j]]==1)
				{
					boo=0;
					break;
				}
			}
			if((V[tmp].size()==1 && deg[tmp]>1) || (deg[i]==(int)V[i].size() && done!=n-2))
			{
				boo=0;
			//	printf("lol %d %d %d\n", done, tmp, i);
			}
			if(boo)
			{
				E.PB(MP(V[tmp][V[tmp].size()-1], V[i][0]));
				deg[tmp]--;
				A[min(tmp, i)][max(i, tmp)]--;
				deg[i]--;
				V[tmp].pb();
				for(int j=1; j<P[6]; j++)
					if((j>>tmp)%2)
						vsum[j]--;
				for(int j=0; j<(int)X[tmp][i].size(); j++)
				{
					lef[X[tmp][i][j]]--;
					if(vsum[X[tmp][i][j]]>0 && lef[X[tmp][i][j]]==0)
					{
						printf("%d %d %d %d\n", done, tmp, i, X[tmp][i][j]);
						return 0;
					}
				}
				done++;
				qwe=0;
			}
			else
				qwe++;
		}
		tmp++;
		if(tmp>=6)
			tmp=0;
		if(qwe>=40)
		{
			printf("lol %d %d %d %d %d %d %d", done, A[0][1], A[0][2], A[1][2], (int)V[0].size(), (int)V[1].size(), (int)V[2].size());
			return 0;
		}
	}
	for(int i=0; i<(int)E.size(); i++)
		cout<< E[i].F << ' ' << E[i].S << '\n';
	return 0;
}