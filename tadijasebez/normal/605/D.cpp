#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define pb push_back
const int N=100050;
const int M=4*N;
int a[N],b[N],c[N],d[N];
bool comp(int i, int j){ return b[i]<b[j];}
vector<int> all[M];
int was[M],vis[N];
void Set(int id){ for(int i=a[id];i<M;i+=i&-i) all[i].pb(id);}//,printf("Push:%i -> %i\n",id,i);}
void Build(){ for(int i=1;i<M;i++) sort(all[i].begin(),all[i].end(),comp);}
int Get(int id)
{
	for(int i=c[id];i;i-=i&-i)
	{
		while(was[i]<all[i].size() && vis[all[i][was[i]]]) was[i]++;
		//printf("i:%i was:%i sz:%i j:%i\n",i,was[i],all[i].size(),all[i][was[i]]);
		if(was[i]<all[i].size() && b[all[i][was[i]]]<=d[id]) return all[i][was[i]++];
	}
	return 0;
}
vector<int> id;
int Find(int x){ return lower_bound(id.begin(),id.end(),x)-id.begin()+1;}
int dist[N],go[N];
int main()
{
	int n,i;
	scanf("%i",&n);
	id.pb(0);
	for(i=1;i<=n;i++)
	{
		scanf("%i %i %i %i",&a[i],&b[i],&c[i],&d[i]);
		id.pb(a[i]);id.pb(b[i]);id.pb(c[i]);id.pb(d[i]);
	}
	sort(id.begin(),id.end());
	id.erase(unique(id.begin(),id.end()),id.end());
	for(i=0;i<=n;i++) a[i]=Find(a[i]),b[i]=Find(b[i]),c[i]=Find(c[i]),d[i]=Find(d[i]);
	//for(i=0;i<=n;i++) printf("%i %i %i %i\n",a[i],b[i],c[i],d[i]);
	for(i=1;i<=n;i++) Set(i);
	Build();
	queue<int> q;
	vis[0]=1;
	q.push(0);
	while(q.size())
	{
		int x=q.front();
		q.pop();
		//printf("%i\n",x);
		int y;
		for(y=Get(x);y;y=Get(x))
		{
			vis[y]=1;
			dist[y]=dist[x]+1;
			go[y]=x;
			q.push(y);
		}
	}
	if(!vis[n]) return printf("-1\n"),0;
	vector<int> ret;
	int x=n;
	while(x) ret.pb(x),x=go[x];
	printf("%i\n",ret.size());
	reverse(ret.begin(),ret.end());
	for(i=0;i<ret.size();i++) printf("%i ",ret[i]);
	printf("\n");
	return 0;
}