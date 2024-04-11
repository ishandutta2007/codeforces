//teja349
#include <bits/stdc++.h>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <utility>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <iomanip> 
//setbase - cout << setbase (16); cout << 100 << endl; Prints 64
//setfill -   cout << setfill ('x') << setw (5); cout << 77 << endl; prints xxx77
//setprecision - cout << setprecision (14) << f << endl; Prints x.xxxx
//cout.precision(x)  cout<<fixed<<val;  // prints x digits after decimal in val

using namespace std;
#define f(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) f(i,0,n)
#define fd(i,a,b) for(i=a;i>=b;i--)
#define pb push_back
#define mp make_pair
#define vi vector< int >
#define vl vector< ll >
#define ss second
#define ff first
#define ll long long
#define pii pair< int,int >
#define pll pair< ll,ll >
#define sz(a) a.size()
#define inf (1000*1000*1000+5)
#define all(a) a.begin(),a.end()
#define tri pair<int,pii>
#define vii vector<pii>
#define vll vector<pll>
#define viii vector<tri>
#define mod (1000*1000*1000+7)
#define pqueue priority_queue< int >
#define pdqueue priority_queue< int,vi ,greater< int > >
#define flush fflush(stdout) 
#define primeDEN 727999983
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// Source: e-maxx.ru
// Tested with: VOJ - NKFLOW, VOJ - MCQUERY (Gomory Hu)
// copied from I_love_Hoang_Yen

// Usage:
// MaxFlow flow(n)
// For each edge: flow.addEdge(u, v, c)
// Index from 0

// Tested:
// - https://open.kattis.com/problems/maxflow
const int INF = 1000000000;
 
struct Edge {
    int a, b, cap, flow;
};

vector<vi> vec(1000);
struct MaxFlow {
    int n, s, t;
    vector<int> d, ptr, q;
    vector< Edge > e;
    vector< vector<int> > g;
    int i,j;

    MaxFlow(int n) : n(n), d(n), ptr(n), q(n), g(n) {
        e.clear();
        rep(i,n) {
            g[i].clear();
            ptr[i] = 0;
        }
    }

    void addEdge(int a, int b, int cap) {
        Edge e1 = { a, b, cap, 0 };
        Edge e2 = { b, a, 0, 0 };
        g[a].push_back( (int) e.size() );
        e.push_back(e1);
        g[b].push_back( (int) e.size() );
        e.push_back(e2);
    }
    int getMaxFlow(int _s, int _t) {
        s = _s; t = _t;
        int flow = 0;
        for (;;) {
            if (!bfs()) break;
            rep(i,n) ptr[i] = 0;
            while (int pushed = dfs(s, INF))
                flow += pushed;
        }
        return flow;
    }
    int retrieve(int nn,int mm){
    	int i;

    	rep(i,e.size()){
    		if(e[i].a<nn && nn<=e[i].b && e[i].b<nn+mm && e[i].cap==1 && e[i].flow==1){
    			//cout<<":ve3ef"<<endl;
    			vec[e[i].a].pb(e[i].b-nn);
    		}
    	}
    	return 0;
    }
    
private:
    bool bfs() {
        int qh = 0, qt = 0;
        q[qt++] = s;
        rep(i,n) d[i] = -1;
        d[s] = 0;

        while (qh < qt && d[t] == -1) {
            int v = q[qh++];
            rep(i,g[v].size()) {
                int id = g[v][i], to = e[id].b;
                if (d[to] == -1 && e[id].flow < e[id].cap) {
                    q[qt++] = to;
                    d[to] = d[v] + 1;
                }
            }
        }
        return d[t] != -1;
    }

    int dfs (int v, int flow) {
        if (!flow) return 0;
        if (v == t) return flow;
        for (; ptr[v] < (int)g[v].size(); ++ptr[v]) {
            int id = g[v][ptr[v]],
                to = e[id].b;
            if (d[to] != d[v] + 1) continue;
            int pushed = dfs(to, min(flow, e[id].cap - e[id].flow));
            if (pushed) {
                e[id].flow += pushed;
                e[id^1].flow -= pushed;
                return pushed;
            }
        }
        return 0;
    }
};
int ans[123456];
int deg[1234],u[1234],v[1234];
int solve(){
	int n,m,k;
	cin>>n>>m>>k;
	int i;
	rep(i,n+10){
		vec[i].clear();
		deg[i]=0;
	}
	rep(i,m){
		ans[i]=0;
		cin>>u[i]>>v[i];
		u[i]--;
		v[i]--;
		deg[u[i]]++;
		deg[v[i]]++;
	}
	MaxFlow flowe(n+m+10);
	int needed=0;
	rep(i,n){
		flowe.addEdge(n+m,i,2*max(0,deg[i]-k));
		needed+=2*max(0,deg[i]-k);
	}
	rep(i,m){
		flowe.addEdge(n+i,n+m+1,1);
	}
	rep(i,m){
		flowe.addEdge(u[i],i+n,1);
		flowe.addEdge(v[i],i+n,1);
	}
	int val=flowe.getMaxFlow(n+m,n+m+1);
	if(val!=needed){
		rep(i,m){
			cout<<0<<"  ";
		}
		cout<<endl;
		return 0;
	}
	flowe.retrieve(n,m);
	int counter=2;
	int j;
	//cout<<needed<<endl;
	rep(i,n){
		rep(j,vec[i].size()){
			//cout<<"sads"<<endl;
			//cout<<vec[i][j]<<endl;
			ans[vec[i][j]]=counter/2;
			counter++;
		}
	}
	rep(i,m){
		if(ans[i]==0){
			cout<<counter<<" ";
			counter++;
		}
		else{
			cout<<ans[i]<<" ";
		}
	}
	cout<<endl;

}
int main(){
    std::ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
    	solve();
    }
    return 0;   
}