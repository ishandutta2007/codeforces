#include<bits/stdc++.h> 
using namespace std;
const int MAXM=2100000;
const int MAXN=2100;
const long long inf=1000000000000000000ll;
int ne[2*MAXM];
long long w[2*MAXM];
int v[2*MAXM];
int h[MAXN]={};
int tot=1;
void add(int x,int y,int ww){
	ne[++tot]=h[x],h[x]=tot,v[tot]=y,w[tot]=ww;
	ne[++tot]=h[y],h[y]=tot,v[tot]=x,w[tot]=0;
}
int d[MAXN];
int now[MAXM];
int s,t;
int N;
queue<int> q;
bool bfs(){
	for(int i=1;i<=N;i++)d[i]=0;
	while(q.size()) q.pop();
	q.push(s);
	d[s]=1;
	now[s]=h[s];
	while(q.size()){
		int x=q.front();
		q.pop();
		for(int i=h[x];i;i=ne[i]){
			if(w[i] && !d[v[i]]){
				q.push(v[i]);
				now[v[i]]=h[v[i]];
				d[v[i]]=d[x]+1;
				if(v[i]==t) return true;
			}
		}
	} 
	return false;
}
long long dinic(int x,long long flow){
	if(x==t) return flow;
	long long rest=flow;
	for(int i=now[x];i && rest;i=ne[i]){
		now[x]=i;
		if(w[i] && d[v[i]]==d[x]+1){
			long long k=dinic(v[i],min(rest,w[i]));
			if(!k) d[v[i]]=0;
			w[i]-=k;
			w[i^1]+=k;
			rest-=k;
		} 
	}
	return flow-rest;
}
int tt[2100];
int in[2100];
int main(){
	int n,m;
	cin>>n>>m;
	int cnt=0;
	for(int i=1;i<=n;i++)cin>>tt[i];
	s=n+1,t=n+2,N=n+2;
	for(int i=1;i<=n;i++){
		if(tt[i]>(m-1)/2){
			cout<<-1;
			return 0;
		}
		if(tt[i]<=m/3)add(i,t,1);
		else cnt++,add(s,i,1);
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(tt[i]<=m/3&&tt[j]>m/3&&2ll*tt[j]+tt[i]<=m&&tt[j]%tt[i]==0)add(j,i,1);
	long long maxflow=0;
	while(bfs()) maxflow+=dinic(s,inf);
	if(maxflow<cnt){
		cout<<-1;
		return 0;
	}
	cout<<n-cnt<<"\n";
	for(int i=1;i<=n;i++)if(tt[i]>m/3){
		for(int j=h[i];j;j=ne[j]){
			int k=v[j];
			if(k!=s&&w[j]==0){
				in[k]=1;
				cout<<2*tt[i]+tt[k]<<" "<<tt[i]+tt[k]<<"\n";
			}
		}
	}
	for(int i=1;i<=n;i++)if(tt[i]<=m/3&&(!in[i]))cout<<3*tt[i]<<" "<<2*tt[i]<<"\n";
/*	int n,m,e;
	scanf("%d%d%d",&n,&m,&e);
	for(int i=1;i<=e;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v+n,1);
	}
	t=n+m+2;
	s=n+m+1;
	N=n+m+2;
	for(int i=1;i<=n;i++) add(s,i,1);
	for(int i=n+1;i<=n+m;i++) add(i,t,1);
	long long maxflow=0;
	while(bfs()) maxflow+=dinic(s,inf);
	printf("%lld",maxflow);*/
	return 0;
}