#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

#include <bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define REP(i,n) for (int i = 0; i < n; i++)
#define FOR(i,a,b) for (int i = a; i < b; i++)
#define all(v) v.begin(),v.end()
typedef map<int,int> mii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
#define F first
#define S second
#define PQ(type) priority_queue<type>
#define PQD(type) priority_queue<type,vector<type>,greater<type> >
#define WL(t) while(t --)
#define SZ(x) ((int)(x).size())
#define runtime() ((double)clock() / CLOCKS_PER_SEC)
#define inrange(i,a,b) ((i>=min(a,b)) && (i<=max(a,b)))
 
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

void solvethetestcase();
 
signed main(){
    // comment when using scanf,printf
    FAST_IO
    int t = 1;
    // (UNCOMMENT FOR MULTIPLE TEST CASES)
    cin >> t;
    FOR(testcase,1,t+1){
        // (UNCOMMENT FOR CODEJAM)
        // printf("Case #%lld: ",testcase); 
        solvethetestcase();
    }
}   
 
int n,m,k;
int deg[100005];
 
void solvethetestcase(){
    cin >> n >> m >> k;
    unordered_set<int> adj[n+1];
    REP(i,n+1){
        deg[i] = 0;
    }
    REP(i,m){
        int u,v; cin >> u >> v;
        adj[u].insert(v);
        adj[v].insert(u);
        deg[u]++;
        deg[v]++;
    }
    if(((k)*(k-1))/2 > m){
        cout << "-1\n";
        return;
    }
    set<pii> s;
    FOR(i,1,n+1) s.insert({deg[i],i});
    while(SZ(s)){
        int u = (*s.begin()).S;
        if(deg[u] >= k){
            cout << "1 " << SZ(s) << "\n";
            for(auto x:s) cout << x.S << " ";
            cout << "\n";
            return;
        }
        if(deg[u] == k-1){
            vi vert;
            for(auto x:adj[u]) vert.pb(x);
            bool f = 1;
            REP(i,SZ(vert)){
                FOR(j,i+1,SZ(vert)){
                    if(adj[vert[i]].find(vert[j]) == adj[vert[i]].end()){
                        f = 0;
                        break;
                    }
                }
                if(!f) break;
            }
            if(f){
                cout << "2\n";
                for(auto x:vert) cout << x << " ";
                cout << u << "\n";
                return;
            }
        }
        for(auto v:adj[u]){
            adj[v].erase(u);
            s.erase({deg[v],v});
            deg[v]--;
            s.insert({deg[v],v});
        }
        adj[u].clear();
        s.erase({deg[u],u});
        deg[u] = 0;
    }
    cout << "-1\n";
}