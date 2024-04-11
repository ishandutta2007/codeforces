#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
namespace tourist{

template <typename T>
class graph {
 public:
  struct edge {
    int from;
    int to;
    T cost;
  };
 
  vector<edge> edges;
  vector<vector<int>> g;
  int n;
 
  graph(int _n) : n(_n) {
    g.resize(n);
  }
 
  virtual int add(int from, int to, T cost) = 0;
};
 
template <typename T>
class undigraph : public graph<T> {
 public:
  using graph<T>::edges;
  using graph<T>::g;
  using graph<T>::n;
 
  undigraph(int _n) : graph<T>(_n) {
  }
 
  int add(int from, int to, T cost = 1) {
    assert(0 <= from && from < n && 0 <= to && to < n);
    int id = (int) edges.size();
    g[from].push_back(id);
    g[to].push_back(id);
    edges.push_back({from, to, cost});
    return id;
  }
};
 
template <typename T>
vector<int> find_max_unweighted_matching(const undigraph<T>& g) {
  vector<int> mate(g.n, -1);
  vector<int> label(g.n);
  vector<int> parent(g.n);
  vector<int> orig(g.n);
  queue<int> q;
  vector<int> aux(g.n, -1);
  int aux_time = -1;
  auto lca = [&](int x, int y) {
    aux_time++;
    while (true) {
      if (x != -1) {
        if (aux[x] == aux_time) {
          return x;
        }
        aux[x] = aux_time;
        if (mate[x] == -1) {
          x = -1;
        } else {
          x = orig[parent[mate[x]]];
        }
      }
      swap(x, y);
    }
  };
  auto blossom = [&](int v, int w, int a) {
    while (orig[v] != a) {
      parent[v] = w;
      w = mate[v];
      if (label[w] == 1) {
        label[w] = 0;
        q.push(w);
      }
      orig[v] = orig[w] = a;
      v = parent[w];
    }
  };
  auto augment = [&](int v) {
    while (v != -1) {
      int pv = parent[v];
      int nv = mate[pv];
      mate[v] = pv;
      mate[pv] = v;
      v = nv;
    }
  };
  auto bfs = [&](int root) {
    fill(label.begin(), label.end(), -1);
    iota(orig.begin(), orig.end(), 0);
    while (!q.empty()) {
      q.pop();
    }
    q.push(root);
    label[root] = 0;
    while (!q.empty()) {
      int v = q.front();
      q.pop();
      for (int id : g.g[v]) {
        auto &e = g.edges[id];
        int x = e.from ^ e.to ^ v;
        if (label[x] == -1) {
          label[x] = 1;
          parent[x] = v;
          if (mate[x] == -1) {
            augment(x);
            return true;
          }
          label[mate[x]] = 0;
          q.push(mate[x]);
          continue;
        }
        if (label[x] == 0 && orig[v] != orig[x]) {
          int a = lca(orig[v], orig[x]);
          blossom(x, v, a);
          blossom(v, x, a);
        }
      }
    }
    return false;
  };
  auto greedy = [&]() {
    vector<int> order(g.n);
    iota(order.begin(), order.end(), 0);
    shuffle(order.begin(), order.end(), mt19937(787788));
    for (int i : order) {
      if (mate[i] == -1) {
        for (int id : g.g[i]) {
          auto &e = g.edges[id];
          int to = e.from ^ e.to ^ i;
          if (mate[to] == -1) {
            mate[i] = to;
            mate[to] = i;
            break;
          }
        }
      }
    }
  };
  greedy();
  for (int i = 0; i < g.n; i++) {
    if (mate[i] == -1) {
      bfs(i);
    }
  }
  return mate;
}

}
// tourist::undigraph<>g
// g.add(from,to)
// tourist::find_max_unweighted_matching(g)
const int N=300005;
int n,a[N],eid,root,f1[605][605];
tuple<int,int,int,int>f2[605][605];
bool vis[N];
vector<tuple<int,int,int,int> >e[605];
struct ufs{
	int fa[605],tag[605];
	ufs(){
		rep(i,1,604)fa[i]=i;
	}
	int fd(int k1){return fa[k1]==k1?k1:fa[k1]=fd(fa[k1]);}
	bool mer(int u,int v){
		u=fd(u),v=fd(v);
		if(u==v){
			if(tag[u])return 0;
			tag[u]=1;
			return 1;
		}else{
			if(tag[u]&&tag[v])return 0;
			tag[v]|=tag[u],fa[u]=v;
			return 1;
		}
	}
}o1;
int used[N],nowt;
void get_root(int u,int last){
	if(used[u]==nowt)return;
	used[u]=nowt;
	for(auto&x:e[u])if(get<3>(x)!=last){
		if(used[get<0>(x)]==nowt)root=get<0>(x);
		get_root(get<0>(x),get<3>(x));
	}
}
void deal(int u,int last){
	for(auto&x:e[u])if(get<3>(x)!=last){
		if(used[get<3>(x)]==nowt)continue;
		used[get<3>(x)]=nowt;
		if(!vis[get<0>(x)]){
			if(!a[get<2>(x)])a[get<2>(x)]=get<0>(x),vis[get<0>(x)]=1;
		}else{
			if(!a[get<1>(x)])a[get<1>(x)]=u,vis[u]=1;
		}
		deal(get<0>(x),get<3>(x));
	}
}
void color(int u,int last){
	for(auto&x:e[u])if(get<3>(x)!=last){
		if(!a[get<2>(x)])a[get<2>(x)]=get<0>(x);
		color(get<0>(x),get<3>(x));
	}
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&a[i]);
	vis[0]=1;
	rep(i,1,n-1){
		if(a[i]&&a[i+1]&&a[i]==a[i+1]){
			vis[a[i]]=1;
		}
	}
	while(1){ // tle?
		bool flg=0;
		for(int i=1,j;i<=n;i=j){ // 0
			j=i+1;
			while(j<=n&&(!!a[i])==(!!a[j]))++j;
			if(!a[i]){
				int u=vis[a[i-1]]?0:a[i-1],u_=i,v=vis[a[j]]?0:a[j],v_=j-1;
				if((j-i)&1){
					if(!u&&!v){
					}else if(!u){
						a[v_]=v;
						vis[v]=1;
						flg=1;
					}else if(!v||u==v){
						a[u_]=u;
						vis[u]=1;
						flg=1;
					}else{
					}
				}
			}
		}
		if(!flg)break;
	}
	//rep(i,1,n)printf("%d%c",a[i],i==n?'\n':' ');
	for(int i=1,j;i<=n;i=j){ // 1
		j=i+1;
		while(j<=n&&(!!a[i])==(!!a[j]))++j;
		if(!a[i]){
			int u=vis[a[i-1]]?0:a[i-1],u_=i,v=vis[a[j]]?0:a[j],v_=j-1;
			if((j-i)&1){
				if(!u&&!v){
				}else if(!u){
				}else if(!v||u==v){
				}else{
					if(o1.mer(u,v)){
						e[u].eb(v,u_,v_,++eid);
						e[v].eb(u,v_,u_,eid);
					}
				}
			}
		}
	}
	rep(i,1,600)if(o1.fd(i)==i&&o1.tag[i]){
		root=i;
		++nowt;
		get_root(i,0);
		++nowt;
		deal(root,0);
	}
	//rep(i,1,n)printf("%d%c",a[i],i==n?'\n':' ');
	tourist::undigraph<int>g(605);
	for(int i=1,j;i<=n;i=j){ // 2
		j=i+1;
		while(j<=n&&(!!a[i])==(!!a[j]))++j;
		if(!a[i]){
			int u=vis[a[i-1]]?0:a[i-1],u_=i,v=vis[a[j]]?0:a[j],v_=j-1;
			if(~(j-i)&1){
				if(!u&&!v){
				}else if(!u){
				}else if(!v||u==v){
				}else if(o1.fd(u)!=o1.fd(v)){
					if(o1.fd(u)>o1.fd(v))swap(u,v),swap(u_,v_);
					if(!o1.tag[o1.fd(u)]&&!o1.tag[o1.fd(v)]){
						if(!f1[o1.fd(u)][o1.fd(v)]){
							f1[o1.fd(u)][o1.fd(v)]=1;
							f2[o1.fd(u)][o1.fd(v)]={u,u_,v,v_};
							g.add(o1.fd(u),o1.fd(v));
						}
					}
				}
			}
		}
	}
	auto ps=[&](int u){
		assert(!o1.tag[o1.fd(u)]);
		o1.tag[o1.fd(u)]=1;
		color(u,0);
	};
	vector<int>mate(tourist::find_max_unweighted_matching(g));
	rep(i,1,600)if(mate[i]!=-1&&i<mate[i]){
		assert(f1[i][mate[i]]);
		int u,u_,v,v_;
		tie(u,u_,v,v_)=f2[i][mate[i]];
		a[u_]=u,a[v_]=v;
		ps(u);
		ps(v);
	}
	rep(i,1,600)if(o1.fd(i)==i&&!o1.tag[i]){
		color(i,0);
	}
	rep(i,1,n-1)if(a[i]&&a[i+1]&&a[i]==a[i+1])vis[a[i]]=1;
	int cur=n;
	rep(i,1,n-1)if(!a[i]&&!a[i+1]){
		while(cur>=1&&vis[cur])--cur;
		vis[cur]=1;
		a[i]=a[i+1]=cur;
	}
	rep(i,1,n)if(!a[i]){
		a[i]=n;
	}
#ifdef xay5421
	int res=0;
	rep(i,1,n)res+=vis[i];
	printf("%d\n",res);
	//rep(i,1,n)printf("%d%c",a[i],i==n?'\n':' ');
#else
	rep(i,1,n)printf("%d%c",a[i],i==n?'\n':' ');
#endif
	return 0;
}