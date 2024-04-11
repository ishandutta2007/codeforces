
// sbctr

#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
//mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
#define fir first
#define sec second
#define mod 998244353
#define ll long long
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
typedef pair<int,int> pii;
void print(vector<int> x){for(int i=0;i<(int)x.size();i++) printf("%d%c",x[i]," \n"[i==(int)x.size()-1]);}
#define N 100005
int a[N],b[N],id[N],n;
ll getval(int x,int id) {return 1LL*x*a[id]+b[id];}


#ifndef ATCODER_INTERNAL_CSR_HPP
#define ATCODER_INTERNAL_CSR_HPP 1

#include <algorithm>
#include <utility>
#include <vector>

namespace atcoder {
namespace internal {

template <class E> struct csr {
    std::vector<int> start;
    std::vector<E> elist;
    csr(int n, const std::vector<std::pair<int, E>>& edges)
        : start(n + 1), elist(edges.size()) {
        for (auto e : edges) {
            start[e.first + 1]++;
        }
        for (int i = 1; i <= n; i++) {
            start[i] += start[i - 1];
        }
        auto counter = start;
        for (auto e : edges) {
            elist[counter[e.first]++] = e.second;
        }
    }
};

}  // namespace internal

}  // namespace atcoder

#endif  // ATCODER_INTERNAL_CSR_HPP

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

#ifndef ATCODER_MINCOSTFLOW_HPP
#define ATCODER_MINCOSTFLOW_HPP 1

#include <algorithm>
#include <cassert>
#include <limits>
#include <queue>
#include <vector>


