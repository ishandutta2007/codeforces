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
//cout<<fixed<<setprecision(15)<<ans;
 
template <typename T>
void printvec(vector<T>& vec){
	for(int i=0;i<vec.size();i++){
		cout<<vec[i]<<" ";
	}
	cout<<endl;
}

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


ll n,m;
int valid(int p,int q){
	if(p<0 || p>=n || q<0 || q>=m)
		return 0;
	return 1;
}
int a[12];
int edg[1234][1234];
int solve(){
    //std::ios::sync_with_stdio(false);  

    a[0]=1;
    a[1]=-1;
    int i,j,k,l,p,q;
    rep(i,n*m){
    	rep(j,n*m){
    		edg[i][j]=0;
    	}
    }
    MaxFlow flowe(n*m+20);
    rep(i,n){
    	rep(j,m){
    		rep(k,4){
    			l=3-k;
    			rep(p,2){
    				rep(q,2){

    					if(valid(i+k*a[p],j+l*a[q]) && !edg[i*m+j][(i+k*a[p])*m + j+l*a[q]]){
    						edg[i*m+j][(i+k*a[p])*m + j+l*a[q]]=1;
    						edg[(i+k*a[p])*m + j+l*a[q]][i*m+j]=1;
    						if((i+j)%2==1)
    							flowe.addEdge(i*m+j,(i+k*a[p])*m + j+l*a[q],1);
    						else
    							flowe.addEdge((i+k*a[p])*m + j+l*a[q],i*m+j,1);
    					}
    				}
    			}
    		}
    		if((i+j)%2)
    			flowe.addEdge(n*m,i*m+j,1);
    		else
    			flowe.addEdge(i*m+j,n*m+1,1);
    	}
    }
    int val=flowe.getMaxFlow(n*m,n*m+1);
    
    return val*2;   
}

int main(){
	cin>>n>>m;
	if(n>m){
		swap(n,m);
	}
	int i,j;
	ll ans;
	

	//cout<<solve()<<endl;
	//return 0;
	//ll ans=0;
	if(n==1){
		ans=(m/6)*6;
		m%=6;
		if(m>3){
			ans+=(m-3)*2;
		}
		cout<<ans<<endl;
	}
	else{
		if(m<24){
			cout<<solve()<<endl;
		}
		else{

			ans=n*m;
			if(ans%2)
				ans--;
			cout<<ans<<endl;
		}
	}


}