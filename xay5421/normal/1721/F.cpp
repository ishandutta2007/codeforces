#include<bits/stdc++.h>
#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#define DD(...) D(#__VA_ARGS__ "="),debug_helper::debug(__VA_ARGS__),D("\n")
#include"/home/xay5421/debug.hpp"
#else
#define D(...) ((void)0)
#define DD(...) ((void)0)
#endif
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define each(x,v) for(auto&x:v)
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
template<class T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<class T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
using namespace std;
using LL=long long;
using ULL=unsigned long long;
#ifndef ATCODER_INTERNAL_QUEUE_HPP
#define ATCODER_INTERNAL_QUEUE_HPP 1

#include <vector>

namespace atcoder {

namespace internal {

template <class T> struct simple_queue {
    std::vector<T> payload;
    int pos = 0;
    void reserve(int n) { payload.reserve(n); }
    int size() const { return int(payload.size()) - pos; }
    bool empty() const { return pos == int(payload.size()); }
    void push(const T& t) { payload.push_back(t); }
    T& front() { return payload[pos]; }
    void clear() {
        payload.clear();
        pos = 0;
    }
    void pop() { pos++; }
};

}  // namespace internal

}  // namespace atcoder

#endif  // ATCODER_INTERNAL_QUEUE_HPP
#ifndef ATCODER_MAXFLOW_HPP
#define ATCODER_MAXFLOW_HPP 1

#include <algorithm>
#include <cassert>
#include <limits>
#include <queue>
#include <vector>

namespace atcoder {

template <class Cap> struct mf_graph {
  public:
    mf_graph() : _n(0) {}
    explicit mf_graph(int n) : _n(n), g(n) {}

    int add_edge(int from, int to, Cap cap) {
        assert(0 <= from && from < _n);
        assert(0 <= to && to < _n);
        assert(0 <= cap);
        int m = int(pos.size());
        pos.push_back({from, int(g[from].size())});
        int from_id = int(g[from].size());
        int to_id = int(g[to].size());
        if (from == to) to_id++;
        g[from].push_back(_edge{to, to_id, cap});
        g[to].push_back(_edge{from, from_id, 0});
        return m;
    }

    struct edge {
        int from, to;
        Cap cap, flow;
    };

    int edge_size() {
    	return int(pos.size());
    }
    
    edge get_edge(int i) {
        int m = int(pos.size());
        assert(0 <= i && i < m);
        auto _e = g[pos[i].first][pos[i].second];
        auto _re = g[_e.to][_e.rev];
        return edge{pos[i].first, _e.to, _e.cap + _re.cap, _re.cap};
    }
    std::vector<edge> edges() {
        int m = int(pos.size());
        std::vector<edge> result;
        for (int i = 0; i < m; i++) {
            result.push_back(get_edge(i));
        }
        return result;
    }
    void change_edge(int i, Cap new_cap, Cap new_flow) {
        int m = int(pos.size());
        assert(0 <= i && i < m);
        assert(0 <= new_flow && new_flow <= new_cap);
        auto& _e = g[pos[i].first][pos[i].second];
        auto& _re = g[_e.to][_e.rev];
        _e.cap = new_cap - new_flow;
        _re.cap = new_flow;
    }

    Cap flow(int s, int t) {
        return flow(s, t, std::numeric_limits<Cap>::max());
    }
    Cap flow(int s, int t, Cap flow_limit) {
        assert(0 <= s && s < _n);
        assert(0 <= t && t < _n);
        assert(s != t);

        std::vector<int> level(_n), iter(_n);
        internal::simple_queue<int> que;

        auto bfs = [&]() {
            std::fill(level.begin(), level.end(), -1);
            level[s] = 0;
            que.clear();
            que.push(s);
            while (!que.empty()) {
                int v = que.front();
                que.pop();
                for (auto e : g[v]) {
                    if (e.cap == 0 || level[e.to] >= 0) continue;
                    level[e.to] = level[v] + 1;
                    if (e.to == t) return;
                    que.push(e.to);
                }
            }
        };
        std::function<Cap(int,Cap)> dfs = [&](int v, Cap up) {
            if (v == s) return up;
            Cap res = 0;
            int level_v = level[v];
            for (int& i = iter[v]; i < int(g[v].size()); i++) {
                _edge& e = g[v][i];
                if (level_v <= level[e.to] || g[e.to][e.rev].cap == 0) continue;
                Cap d =
                    dfs(e.to, std::min(up - res, g[e.to][e.rev].cap));
                if (d <= 0) continue;
                g[v][i].cap += d;
                g[e.to][e.rev].cap -= d;
                res += d;
                if (res == up) return res;
            }
            level[v] = _n;
            return res;
        };

        Cap flow = 0;
        while (flow < flow_limit) {
            bfs();
            if (level[t] == -1) break;
            std::fill(iter.begin(), iter.end(), 0);
            Cap f = dfs(t, flow_limit - flow);
            if (!f) break;
            flow += f;
        }
        return flow;
    }

    std::vector<bool> min_cut(int s) {
        std::vector<bool> visited(_n);
        internal::simple_queue<int> que;
        que.push(s);
        while (!que.empty()) {
            int p = que.front();
            que.pop();
            visited[p] = true;
            for (auto e : g[p]) {
                if (e.cap && !visited[e.to]) {
                    visited[e.to] = true;
                    que.push(e.to);
                }
            }
        }
        return visited;
    }

  private:
    int _n;
    struct _edge {
        int to, rev;
        Cap cap;
    };
    std::vector<std::pair<int, int>> pos;
    std::vector<std::vector<_edge>> g;
};

}  // namespace atcoder

