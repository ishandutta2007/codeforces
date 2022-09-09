#include <stdio.h>
#include <vector>
using namespace std;
#define ll long long
const int N=100050;
vector<int> Tree[N];
ll dec[N],inc[N],val[N];
ll max(ll a, ll b){ return a>b?a:b;}
void DFS(int cur, int prev)
{
	int i;
	for(i=0;i<Tree[cur].size();i++)
	{
		int v=Tree[cur][i];
		if(v!=prev)
		{
			DFS(v,cur);
			inc[cur]=max(inc[cur],inc[v]);
			dec[cur]=max(dec[cur],dec[v]);
		}
	}
	ll ost=val[cur]-dec[cur]+inc[cur];
	if(ost<0) inc[cur]-=ost;
	else dec[cur]+=ost;
}
int main()
{
	int n,u,v,i;
	scanf("%i",&n);
	for(i=1;i<n;i++)
	{
		scanf("%i %i",&u,&v);
		Tree[u].push_back(v);
		Tree[v].push_back(u);
	}
	for(i=1;i<=n;i++) scanf("%lld",&val[i]);
	DFS(1,0);
	printf("%lld\n",inc[1]+dec[1]);
	return 0;
}