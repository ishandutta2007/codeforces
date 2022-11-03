#include<bits/stdc++.h>
#define ll long long
#define FOr(i,x,y)  for(ll i=x;i>=y;--i)
#define For(i,x,y)	for(ll i=x;i<=y;++i)
#define pa pair<ll,ll>
using namespace std;
ll read(){	ll x;	scanf("%I64d",&x);	return x;}
const ll N=300010;
priority_queue<pa,vector<pa>,greater<pa> >q[N];
ll head[N],nxt[N*2],vet[N*2],dep[N],tag[N],n,m,tot,ans;
void insert(ll x,ll y){	nxt[++tot]=head[x];	head[x]=tot;	vet[tot]=y;	}
void merge(ll x,ll y){
	if (q[x].size()<q[y].size())	swap(q[x],q[y]),swap(tag[x],tag[y]);
	while(!q[y].empty())	q[x].push(make_pair(q[y].top().first+tag[y]-tag[x],q[y].top().second)),q[y].pop();
}
void Dfs(ll x,ll pre){
	for(ll i=head[x];i;i=nxt[i])	if (vet[i]!=pre)	Dfs(vet[i],x),merge(x,vet[i]);
	while(!q[x].empty()&&dep[x]<=q[x].top().second)	q[x].pop();
	if (x!=1){
		if (q[x].empty()){	puts("-1");	exit(0);	}
		ll cost=q[x].top().first+tag[x];
		ans+=cost;	tag[x]-=cost;
	}
}
void dfs(ll x,ll pre){	dep[x]=dep[pre]+1;	for(ll i=head[x];i;i=nxt[i])	if (vet[i]!=pre)	dfs(vet[i],x);	}
int main(){
	n=read();	m=read();
	For(i,2,n){
		ll x=read(),y=read();
		insert(x,y);	insert(y,x);
	}dfs(1,0);
	For(i,1,m){
		ll x=read(),y=read(),w=read();
		q[x].push(make_pair(w,dep[y]));
	}Dfs(1,0);	printf("%I64d",ans); 
}