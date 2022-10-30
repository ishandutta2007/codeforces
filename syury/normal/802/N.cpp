#include<bits/stdc++.h>

//#pragma GCC optimize("O3")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx") 

using namespace std;

const long long flow_inf = 1e18;

struct FlowEdge{
	int v, u;
	long long cost;
	long long flow = 0;
	long long cap;
	FlowEdge(){}
	FlowEdge(int sv, int su, long long scost, long long scap):v(sv),u(su),cost(scost),cap(scap){}
};

struct MCMF{
	int n;
	vector<vector<FlowEdge> > gr;
	vector<long long> pot;
	vector<int> p;
	queue<int> fb_q;
	vector<int> fb_inq;
	vector<long long> dist;
	set<pair<long long, int> > s;
	long long total_flow = 0;
	long long total_cost = 0;
	void set_n(int sn){
		n = sn;
		gr.resize(n);
		pot.resize(n);
		p.resize(n);
		dist.resize(n);
		fb_inq.resize(n);
	}
	void add_edge(int from, int to, long long cost, long long cap){
		gr[from].push_back(FlowEdge(from, to, cost, cap));
	}
	void ford_bellman(){
		pot.assign(n, flow_inf);
		pot[0] = 0;
		fb_inq.assign(n, false);
		fb_inq[0] = true; fb_q.push(0);
		while(!fb_q.empty()){
			int v = fb_q.front();
			fb_q.pop();
			fb_inq[v] = false;
			for(auto e : gr[v]){
				if(e.cap - e.flow == 0)continue;
				if(pot[e.u] > pot[v] + e.cost){
					pot[e.u] = pot[v] + e.cost;
					if(!fb_inq[e.u]){fb_inq[e.u] = true; fb_q.push(e.u);}
				}
			}
		}
	}
	void dijkstra(){
		dist.assign(n, flow_inf);
		p.assign(n, -1);
		dist[0] = 0;
		s.insert(make_pair(0, 0));
		while(!s.empty()){
			int v = s.begin()->second;
			s.erase(s.begin());
			for(auto e : gr[v]){
				if(e.cap - e.flow == 0)continue;
				long long w = pot[e.u] - pot[v] + e.cost;
				if(dist[e.u] <= dist[v] + w)continue;
				p[e.u] = v;
				s.erase(make_pair(dist[e.u], e.u));
				dist[e.u] = dist[v] + w;
				s.insert(make_pair(dist[e.u], e.u));
			}
		}
		for(int i = 1; i < n; i++)if(p[i] != -1)dist[i] = dist[i] - pot[i] + pot[0];
		pot.swap(dist);
	}
	long long min_cost_flow(long long val, bool need_first_potential = true){
		if(need_first_potential)
			ford_bellman();
		for(int i = 0; i < val; i++){
			dijkstra();
			if(pot[n - 1] == flow_inf)return -flow_inf;
			++total_flow;
			int v = n - 1;
			while(true){
				int pv = p[v];
				if(pv == -1)break;
				for(auto & e : gr[pv])if(e.u == v){e.flow++; if(e.cap != 0)total_cost += e.cost;}
				for(auto & e : gr[v])if(e.u == pv){e.flow--; if(e.cap != 0)total_cost -= e.cost;}
				v = pv;
			}
		}
		return total_cost;
	}
	long long min_cost_max_flow(bool need_first_potential = true){
		if(need_first_potential)
			ford_bellman();
		for(;;){
			dijkstra();
			if(pot[n - 1] == flow_inf)break;
			int v = n - 1;
			long long pushed = flow_inf;
			while(true){
				int pv = p[v];
				if(pv == -1)break;
				for(auto & e : gr[pv])if(e.u == v)pushed = min(pushed, e.cap - e.flow);
				v = pv;
			}
			total_flow += pushed;
			v = n - 1;
			while(true){
				int pv = p[v];
				if(pv == -1)break;
				for(auto & e : gr[pv])if(e.u == v){e.flow += pushed; if(e.cap != 0)total_cost += e.cost * pushed;}
				for(auto & e : gr[v])if(e.u == pv){e.flow -= pushed; if(e.cap != 0)total_cost -= e.cost * pushed;}
				v = pv;
			}
		}
		return total_cost;
	}
};

MCMF solver;

const int MAXN = 2222;

int k, n;
int a[MAXN], b[MAXN];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	scanf("%d%d", &n, &k);
	for(int i = 0; i < n; i++)scanf("%d", &a[i]);
	for(int i = 0; i < n; i++)scanf("%d", &b[i]);
	solver.set_n(n + 2);
	for(int i = 0; i < n; i++){
		solver.add_edge(0, i + 1, a[i], 1);
		solver.add_edge(i + 1, 0, -a[i], 0);
		solver.add_edge(i + 1, n + 1, b[i], 1);
		solver.add_edge(n + 1, i + 1, -b[i], 0);
		if(i < n - 1)solver.add_edge(i + 1, i + 2, 0, 1<<12);
		if(i > 0)solver.add_edge(i + 1, i, 0, 0);
	}
	printf("%lld", solver.min_cost_flow(k));
	return 0;
}