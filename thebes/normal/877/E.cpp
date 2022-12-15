#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,ssse3,sse3,sse4,popcnt,avx,mmx,abm,tune=native")
#include <bits/stdc++.h>
using namespace std;

const int MN = 2e5+5;
pair<int,int> t[MN];
int N, M, i, x, y, nxt, arr[MN];
struct node{int v, f;}st[3*MN];
vector<int> adj[MN];
string s;

void dfs(int n){
	t[n].first = ++nxt;
	for(auto v : adj[n]) dfs(v);
	t[n].second = nxt;
}

void build(int i,int s,int e){
	if(s!=e){
		build(2*i,s,(s+e)/2);
		build(2*i+1,(s+e)/2+1,e);
		st[i].v=st[2*i].v+st[2*i+1].v;
	}
	else st[i].v=arr[s];
}

void push_down(int i,int s,int e){
	if(!st[i].f) return ;
	st[i].v = e-s+1-st[i].v;
	if(s != e){
		st[2*i].f=!st[2*i].f;
		st[2*i+1].f=!st[2*i+1].f;
	}
	st[i].f = 0;
}

void upd(int i,int s,int e,int ss,int se){
	if(st[i].f) push_down(i,s,e);
	if(s>=ss&&e<=se)
		st[i].f=1,push_down(i,s,e);
	else{
		if((s+e)/2<ss) upd(2*i+1,(s+e)/2+1,e,ss,se),push_down(2*i,s,(s+e)/2);
		else if((s+e)/2>=se) upd(2*i,s,(s+e)/2,ss,se),push_down(2*i+1,(s+e)/2+1,e);
		else upd(2*i+1,(s+e)/2+1,e,ss,se),upd(2*i,s,(s+e)/2,ss,se);
		st[i].v = st[2*i].v+st[2*i+1].v;
	}
}

int qu(int i,int s,int e,int ss,int se){
	if(st[i].f) push_down(i,s,e);
	if(s>=ss&&e<=se) return st[i].v;
	else if((s+e)/2<ss) return qu(2*i+1,(s+e)/2+1,e,ss,se);
	else if((s+e)/2>=se) return qu(2*i,s,(s+e)/2,ss,se);
	else return qu(2*i+1,(s+e)/2+1,e,ss,se)+qu(2*i,s,(s+e)/2,ss,se);
}

int main(){
	for(scanf("%d",&N),i=2;i<=N;i++){
		scanf("%d",&x);
		adj[x].push_back(i);
	}
	dfs(1);
	for(i=1;i<=N;i++){
		scanf("%d",&x);
		arr[t[i].first]=arr[t[i].second]=x;
	}
	build(1,1,N);
	for(scanf("%d",&M);M;M--){
		cin >> s >> x;
		if(s=="get") printf("%d\n",qu(1,1,N,t[x].first,t[x].second));
		else upd(1,1,N,t[x].first,t[x].second);
	}
	return 0;
}