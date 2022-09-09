#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;
#define pb push_back
#define mp make_pair
priority_queue<pair<int,int> ,vector<pair<int,int> > ,greater<pair<int,int> > > pq;
const int N=100050;
int l[N],r[N],x[N];
vector<int> id[N],ex[N];
int main()
{
	int n,i,m,j;
	scanf("%i %i",&m,&n);
	for(i=1;i<=n;i++) scanf("%i %i %i",&l[i],&r[i],&x[i]),id[l[i]].pb(i),ex[r[i]].pb(i);
	vector<int> sol;
	for(i=1;i<=m;i++)
	{
		for(j=0;j<id[i].size();j++) pq.push(mp(r[id[i][j]],id[i][j]));
		if(ex[i].size()>1) return printf("-1\n"),0;
		if(ex[i].size()==1)
		{
			if(x[ex[i][0]]>0) return printf("-1\n"),0;
			sol.pb(n+1);
		}
		else
		{
			//printf("%i\n",i);
			if(!pq.size()) sol.pb(0);
			else
			{
				int idx=pq.top().second;
				pq.pop();
				x[idx]--;
				sol.pb(idx);
				if(x[idx]>0) pq.push(mp(r[idx],idx));
			}
		}
	}
	for(i=0;i<m;i++) printf("%i ",sol[i]);
	printf("\n");
	return 0;
}