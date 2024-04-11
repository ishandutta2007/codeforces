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


//std::ios::sync_with_stdio(false);   
int c[123],p[123],l[123];
int pr[223456];
vii vec;
int check(int mid){
	int i,sumi=0,j;
	vi po,pe,ce,co;
	int maxi=-1,valed,val;
	rep(i,vec.size()){
		if(vec[i].ff>mid){
			break;
		}
		else{
			val=vec[i].ss;
			if(c[val]==1){
				if(p[val]>maxi){
					valed=val;
					maxi=p[val];
				}
			}
			else if(c[val]%2){
				po.pb(p[val]);
				co.pb(c[val]);
				sumi+=p[val];
			}
			else{
				pe.pb(p[val]);
				ce.pb(c[val]);
				sumi+=p[val];
			}
			
		}
	}
	if(maxi!=-1){
		po.pb(p[valed]);
		co.pb(c[valed]);
		sumi+=p[valed];
	}

	MaxFlow flow(500);
	int n=co.size();
	int m=ce.size(); 
	rep(i,co.size()){
		rep(j,ce.size()){
			if(pr[co[i]+ce[j]]==0){
				flow.addEdge(i,j+n,po[i]+pe[j]);
			}
		}
	}
	rep(i,co.size()){
		flow.addEdge(n+m,i,po[i]);
	}
	rep(i,ce.size()){
		flow.addEdge(i+n,n+m+1,pe[i]);
	}
	val=flow.getMaxFlow(n+m,n+m+1);
	return sumi-val;
}

int main(){
    std::ios::sync_with_stdio(false);
    int n,k;
    cin>>n>>k;
    int i,j;
    for(i=2;i*i<=200002;i++){
    	if(pr[i])
    		continue;
    	for(j=i*i;j<=200002;j+=i){
    		pr[j]=1;
    	}
    }


    rep(i,n){
    	cin>>p[i]>>c[i]>>l[i];
    	vec.pb(mp(l[i],i));
    }
    sort(vec.begin(),vec.end());
    int low=1;
    int high=n;
    int mid,ans=-1;
    while(low<=high){
    	mid=(low+high)/2;
    	if(check(mid)>=k){
    		ans=mid;
    		high=mid-1;
    	}
    	else
    		low=mid+1;
    }
    cout<<ans<<endl;
    
}