namespace atcoder {

template <class Cap, class Cost> struct mcf_graph {
  public:
    mcf_graph() {}
    mcf_graph(int n) : _n(n) {}

    int add_edge(int from, int to, Cap cap, Cost cost) {
        assert(0 <= from && from < _n);
        assert(0 <= to && to < _n);
        assert(0 <= cap);
        assert(0 <= cost);
        int m = int(_edges.size());
        _edges.push_back({from, to, cap, 0, cost});
        return m;
    }

    struct edge {
        int from, to;
        Cap cap, flow;
        Cost cost;
    };

    edge get_edge(int i) {
        int m = int(_edges.size());
        assert(0 <= i && i < m);
        return _edges[i];
    }
    std::vector<edge> edges() { return _edges; }

    std::pair<Cap, Cost> flow(int s, int t) {
        return flow(s, t, std::numeric_limits<Cap>::max());
    }
    std::pair<Cap, Cost> flow(int s, int t, Cap flow_limit) {
        return slope(s, t, flow_limit).back();
    }
    std::vector<std::pair<Cap, Cost>> slope(int s, int t) {
        return slope(s, t, std::numeric_limits<Cap>::max());
    }
    std::vector<std::pair<Cap, Cost>> slope(int s, int t, Cap flow_limit) {
        assert(0 <= s && s < _n);
        assert(0 <= t && t < _n);
        assert(s != t);

        int m = int(_edges.size());
        std::vector<int> edge_idx(m);

        auto g = [&]() {
            std::vector<int> degree(_n), redge_idx(m);
            std::vector<std::pair<int, _edge>> elist;
            elist.reserve(2 * m);
            for (int i = 0; i < m; i++) {
                auto e = _edges[i];
                edge_idx[i] = degree[e.from]++;
                redge_idx[i] = degree[e.to]++;
                elist.push_back({e.from, {e.to, -1, e.cap - e.flow, e.cost}});
                elist.push_back({e.to, {e.from, -1, e.flow, -e.cost}});
            }
            auto _g = internal::csr<_edge>(_n, elist);
            for (int i = 0; i < m; i++) {
                auto e = _edges[i];
                edge_idx[i] += _g.start[e.from];
                redge_idx[i] += _g.start[e.to];
                _g.elist[edge_idx[i]].rev = redge_idx[i];
                _g.elist[redge_idx[i]].rev = edge_idx[i];
            }
            return _g;
        }();

        auto result = slope(g, s, t, flow_limit);

        for (int i = 0; i < m; i++) {
            auto e = g.elist[edge_idx[i]];
            _edges[i].flow = _edges[i].cap - e.cap;
        }

        return result;
    }

  private:
    int _n;
    std::vector<edge> _edges;

    // inside edge
    struct _edge {
        int to, rev;
        Cap cap;
        Cost cost;
    };

    std::vector<std::pair<Cap, Cost>> slope(internal::csr<_edge>& g,
                                            int s,
                                            int t,
                                            Cap flow_limit) {
        // variants (C = maxcost):
        // -(n-1)C <= dual[s] <= dual[i] <= dual[t] = 0
        // reduced cost (= e.cost + dual[e.from] - dual[e.to]) >= 0 for all edge

        // dual_dist[i] = (dual[i], dist[i])
        std::vector<std::pair<Cost, Cost>> dual_dist(_n);
        std::vector<int> prev_e(_n);
        std::vector<bool> vis(_n);
        struct Q {
            Cost key;
            int to;
            bool operator<(Q r) const { return key > r.key; }
        };
        std::vector<int> que_min;
        std::vector<Q> que;
        auto dual_ref = [&]() {
            for (int i = 0; i < _n; i++) {
                dual_dist[i].second = std::numeric_limits<Cost>::max();
            }
            std::fill(vis.begin(), vis.end(), false);
            que_min.clear();
            que.clear();

            // que[0..heap_r) was heapified
            size_t heap_r = 0;

            dual_dist[s].second = 0;
            que_min.push_back(s);
            while (!que_min.empty() || !que.empty()) {
                int v;
                if (!que_min.empty()) {
                    v = que_min.back();
                    que_min.pop_back();
                } else {
                    while (heap_r < que.size()) {
                        heap_r++;
                        std::push_heap(que.begin(), que.begin() + heap_r);
                    }
                    v = que.front().to;
                    std::pop_heap(que.begin(), que.end());
                    que.pop_back();
                    heap_r--;
                }
                if (vis[v]) continue;
                vis[v] = true;
                if (v == t) break;
                // dist[v] = shortest(s, v) + dual[s] - dual[v]
                // dist[v] >= 0 (all reduced cost are positive)
                // dist[v] <= (n-1)C
                Cost dual_v = dual_dist[v].first, dist_v = dual_dist[v].second;
                for (int i = g.start[v]; i < g.start[v + 1]; i++) {
                    auto e = g.elist[i];
                    if (!e.cap) continue;
                    // |-dual[e.to] + dual[v]| <= (n-1)C
                    // cost <= C - -(n-1)C + 0 = nC
                    Cost cost = e.cost - dual_dist[e.to].first + dual_v;
                    if (dual_dist[e.to].second - dist_v > cost) {
                        Cost dist_to = dist_v + cost;
                        dual_dist[e.to].second = dist_to;
                        prev_e[e.to] = e.rev;
                        if (dist_to == dist_v) {
                            que_min.push_back(e.to);
                        } else {
                            que.push_back(Q{dist_to, e.to});
                        }
                    }
                }
            }
            if (!vis[t]) {
                return false;
            }

            for (int v = 0; v < _n; v++) {
                if (!vis[v]) continue;
                // dual[v] = dual[v] - dist[t] + dist[v]
                //         = dual[v] - (shortest(s, t) + dual[s] - dual[t]) +
                //         (shortest(s, v) + dual[s] - dual[v]) = - shortest(s,
                //         t) + dual[t] + shortest(s, v) = shortest(s, v) -
                //         shortest(s, t) >= 0 - (n-1)C
                dual_dist[v].first -= dual_dist[t].second - dual_dist[v].second;
            }
            return true;
        };
        Cap flow = 0;
        Cost cost = 0, prev_cost_per_flow = -1;
        std::vector<std::pair<Cap, Cost>> result = {{Cap(0), Cost(0)}};
        while (flow < flow_limit) {
            if (!dual_ref()) break;
            Cap c = flow_limit - flow;
            for (int v = t; v != s; v = g.elist[prev_e[v]].to) {
                c = std::min(c, g.elist[g.elist[prev_e[v]].rev].cap);
            }
            for (int v = t; v != s; v = g.elist[prev_e[v]].to) {
                auto& e = g.elist[prev_e[v]];
                e.cap += c;
                g.elist[e.rev].cap -= c;
            }
            Cost d = -dual_dist[s].first;
            flow += c;
            cost += c * d;
            if (prev_cost_per_flow == d) {
                result.pop_back();
            }
            result.push_back({flow, cost});
            prev_cost_per_flow = d;
        }
        return result;
    }
};

}  // namespace atcoder

#endif  // ATCODER_MINCOSTFLOW_HPP

