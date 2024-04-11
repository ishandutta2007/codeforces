#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
#define mp make_pair
#define pb push_back
const int N=1000050;
int r[N];
vector<int> id;
int Find(int x){ return lower_bound(id.begin(),id.end(),x)-id.begin()+1;}
vector<int> E[N];
int cnt[N];
int main()
{
	int n,i,k,u,v,j;
	scanf("%i %i",&n,&k);
	for(i=1;i<=n;i++) scanf("%i",&r[i]),id.pb(r[i]);
	sort(id.begin(),id.end());
	id.erase(unique(id.begin(),id.end()),id.end());
	for(i=1;i<=n;i++) r[i]=Find(r[i]),cnt[r[i]]++;
	for(i=1;i<=n;i++) cnt[i]+=cnt[i-1];
	while(k--) scanf("%i %i",&u,&v),E[u].pb(v),E[v].pb(u);
	for(i=1;i<=n;i++)
	{
		int sol=cnt[r[i]-1];
		for(j=0;j<E[i].size();j++)
		{
			int v=E[i][j];
			if(r[v]<r[i]) sol--;
		}
		printf("%i ",sol);
	}
	return 0;
}