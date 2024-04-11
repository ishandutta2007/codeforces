#include<bits/stdc++.h>
using namespace std;

const int maxm=100007;
const int maxn=207;
const int INF=1<<30;

struct edge{
	int to,next,w;
}e[maxm];

int p[maxn],d[maxn],cnt=0,n,m,s,t;
int a[maxn],b[maxn];
vector<int> ta,tb;
bool vis[maxn];

void add_edge(int x,int y,int z){
	e[cnt].to=y; e[cnt].next=p[x]; e[cnt].w=z; p[x]=cnt++; 
}

bool ck(int i,int j){
	for (int k=1;k<=m;++k){
		if (a[k]<=ta[i-1]&&a[k+m]>=ta[i]&&b[k]<=tb[j-1]&&b[k+m]>=tb[j]){
			return 1;
		}
	}
	return 0;
}

bool bfs(){
	memset(d,0,sizeof(d));
	queue<int> q;
	while (!q.empty()){
		q.pop();
	}
	q.push(s);
	d[s]=1;
	while (!q.empty()){
		int u=q.front();
		q.pop();
		for (int i=p[u];i!=-1;i=e[i].next){
			if (e[i].w&&!d[e[i].to]){
				d[e[i].to]=d[u]+1;
				q.push(e[i].to);
				if (e[i].to==t) return 1;
			}
		}
	}
	return 0;
}

int dinic(int x,int flow){
	if (x==t) return flow;
	int rest=flow,k;
	for (int i=p[x];i!=-1;i=e[i].next){
		if (e[i].w&&d[e[i].to]==d[x]+1){
			k=dinic(e[i].to,min(rest,e[i].w));
			if (!k) d[e[i].to]=0;
			e[i].w-=k;
			e[i^1].w+=k;
//			printf("%d %d %d %d\n\n",k,e[i].w,x,e[i].to);
			rest-=k;
		}
	}
	return flow-rest;
}

int main(){
	scanf("%d%d",&n,&m);
	for (int i=0;i<maxn;++i){
		p[i]=-1;
	}
	ta.push_back(0);
	ta.push_back(n);
	tb.push_back(0);
	tb.push_back(n);
	for (int i=1;i<=m;++i){
		scanf("%d%d%d%d",&a[i],&b[i],&a[i+m],&b[i+m]);
		a[i]--,b[i]--;
		ta.push_back(a[i]);
		ta.push_back(a[i+m]);
		tb.push_back(b[i]);
		tb.push_back(b[i+m]);
	}
	sort(ta.begin(),ta.end());
	sort(tb.begin(),tb.end());
	ta.resize(unique(ta.begin(),ta.end())-ta.begin());
	tb.resize(unique(tb.begin(),tb.end())-tb.begin());
	int sza=ta.size()-1,szb=tb.size()-1;
	s=0,t=sza+szb+1;
	for (int i=1;i<=sza;++i){
		add_edge(s,i,ta[i]-ta[i-1]);
		add_edge(i,s,0);
	}
	for (int i=1;i<=szb;++i){
		add_edge(i+sza,t,tb[i]-tb[i-1]);
		add_edge(t,i+sza,0);
	}
	for (int i=1;i<=sza;++i){
		for (int j=1;j<=szb;++j){
			if (ck(i,j)){
//				printf("%d %d %d %d %d %d\n",i,j,ta[i-1],ta[i],tb[j-1],tb[j]);
				add_edge(i,j+sza,INF);
				add_edge(j+sza,i,0);
			}
		}
	}
	int ans=0;
	while(bfs()){
		ans+=dinic(s,INF);
	}
	printf("%d\n",ans);
	return 0;
}