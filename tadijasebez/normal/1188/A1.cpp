#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define mt make_tuple
void ckmx(int &a, int b){ a=max(a,b);}
void ckmn(int &a, int b){ a=min(a,b);}
void ckmx(ll &a, ll b){ a=max(a,b);}
void ckmn(ll &a, ll b){ a=min(a,b);}
const int N=200050;
int deg[N];
int main()
{
	int n,u,v;
	scanf("%i",&n);
	for(int i=1;i<n;i++) scanf("%i %i",&u,&v),deg[u]++,deg[v]++;
	for(int i=1;i<=n;i++)
	{
		if(deg[i]==2)
		{
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	return 0;
}