namespace Flow
{
	struct Edge{int v,cap,nxt;};
	Edge edge[N*2];
	int fir[N],cur[N],ss,dep[N];
	inline void init()
	{
		memset(fir,0,sizeof(fir)); ss=1;
	}
	inline void add(int u,int v,int w)
	{
//		printf("%d %d %d\n",u,v,w);
		edge[++ss]=(Edge){v,w,fir[u]}; fir[u]=ss;
		edge[++ss]=(Edge){u,0,fir[v]}; fir[v]=ss;
	}
	int q[N],l,r;
	int s,t;
	bool bfs()
	{
		for(int i=1;i<=t;i++) dep[i]=0;
		int l=1,r=1; q[1]=s,dep[s]=1;
		while(l<=r)
		{
			int u=q[l++];
			for(int i=fir[u];i!=0;i=edge[i].nxt)
			{
				if(!edge[i].cap) continue;
				int v=edge[i].v;
				if(!dep[v]) dep[v]=dep[u]+1,q[++r]=v;
				if(v==t) return 1;
			}
		}
//		for(int i=1;i<=t;i++) printf("%d%c",dep[i]," \n"[i==t]);
		return dep[t];
	}
	int dfs(int u,int flow)
	{
		if(u==t||flow==0) return flow;
		int ans=0;
		for(int &i=cur[u];i!=0;i=edge[i].nxt)
		{
			if(!edge[i].cap) continue;
			int v=edge[i].v;
			if(dep[v]!=dep[u]+1) continue;
			int go=dfs(v,min(flow,edge[i].cap));
			if(go)
			{
				flow-=go,ans+=go;
				edge[i].cap-=go,edge[i^1].cap+=go;
			}
			if(!flow) return ans;
		}
		return ans;
	}
	int dinic()
	{
		int ans=0;
		while(bfs())
		{
			for(int i=1;i<=t;i++) cur[i]=fir[i];
			ans+=dfs(s,inf);
		}
		return ans;
	}
	/*
	bool chk(int mid)
	{
		init(); s=n*4+1,t=s+1;
		for(int i=1;i<=n;i++) add(s,i,1);
		for(int i=1;i<=n*2;i++) id[i]=i;
		sort(id+1,id+n*2+1,[&](int x,int y){return getval(0,x)>getval(0,y);});
		for(int i=1;i<n*2;i++) add(id[i],id[i+1],inf);
		for(int i=1;i<=n*2;i++)
		{
			int j=i;
			while(getval(0,id[i])==getval(0,id[j+1])) j++;
			if(j!=i) add(id[j],id[i],inf),i=j;
		}
		for(int i=1;i<=n*2;i++) add(i,i+n*2,inf);
		sort(id+1,id+n*2+1,[&](int x,int y){return getval(mid,x)>getval(mid,y);});
		for(int i=1;i<n*2;i++) add(n*2+id[i],n*2+id[i+1],inf);
		for(int i=1;i<=n*2;i++)
		{
			int j=i;
			while(getval(mid,id[i])==getval(mid,id[j+1])) j++;
			if(j!=i) add(n*2+id[j],n*2+id[i],inf),i=j;
		}
		for(int i=n+1;i<=n+n;i++) add(i+n*2,t,1);
		int ans=dinic();
		if(ans==n) return 1;
		else return 0;
	}
	*/
	int cnt[N],id[N],rev[N],premx[N];
	bool chk(int mid)
	{
		for(int i=1;i<=n*2;i++) cnt[i]=0;
		for(int i=1;i<=n*2;i++) id[i]=i;
		sort(id+1,id+n*2+1,[&](int x,int y){return getval(0,x)<getval(0,y);});
		for(int i=1;i<=n*2;i++) rev[id[i]]=i;
		premx[1]=id[1];
		for(int i=2;i<=n*2;i++)
		{
			if(getval(mid,premx[i-1])>getval(mid,id[i])) premx[i]=premx[i-1];
			else premx[i]=id[i];
		}
		for(int i=n*2-1;i>=1;i--) if(b[id[i]]==b[id[i+1]]) premx[i]=premx[i+1];
		for(int i=1;i<=n;i++) cnt[premx[rev[i]]]++;
		for(int i=1;i<=n*2;i++) id[i]=i;
		sort(id+1,id+n*2+1,[&](int x,int y){return getval(mid,x)>getval(mid,y);});
//		for(int i=1;i<=n*2;i++) printf("%d%c",cnt[i]," \n"[i==n*2]);
		int cur=0;
		for(int i=1;i<=n*2;i++)
		{
			cur+=cnt[id[i]];
			if(id[i]>n) cur--;
			while(i<n*2&&getval(mid,id[i])==getval(mid,id[i+1]))
			{
				i++;
				cur+=cnt[id[i]];
				if(id[i]>n) cur--;
			}
			if(cur<0) return 0;
		}
		return 1;
	}
};
namespace COST_FLOW
{
	/*
	struct Edge{int v,w,cap,nxt;};
	Edge edge[N*2];
	int fir[N],ss;
	void init()
	{
		memset(fir,0,sizeof(fir));
		ss=1;
	}
	void add(int u,int v,int w,int c)
	{
//		printf("%d %d %d\n",u,v,w);
		edge[++ss]=(Edge){v,w,c,fir[u]}; fir[u]=ss;
		edge[++ss]=(Edge){u,-w,0,fir[v]}; fir[v]=ss;
	}
	int dis[N],fr[N],fe[N],q[N],vis[N],ql,qr,s,t;
	bool spfa()
	{
		for(int i=1;i<=t;i++) dis[i]=inf;
		dis[s]=0,ql=qr=1,q[1]=s;
		while(ql!=qr+1)
		{
//			if(dis[q[ql]]>dis[q[qr]]) swap(q[ql],q[qr]); 
			int u=q[ql++]; vis[u]=0; if(ql==N) ql=0;
			for(int i=fir[u];i!=0;i=edge[i].nxt)
			{
				if(!edge[i].cap) continue;
				int v=edge[i].v;
				if(dis[v]>dis[u]+edge[i].w)
				{
					dis[v]=dis[u]+edge[i].w;
					fr[v]=u,fe[v]=i;
					if(!vis[v])
					{
						qr++;
						if(qr==N) qr=0;
						vis[v]=1,q[qr]=v;
					}
				}
			}
		}
		return dis[t]!=inf;
	}
	int dinic()
	{
		int ans=0;
		while(spfa())
		{
			int cur=t;
			ans+=dis[t];
			while(cur!=s)
			{
				int ce=fe[cur];
				edge[ce].cap--,edge[ce^1].cap++;
				cur=fr[cur];
			}
		}
		return ans;
	}
	*/
	
