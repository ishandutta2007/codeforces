#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5050;
vector<int> E[N];
int c[N],k[N],p[N];
int g[N],r[N],a[N],ans[N];
vector<int> Sts[N],Qs[N];
int n,m;
int dist[N];
void Solve(int st){
	queue<int> q;
	for(int i=1;i<=n;i++)dist[i]=-1;
	q.push(st);
	dist[st]=0;
	vector<int> ord;
	while(q.size()){
		int u=q.front();
		q.pop();
		ord.push_back(u);
		for(int v:E[u])if(dist[v]==-1){
			dist[v]=dist[u]+1;
			q.push(v);
		}
	}
	for(int qu:Qs[st]){
		multiset<pair<int,int>> sho;
		ll cost=0;
		int num=0;
		ans[qu]=-1;
		for(int u:ord){
			for(int store:Sts[u]){
				sho.insert({p[store],k[store]});
				cost+=(ll)p[store]*k[store];
				num+=k[store];
			}
			while(num>r[qu]){
				pair<int,int> store=*sho.rbegin();
				sho.erase(--sho.end());
				num-=store.second;
				cost-=(ll)store.first*store.second;
				if(num>=r[qu])continue;
				else{
					int add=r[qu]-num;
					num+=add;
					cost+=(ll)add*store.first;
					sho.insert({store.first,add});
				}
			}
			if(num==r[qu]&&cost<=a[qu]){
				ans[qu]=dist[u];
				break;
			}
		}
	}
}
int main(){
	scanf("%i %i",&n,&m);
	for(int i=1;i<=m;i++){
		int u,v;
		scanf("%i %i",&u,&v);
		E[u].push_back(v);
		E[v].push_back(u);
	}
	int w;
	scanf("%i",&w);
	for(int i=1;i<=w;i++){
		scanf("%i %i %i",&c[i],&k[i],&p[i]);
		Sts[c[i]].push_back(i);
	}
	int q;
	scanf("%i",&q);
	for(int i=1;i<=q;i++){
		scanf("%i %i %i",&g[i],&r[i],&a[i]);
		Qs[g[i]].push_back(i);
	}
	for(int i=1;i<=n;i++)Solve(i);
	for(int i=1;i<=q;i++)printf("%i\n",ans[i]);
	return 0;
}