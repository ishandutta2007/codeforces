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
//setprecision - cout << setprecision (4) << f << endl; Prints x.xxxx


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

//std::ios::sync_with_stdio(false);   

int arr[110][110]={0},lol;
// Source: e-maxx.ru
// Tested with: VOJ - NKFLOW, VOJ - MCQUERY (Gomory Hu)
// copied from I_love_Hoang_Yen
// Usage:
// MaxFlow flow(n)
// For each edge: flow.addEdge(u, v, c, edge_id)
// flow.getMaxFlow(s, t)
// flow.trace()
// Index from 0

// Tested:
// - https://open.kattis.com/problems/maxflow
const int INF = 100011100;
 
struct Edge {
    int a, b, cap, flow, id;
};

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

    void addEdge(int a, int b, int cap, int id) {
        Edge e1 = { a, b, cap, 0, id };
        Edge e2 = { b, a, 0, 0, id };
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

    int trace() {
       // bfs();
    	j=0;
        rep(i,lol){
        	//cout<<e[j].flow<<endl;
        	arr[e[j].a][e[j].b]+=e[j].flow;
        	//cout<<arr[e[j].a][e[j].b]<<endl;
        	j+=2;
        }
        
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




int a[500],b[500];
int main(){
	std::ios::sync_with_stdio(false);
	int n,m,i,j;
	cin>>n>>m;
	int lala=0,yorr=0;
	MaxFlow flow(n*2+30);
	rep(i,n){
		cin>>a[i];
		lala+=a[i];
		flow.addEdge(i,i+n+1,400,i);
	}
	
	rep(i,n){
		cin>>b[i];
		yorr+=b[i];
	}
	if(lala!=yorr)
	{
		cout<<"NO"<<endl;
		return 0;
	}
	int u,v;
	rep(i,m){
		cin>>u>>v;
		u--;
		v--;
		//haha.pb(mp(u,v));
		flow.addEdge(u,v+n+1,400,i);
		flow.addEdge(v,u+n+1,400,i);
	}
	lol=2*m+n;
	rep(i,n){
		flow.addEdge(2*n+20,i,a[i],i);
		flow.addEdge(i+n+1,2*n+21,b[i],i);
	}
	int val=flow.getMaxFlow(2*n+20,2*n+21);
	if(val!=lala){
		cout<<"NO"<<endl;
		return 0;
	}
	cout<<"YES"<<endl;
	flow.trace();
	rep(i,n){
		rep(j,n){
			cout<<arr[i][j+n+1]<<" ";
		}
		cout<<endl;
	}

}