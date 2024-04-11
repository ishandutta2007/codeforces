#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
const int N=100050;
vector<int> E[N];
int in[N],a[N],b[N],val[N];
int max(int a, int b){ return a>b?a:b;}
bool Check(int n, int mid)
{
	int i;
	for(i=1;i<=n;i++) in[i]=0,val[i]=0,E[i].clear();
	for(i=1;i<=mid;i++)
	{
		E[a[i]].push_back(b[i]);
		in[b[i]]++;
	}
	queue<int> q;
	for(i=1;i<=n;i++) if(!in[i]) q.push(i),val[i]=1;
	int sol=0;
	while(q.size())
	{
		int u=q.front();
		q.pop();
		sol=max(sol,val[u]);
		for(i=0;i<E[u].size();i++)
		{
			int v=E[u][i];
			in[v]--;
			val[v]=max(val[v],val[u]+1);
			if(!in[v]) q.push(v);
		}
	}
	return sol==n;
}
int main()
{
	int n,m,i;
	scanf("%i %i",&n,&m);
	for(i=1;i<=m;i++) scanf("%i %i",&a[i],&b[i]);
	int top=m,bot=1,ans=-1,mid;
	while(top>=bot)
	{
		mid=top+bot>>1;
		if(Check(n,mid)) ans=mid,top=mid-1;
		else bot=mid+1;
	}
	printf("%i\n",ans);
	return 0;
}