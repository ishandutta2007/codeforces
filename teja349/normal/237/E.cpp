
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

//std::ios::sync_with_stdio(false);   


// Source: rng_58: http://codeforces.com/contest/277/submission/3212642
// Fast min cost max floweee (Dijkstra)
// Index from 0
// NOTE!!!!!! Flow through both direction can be < 0
// --> need to be careful when trace
// Does not work when cost < 0

#define F_INF 1000111000LL
#define C_INF 1000111000LL

template<class Flow = long long, class Cost = long long>
struct MinCostFlow {
    int V, E,i;
    vector<Flow> cap;
    vector<Cost> cost;
    vector<int> to, prev;

    vector<Cost> dist, pot;
    vector<int> last, path, used;
    priority_queue< pair<Cost, int> > q;

    MinCostFlow(int V, int E) : V(V), E(0), cap(E*2,0), cost(E*2,0), to(E*2,0), prev(E*2,0),
            dist(V,0), pot(V,0), last(V, -1), path(V,0), used(V,0) {}

    int addEdge(int x, int y, Flow f, Cost c) {
        cap[E] = f; cost[E] = c; to[E] = y; prev[E] = last[x]; last[x] = E; E++;
        cap[E] = 0; cost[E] = -c; to[E] = x; prev[E] = last[y]; last[y] = E; E++;
        return E - 2;
    }

    pair<Flow, Cost> search(int s, int t) {
        Flow ansf = 0; Cost ansc = 0;
        rep(i,V) used[i] = false;
        rep(i,V) dist[i] = C_INF;

        dist[s] = 0; path[s] = -1; q.push(make_pair(0, s));
        while (!q.empty()) {
            int x = q.top().second; q.pop();
            if (used[x]) continue; used[x] = true;
            for(int e = last[x]; e >= 0; e = prev[e]) if (cap[e] > 0) {
                Cost tmp = dist[x] + cost[e] + pot[x] - pot[to[e]];
                if (tmp < dist[to[e]] && !used[to[e]]) {
                    dist[to[e]] = tmp;
                    path[to[e]] = e;
                    q.push(make_pair(-dist[to[e]], to[e]));
                }
            }
        }
        rep(i,V) pot[i] += dist[i];
        if (used[t]) {
            ansf = F_INF;
            for(int e=path[t]; e >= 0; e=path[to[e^1]]) ansf = min(ansf, cap[e]);
            for(int e=path[t]; e >= 0; e=path[to[e^1]]) { ansc += cost[e] * ansf; cap[e] -= ansf; cap[e^1] += ansf; }
        }
        return make_pair(ansf, ansc);
    }
    pair<Flow, Cost> minCostFlow(int s, int t) {
        Flow ansf = 0; Cost ansc = 0;
        while (1) {
            pair<Flow, Cost> p = search(s, t);
            if (!used[t]) break;
            ansf += p.first; ansc += p.second;
        }
        return make_pair(ansf, ansc);
    }
};







string s[123];
int a[123],arr[100];
int main(){
    std::ios::sync_with_stdio(false);
    string t;
    cin>>t;
    int n,i,j;
    cin>>n;
    rep(i,n){
    	cin>>s[i]>>a[i];
    }
    MinCostFlow<ll ,ll> floweee(n+100,30*n+100);
    rep(i,t.length()){
    	arr[t[i]-'a']++;
    }
    rep(i,26){
    	floweee.addEdge(0,i+1,arr[i],0);
    }
    rep(i,n){
    	rep(j,30){
    		arr[j]=0;
    	}
    	rep(j,s[i].length()){
    		arr[s[i][j]-'a']++;
    	}
    	rep(j,26){
    		floweee.addEdge(j+1,50+i,arr[j],0);
    	}

    	floweee.addEdge(50+i,50+n+10,a[i],i+1);
    }
    pll papa=floweee.minCostFlow(0,n+60);
    if(papa.ff!=t.length())
    	papa.ss=-1;
    cout<<papa.ss<<endl;

    return 0;  
    
}