#endif  // ATCODER_MAXFLOW_HPP
const int N=200005;
int n1,n2,m,Q;
vector<int>e[N<<1];
int mate[N<<1][2];
bool ban[N<<1];
int deg[N<<1];
void dfs(int u){
	if(ban[u])return;
	ban[u]=1;
	each(x,e[u])if(mate[x][0]&&!ban[x]){
		ban[x]=1;
		dfs(mate[x][0]);
	}
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	rd(n1),rd(n2),rd(m),rd(Q);
	atcoder::mf_graph<int>f(n1+n2+2);
	rep(i,1,m){
		int x,y;
		rd(x),rd(y);
		f.add_edge(x,y+n1,1);
	}
	rep(i,1,n1)f.add_edge(0,i,1);
	rep(i,n1+1,n1+n2)f.add_edge(i,n1+n2+1,1);
	f.flow(0,n1+n2+1);
	auto E=f.edges();
	LL ans=0;
	set<int>S;
	auto ps=[&](int x){
		S.insert(x);
		ans+=x;
	};
	auto pop=[&](int x){
		S.erase(x);
		ans-=x;
	};
	auto ID=[&](int x){
		return x<=n1?x:-(x-n1);
	};
	rep(i,0,m-1){
		e[E[i].from].pb(E[i].to);
		e[E[i].to].pb(E[i].from);
		++deg[E[i].from],++deg[E[i].to];
		if(E[i].flow){
			mate[E[i].from][0]=E[i].to;
			mate[E[i].to][0]=E[i].from;
			mate[E[i].from][1]=mate[E[i].to][1]=i+1;
			ps(i+1);
		}
	}
	rep(i,1,n1)if(!ban[i]&&!mate[i][0]){
		dfs(i);
	}
	vector<int>v;
	rep(i,1,n1)if(!ban[i])v.pb(i);
	rep(i,n1+1,n1+n2)if(ban[i])v.pb(i);
	auto del=[&](int u){
		if(mate[u][0]){
			pop(mate[u][1]);
			mate[mate[u][0]][0]=mate[mate[u][0]][1]=0;
			mate[u][0]=mate[u][1]=0;
		}
	};
	rep(i,1,Q){
		int opt;
		scanf("%d",&opt);
		if(opt==1){
			int ret=v.back();
			v.pop_back();
			del(ret);
			printf("1\n%d\n%lld\n",ID(ret),ans);
			fflush(stdout);
		}else{
			printf("%d\n",SZ(S));
			each(x,S)printf("%d ",x);
			puts("");
			fflush(stdout);
		}
	}
	return 0;
}