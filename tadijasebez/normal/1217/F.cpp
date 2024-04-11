//	2001
#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define pb push_back
const int N=200005;
const int L=18;
const int M=N*L*2;
stack<int> reu;
int tsz,go[M][2],fa[M],sz[M],my_mask[M],mask[M];
pii my_edg[M];
int New(){
	int x;if(reu.empty())x=++tsz;else x=reu.top(),reu.pop();
	go[x][0]=go[x][1]=fa[x]=0;sz[x]=1;my_mask[x]=mask[x]=0;
	return x;
}
void Free(int x){reu.push(x);go[x][0]=go[x][1]=fa[x]=sz[x]=my_mask[x]=mask[x]=0;my_edg[x]={0,0};}
void pull(int x){assert(x!=0);sz[x]=sz[go[x][0]]+1+sz[go[x][1]];mask[x]=mask[go[x][0]]|my_mask[x]|mask[go[x][1]];}
int pd(int x){return go[fa[x]][0]==x?0:go[fa[x]][1]==x?1:-1;}
void rot(int x){
	int y=fa[x],z=fa[y],p=pd(x),q=pd(y),w=go[x][p^1];
	if(~q)go[z][q]=x;go[x][p^1]=y;go[y][p]=w;
	if(w)fa[w]=y;fa[y]=x;fa[x]=z;
	pull(y);pull(x);
}
void splay(int x){for(;~pd(x);rot(x))if(~pd(fa[x]))rot(pd(x)==pd(fa[x])?fa[x]:x);}
int exp_r(int x){splay(x);while(go[x][1])x=go[x][1];splay(x);return x;}
int exp_l(int x){splay(x);while(go[x][0])x=go[x][0];splay(x);return x;}
void mrg(int x,int y){if(x&&y)x=exp_r(x),splay(y),go[x][1]=y,fa[y]=x,pull(x);}
int Find(int x,int m){
	if(mask[go[x][0]]&m)return Find(go[x][0],m);
	if(my_mask[x]&m)return x;
	return Find(go[x][1],m);
}
void fir(int x){splay(x);if(go[x][0]){int y=go[x][0];fa[y]=0;go[x][0]=0;pull(x);mrg(x,y);}}
void cut(int x){
	splay(x);
	int y=go[x][0],z=go[x][1];
	fa[y]=fa[z]=0;Free(x);
}
struct EulerTourTree{
	set<pii> E,A;
	map<pii,int> edg;
	EulerTourTree(){}
	void init(int n){E.clear();A.clear();edg.clear();}
	bool empty_e(int x){auto it=E.lower_bound({x,0});return it==E.end()||it->first!=x;}
	bool empty_a(int x){auto it=A.lower_bound({x,0});return it==A.end()||it->first!=x;}
	int node(int x){
		auto it=edg.lower_bound({x,0});
		if(it==edg.end()||it->first.first!=x)return 0;
		return it->second;
	}
	void cng_rt(int x){x=node(x);if(!x)return;fir(x);}
	int find_rt(int x){if(!node(x))return x;return my_edg[exp_l(node(x))].first;}
	bool con(int x,int y){return find_rt(x)==find_rt(y);}
	void add_mask(int x){int nd=node(x);if(nd)splay(nd),my_mask[nd]=(!empty_a(x))*2+(!empty_e(x)),pull(nd);}
	void del_mask(int x){int nd=node(x);if(nd)splay(nd),my_mask[nd]=0,pull(nd);}
	void ins_e(int x,int y){E.insert({x,y});add_mask(x);}
	void ins_a(int x,int y){A.insert({x,y});add_mask(x);}
	void del_e(int x,int y){E.erase({x,y});add_mask(x);}
	void del_a(int x,int y){A.erase({x,y});add_mask(x);}
	bool is_edge(int x,int y){return edg.find({x,y})!=edg.end();}
	bool is_arc(int x,int y){return A.find({x,y})!=A.end();}
	int sub_sz(int x){x=node(x);if(x)splay(x);return sz[x]/2+1;}
	void take_edges(int x,vector<pii>&ret){
		if(node(x)){
			x=node(x);
			while(1){
				splay(x);if(!(mask[x]&1))break;
				int y=Find(x,1);splay(y);
				assert(my_mask[y]&1);
				int X=my_edg[y].first;
				assert(!empty_e(X));
				int Y=E.lower_bound({X,0})->second;
				del_e(X,Y);del_e(Y,X);
				ret.pb({X,Y});
			}
		}else assert(empty_e(x));
	}
	pii take_arcs(int x,vector<pii>&ret){
		if(node(x)){
			x=node(x);
			while(1){
				splay(x);if(!(mask[x]&2))break;
				int y=Find(x,2);splay(y);
				assert(my_mask[y]&2);
				int X=my_edg[y].first;
				assert(!empty_a(X));
				int Y=A.lower_bound({X,0})->second;
				del_a(X,Y);del_a(Y,X);
				if(!con(X,Y))return {X,Y};
				else ret.pb({X,Y});
			}
		}else{
			while(!empty_a(x)){
				int y=A.lower_bound({x,0})->second;
				del_a(x,y);del_a(y,x);
				if(!con(x,y))return {x,y};
				else ret.pb({x,y});
			}
		}
		return {-1,-1};
	}
	void DelEdge(int x,int y){
		if(is_arc(x,y))del_a(x,y),del_a(y,x);
		else{
			if(E.find({x,y})!=E.end())del_e(x,y),del_e(y,x);
			del_mask(x);del_mask(y);
			fir(edg[{x,y}]);
			cut(edg[{x,y}]);edg.erase({x,y});
			cut(edg[{y,x}]);edg.erase({y,x});
			add_mask(x);add_mask(y);
		}
	}
	void AddEdge(int x,int y){
		if(con(x,y))ins_a(x,y),ins_a(y,x);
		else{
			del_mask(x);del_mask(y);
			int nx=node(x),ny=node(y);
			cng_rt(x);cng_rt(y);
			int a=edg[{x,y}]=New();my_edg[a]={x,y};
			int b=edg[{y,x}]=New();my_edg[b]={y,x};
			mrg(nx,a);mrg(a,ny);mrg(a,b);
			ins_e(x,y);ins_e(y,x);
		}
	}
};
struct HolmDeLichtenbergThorup{
	EulerTourTree ETT[L];
	HolmDeLichtenbergThorup(){}
	void init(int n){for(int i=0;i<L;i++)ETT[i].init(n);}
	void AddEdge(int u,int v){ETT[0].AddEdge(u,v);}
	void Replace(int u,int v,int lvl){
		pii repl={-1,-1};
		for(int i=lvl;i>=0;i--){
			int w=ETT[i].sub_sz(u)>ETT[i].sub_sz(v)?v:u;
			vector<pii> E;
			ETT[i].take_edges(w,E);
			for(auto p:E)ETT[i+1].AddEdge(p.first,p.second);
			E.clear();
			if(repl.first==-1)repl=ETT[i].take_arcs(w,E);
			for(auto p:E)ETT[i+1].AddEdge(p.first,p.second);
			if(repl.first!=-1)ETT[i].AddEdge(repl.first,repl.second);
		}
	}
	void DelEdge(int u,int v){
		if(ETT[0].is_edge(u,v)){
			int i;for(i=0;i<L;i++){
				if(ETT[i].is_edge(u,v))
					ETT[i].DelEdge(u,v);
				else break;
			}
			Replace(u,v,i-1);
		}else{
			for(int i=0;i<L;i++)
				if(ETT[i].is_arc(u,v))
					ETT[i].DelEdge(u,v);
		}
	}
	bool con(int u,int v){return ETT[0].con(u,v);}
}HDT;
int main(){
	int n,q,last=0;scanf("%i %i",&n,&q);
	set<pii> edges;HDT.init(n);
	while(q--){
		int t,x,y;scanf("%i %i %i",&t,&x,&y);
		x=(x+last-1)%n+1;
		y=(y+last-1)%n+1;
		if(x>y)swap(x,y);
		if(t==1){
			if(edges.count({x,y})){
				HDT.DelEdge(x,y);
				edges.erase({x,y});
			}else{
				HDT.AddEdge(x,y);
				edges.insert({x,y});
			}
		}else{
			last=HDT.con(x,y);
			printf("%i",last);
		}
	}
	return 0;
}