	atcoder::mcf_graph<int,int> G(9*4000+5);
	void add(int u,int v,int w,int c)
	{
		G.add_edge(u,v,c,w);
	}
	int get(int mid)
	{
		int s=n*9+1,t=s+1;
		for(int i=1;i<=n;i++) add(s,i,0,1);
		for(int i=1;i<=n*2;i++) id[i]=i;
		sort(id+1,id+n*2+1,[&](int x,int y){return getval(0,x)>getval(0,y);});
		for(int i=1;i<=n*2;i++) add(i,i+n*2,1,1);
		for(int i=1;i<n*2;i++) add(id[i]+n*2,id[i+1]+n*2,0,inf);
		for(int i=1;i<=n*2;i++)
		{
			int j=i;
			while(getval(0,id[i])==getval(0,id[j+1])) j++;
			if(j!=i) add(id[j]+n*2,id[i]+n*2,0,inf),i=j;
		}
		for(int i=1;i<=n*2;i++) add(i,i+n*4,0,inf);
		for(int i=1;i<=n*2;i++) add(i+n*2,i+n*4,0,inf);
		sort(id+1,id+n*2+1,[&](int x,int y){return getval(mid,x)>getval(mid,y);});
		for(int i=1;i<=n*2;i++) add(i+n*4,i+n*6,1,inf);
		for(int i=1;i<n*2;i++) add(n*6+id[i],n*6+id[i+1],0,inf);
		for(int i=1;i<=n*2;i++)
		{
			int j=i;
			while(getval(mid,id[i])==getval(mid,id[j+1])) j++;
			if(j!=i) add(n*6+id[j],n*6+id[i],0,inf),i=j;
		}
		for(int i=n+1;i<=n+n;i++) add(i+n*4,i+n*7,0,1);
		for(int i=n+1;i<=n+n;i++) add(i+n*6,i+n*7,0,1);
		for(int i=n+1;i<=n+n;i++) add(i+n*7,t,0,1);
//		int ans=dinic();
		int ans=G.flow(s,t,n).sec;
		return ans;
	}
};
signed main()
{
	cin>>n;
	for(int i=1;i<=n*2;i++) a[i]=read(),b[i]=read();
	int l=0,r=1e9,ans=-1;
//	cout<<Flow::chk(0)<<endl;
//	return 0;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(Flow::chk(mid)) r=mid-1,ans=mid;
		else l=mid+1;
	}
//	cerr<<clock()<<endl;
	if(ans==-1) return cout<<"-1\n",0;
	cout<<ans<<" ";
	cout<<COST_FLOW::get(ans)<<endl;
	return 0;
}