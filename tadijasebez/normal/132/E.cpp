#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
struct Edge{int u,v;ll c,w;};
vector<Edge> edges;
const int N=550;
const ll inf=9e18;
vector<int> G[N];
void AddEdge(int u,int v,ll c,ll w){
	G[u].pb(edges.size());edges.pb((Edge){u,v,c,w});
	G[v].pb(edges.size());edges.pb((Edge){v,u,0,-w});
}
ll dist[N];
int go[N];
bool in[N];
int s,t;
bool spfa(){
	for(int i=s;i<=t;i++)dist[i]=inf,in[i]=0;
	queue<int> q;
	q.push(s);dist[s]=0;in[s]=1;
	while(q.size()){
		int u=q.front();q.pop();in[u]=0;
		for(int e:G[u]){
			int v=edges[e].v;ll w=edges[e].w;
			if(edges[e].c>0&&dist[v]>dist[u]+w){
				dist[v]=dist[u]+w;go[v]=e;
				if(!in[v])q.push(v),in[v]=1;
			}
		}
	}
	return dist[t]!=inf;
}
ll MCMF(int k){
	ll ans=0;
	while(k--&&spfa()){
		for(int u=t;u!=s;u=edges[go[u]].u){
			edges[go[u]].c--;
			edges[go[u]^1].c++;
		}
		ans+=dist[t];
	}
	return ans;
}
const ll lim=1e12;
int a[N],b[26],c[26];
string ans;
int lines,cost;
void P(int j){
	ans+="print(";
	ans+='a'+j;
	ans+=")\n";
	lines++;
}
void A(int j,int x){
	ans+='a'+j;
	ans+="=";
	ans+=to_string(x);
	ans+="\n";
	lines++;
	cost+=__builtin_popcount(x);
	b[j]=x;
}
int use[N];
int main(){
	int n,m;scanf("%i %i",&n,&m);
	s=1;t=n*2;
	ll ans=0;
	for(int i=1;i<=n;i++){
		scanf("%i",&a[i]);
		AddEdge(i*2-1,i*2,1,-lim);
		AddEdge(i*2-1,i*2,m,0);
		if(i<n)AddEdge(i*2,i*2+1,m,0);
		ans+=__builtin_popcount(a[i]);
		for(int j=i-1;j>=1;j--){
			if(a[i]==a[j]){
				AddEdge(j*2,i*2-1,1,-__builtin_popcount(a[i]));
				use[j]=edges.size()-1;
				break;
			}
		}
	}
	ans+=MCMF(m)+lim*n;
	for(int i=1;i<=n;i++){
		bool ok=0;
		for(int j=0;j<26;j++){
			if(b[j]==a[i]){
				P(j);
				c[j]=i;
				ok=1;
				break;
			}
		}
		if(ok)continue;
		for(int j=0;j<26;j++){
			if(!use[c[j]]||edges[use[c[j]]].c==0){
				A(j,a[i]);
				P(j);
				c[j]=i;
				break;
			}
		}
	}
	assert(ans==cost);
	printf("%i %i\n",lines,ans);
	cout<<::ans;
	return 0;
}