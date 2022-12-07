#include<bits/stdc++.h>

using namespace std;

#define rg register
#define In inline
#define ll long long

const int N = 3000;

namespace IO{
	In ll read(){
		ll s = 0,ww = 1;
		char ch = getchar();
		while(ch < '0' || ch > '9'){if(ch == '-')ww = -1;ch = getchar();}
		while('0' <= ch && ch <= '9'){s = 10 * s + ch - '0';ch = getchar();}
		return s * ww;
	}
	In void write(ll x){
		if(x < 0)putchar('-'),x = -x;
		if(x > 9)write(x / 10);
		putchar('0' + x % 10);
	}
}
using namespace IO;

int n,m,deg[N+5],curdeg[N+5],num1,cnt;
int head[N+5];
bool vis[N+5],adj[N+5];
vector<int> vc,vc2,vct;
queue<int> Q;

struct edge{
	int to,next,open;
}e[2*N+5];

In void addedge(int u,int v){
	cnt++;
	e[cnt].to = v;
	e[cnt].next = head[u];
	e[cnt].open = 1;
	head[u] = cnt;
}
void simulate(int u){ // find Eular route starting from u
	for(rg int i = head[u];i;i = e[i].next){
		int v = e[i].to;
		if(!e[i].open)continue;
		e[i].open = e[i^1].open = 0;
		simulate(v);
	}
	vc.push_back(u);
}
void print(){
	cout<<vc.size()<<endl;
	for(rg int i = 0;i < vc.size();i++)cout<<vc[i]<<" ";cout<<endl;
}
void bfs(int s,int &x,int &y){
	vct.resize(0);
	vis[s] = 1;Q.push(s);
	x = 0,y = 0;
	while(!Q.empty()){
		int u = Q.front();
		Q.pop();
		vct.push_back(u);
		curdeg[u] = 0;
		for(rg int i = head[u];i;i = e[i].next){
			int v = e[i].to;
			if(e[i].open)curdeg[u]++;
			if(!e[i].open || vis[v])continue;
			vis[v] = 1;
			Q.push(v);
		}
		if(curdeg[u] & 1){if(adj[u])y++;else x++;}
	}
}
void clear(int u){
	for(rg int i = head[u];i;i = e[i].next){
		adj[e[i].to] = 0;
		e[i].open = e[i^1].open = 1;
	}
}
bool check(int u){
	int t = 0;
	memset(vis,0,sizeof(vis));
	for(rg int i = head[u];i;i = e[i].next){
		adj[e[i].to] = 1;
		e[i].open = e[i^1].open = 0;
	}
	for(rg int i = head[u];i;i = e[i].next){
		int v = e[i].to,x,y;
		if(vis[v])continue;
		bfs(v,x,y);
		if(vct.size() == 1)continue;
		if(x >= 2){clear(u);return 0;}
		if(x == 1 && y >= 1)t++;
		if(x == 0 && y == 0){t++;e[i].open = e[i^1].open = 1;}
	}
	if(t > 1){clear(u);return 0;}
	for(rg int i = head[u];i;i = e[i].next){
		int v = e[i].to;
		if(curdeg[v] & 1)e[i].open = e[i^1].open = 1;
	}
	vc2.resize(0);
	for(rg int i = head[u];i;i = e[i].next){
		int v = e[i].to;
		if(!e[i].open)vc2.push_back(v),vc2.push_back(u);
	}
	simulate(u);
	vc.push_back(-1);
	for(rg int i = 0;i < vc2.size();i++)vc.push_back(vc2[i]);
	if(vc.back() == -1)vc.pop_back();	
	print();return 1;
/*	
	int x = num1,y = 0;
	if(deg[u] & 1)x--;
	for(rg int i = head[u];i;i = e[i].next){
		if(deg[e[i].to] & 1)x--;
		else y++;
	}
	if(!checkcon(u))return 0;
	if(x >= 2)return 0;
	else{
		if(x == 1){
			for(rg int i = head[u];i;i = e[i].next){
				int v = e[i].to;
				if(deg[v] & 1)e[i].open = e[i^1].open = 0;
			}
			simulate(u);
//			for(rg int i = 0;i < (int)vc.size() - 1 - i;i++)swap(vc[i],vc[vc.size()-1-i]);
			vc.push_back(-1);
			for(rg int i = head[u];i;i = e[i].next){
				int v = e[i].to;
				if(deg[v] & 1)vc.push_back(v),vc.push_back(u);
			}
			if(vc.back() == -1)vc.pop_back();
			print();
			return 1;
		}
		else{
			if(y == 0){
				for(rg int i = head[u];i;i = e[i].next)e[i].open = e[i^1].open = 0;
				int v = e[head[u]].to;
				simulate(v);
				vc.push_back(u);
				vc.push_back(-1);
				for(rg int i = head[u];i;i = e[i].next)if(e[i].to != v)vc.push_back(e[i].to),vc.push_back(u);
				if(vc.back() == -1)vc.pop_back();
				print();
				return 1;
			}
			else{
				for(rg int i = head[u];i;i = e[i].next){
					int v = e[i].to;
					if(deg[v] & 1)e[i].open = e[i^1].open = 0;
				}
				simulate(u);
				for(rg int i = 0;i < (int)vc.size() - 1 - i;i++)swap(vc[i],vc[vc.size()-1-i]);
				vc.push_back(-1);
				for(rg int i = head[u];i;i = e[i].next){
					int v = e[i].to;
					if(deg[v] & 1)vc.push_back(v),vc.push_back(u);
				}
				if(vc.back() == -1)vc.pop_back();
				print();
				return 1;
			}
		}
	}*/
}

int main(){
//	freopen("CF1494F.in","r",stdin);
//	freopen("CF1494F.out","w",stdout);
	n = read(),m = read();cnt = 1;
	for(rg int i = 1;i <= m;i++){
		int u = read(),v = read();
		addedge(u,v);
		addedge(v,u);
		deg[u]++,deg[v]++;
	}
	for(rg int u = 1;u <= n;u++)if(deg[u] & 1)num1++;
	if(num1 == 0){simulate(1);print();return 0;}
	for(rg int u = 1;u <= n;u++)if(check(u))return 0;
	puts("0");
	return 0;
}