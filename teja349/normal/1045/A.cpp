
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

struct MaxFlow {
    int n, s, t;
    vector<int> d, ptr, q;
    vector< Edge > e;
    vector< vector<int> > g;
    vi visit;
    int i,j;
    int ver1,ver2;
    MaxFlow(int n) : n(n), d(n), ptr(n), q(n), g(n),visit(n) {
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
    pii getsomepath(){
    	int i;
    	rep(i,n){
			visit[i]=0;
		}
    	int val=dodfs(s);
    	assert(val==1);
    	return mp(ver1,ver2);
    }
private:
	int dodfs(int cur){
		if(cur==t){
			return 1;
		}
		//cout<<cur<<endl;
		//visit[cur]=1;
		int i;
		int ed,to;
		rep(i,g[cur].size()){
			ed=g[cur][i];
			to=e[ed].b;
			if(!visit[to] && e[ed].flow>0){
				//cout<<cur<<" "<<to<<" "<<ed<<" "<<e[ed].flow<<" "<<e[ed].cap<<endl;
				int val=dodfs(to);
				if(val){
					e[ed].flow--;
					if(cur==s){
						ver1=to;
					}
					if(to==t){
						ver2=cur;
					}
					return 1;
				}		

			}
		}
		return 0;
	}
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
int haha[123456];
MaxFlow flowe(25100);
int s,t;
int dfs(int node,int s,int e){
	if(s==e){
		flowe.addEdge(node,t,1);
		haha[node]=s;
		return 0;
	}
	int mid=(s+e)/2;
	flowe.addEdge(node,2*node,inf);
	flowe.addEdge(node,2*node+1,inf);
	dfs(2*node,s,mid);
	dfs(2*node+1,mid+1,e);
	return 0;
}
int addtorange(int node,int s,int e,int l,int r,int gg){
	if(l<=s && e<=r){
		flowe.addEdge(gg,node,inf);
		return 0;
	}
	if(e<l || r<s)
		return 0;
	int mid=(s+e)/2;
	addtorange(2*node,s,mid,l,r,gg);
	addtorange(2*node+1,mid+1,e,l,r,gg);
	return 0;
}
vector<vi> vec(12345);
int ty[12345],wow[12345],cnt[12345];
int main(){
    std::ios::sync_with_stdio(false); cin.tie(NULL);
	int n,m;
	cin>>n>>m;
	int segnodes = 4*m+20;
	int i,j;
	s=4*m+n+22;
	t=4*m+n+23;
	dfs(1,0,m-1);
	//return 0;
	int typ,k,l,r,val;
	rep(i,n){
		cin>>typ;
		ty[i]=typ;
		if(typ==0){
			k;
			cin>>k;
			rep(j,k){
				cin>>val;
				val--;
				addtorange(1,0,m-1,val,val,segnodes+i);
			}
			flowe.addEdge(s,segnodes+i,1);

		}
		else if(typ==1){
			int l,r;
			cin>>l>>r;
			l--;
			r--;
			addtorange(1,0,m-1,l,r,segnodes+i);
			flowe.addEdge(s,segnodes+i,1);
		}
		else{
			cin>>l>>r>>k;
			l--;
			r--;
			k--;
			vec[i].pb(l);
			vec[i].pb(r);
			vec[i].pb(k);
			addtorange(1,0,m-1,k,k,segnodes+i);
			addtorange(1,0,m-1,r,r,segnodes+i);
			addtorange(1,0,m-1,l,l,segnodes+i);
			flowe.addEdge(s,segnodes+i,2);
		}
	}
	val=flowe.getMaxFlow(s,t);
	cout<<val<<endl;
	//return 0;
	pii papa;
	int ver1,ver2;
	rep(i,m+2){
		wow[i]=-1;
	}
	rep(i,val){

		papa=flowe.getsomepath();
		//cout<<i<<endl;
		ver1=papa.ff;
		ver1-=segnodes;
		ver2=papa.ss;
		ver2=haha[ver2];
		//cout<<ver2<<" "<<ver1<<endl;
		wow[ver2]=ver1;
		cnt[ver1]++;
	}
	
	rep(i,n){
		if(ty[i]==2 && cnt[i]==1){
			l=vec[i][0];
			r=vec[i][1];
			k=vec[i][2];
			if(wow[l]!=i){
				wow[l]=i;
				continue;
			}
			l=r;
			if(wow[l]!=i){
				wow[l]=i;
				continue;
			}
			l=k;
			if(wow[l]!=i){
				wow[l]=i;
				continue;
			}
		}
	}
	rep(i,m){
		//cout<<wow[i]<<endl;
		if(wow[i]!=-1){
			cout<<wow[i]+1<<" "<<i+1<<endl;
		}
	}
    return 0;   
}