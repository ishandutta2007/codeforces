#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
#define pb push_back
#define mp make_pair
const int N=500050;
int deg[N],dep[N];
vector<pair<int,int> > edges;
queue<int> q;
int max(int a, int b){ return a>b?a:b;}
int main()
{
	int n,d,k,i,sz=0;
	scanf("%i %i %i",&n,&d,&k);
	d++;
	if(n==1 && d==1) return printf("YES\n"),0;
	if(n==2 && d==2 && k==1) return printf("YES\n1 2\n"),0;
	if(d>n || k==1) return printf("NO\n"),0;
	for(i=1;i<=d;i++)
	{
		if(sz) edges.pb(mp(sz,sz+1)),deg[sz]++,deg[sz+1]++;
		sz++;
		dep[sz]=max(sz,d-sz+1);
		q.push(sz);
	}
	while(q.size() && sz<n)
	{
		int x=q.front();q.pop();
		if(dep[x]==d || deg[x]==k) continue;
		sz++;edges.pb(mp(sz,x));deg[sz]++;deg[x]++;dep[sz]=dep[x]+1;
		q.push(x);q.push(sz);
	}
	if(sz<n) printf("NO\n");
	else
	{
		printf("YES\n");
		for(i=0;i<edges.size();i++) printf("%i %i\n",edges[i].first,edges[i].second);
	}
	return 0;
}