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
#define pistr pair< int , string >






/*
 * mincostflow implementation. Vertex indices from 0
 * Usage:
 *   for i = 1..N: int v = mcf.addV();
 *   for i = 1..E: MinCostFlow<int,int>::Edge* e = mcf.addEdge(u, v, flow, cost);
 *   mcf.minCostFlow --> return pair<flow, cost>
 * DANGEROUS!!!!!!! If need to find flow through each edge, remember that there can
 * be flow through both (u, v) and (v, u)
 */

//  copied from I_love_Hoang_Yen

// Slow version (Ford Bellman)
// Can work with negative edges. (not loop!)
// Must be careful when used with double.

#define _MAX_COST INT_MAX
#define _MAX_FLOW INT_MAX

template<class Flow = int, class Cost = int>
struct MinCostFlow {
    struct Edge {
        int t;
        Flow f;
        Cost c;
        Edge*next, *rev;
        Edge(int _t, Flow _f, Cost _c, Edge*_next) :
                t(_t), c(_c), next(_next) {
                    f=_f;
        }
    };
    vector<Edge*> E;

    int addV() {
        E.push_back((Edge*) 0);
        return E.size() - 1;
    }
    Edge* makeEdge(int s, int t, Flow f, Cost c) {
        return E[s] = new Edge(t, f, c, E[s]);
    }
    Edge* addEdge(int s, int t, Flow f, Cost c) {
        Edge*e1 = makeEdge(s, t, f, c), *e2 = makeEdge(t, s, 0, -c);
        e1->rev = e2, e2->rev = e1;
        return e1;
    }
    pair<Flow, Cost> minCostFlow(int vs, int vt) {
        int n = E.size();
        Flow flow = 0;
        Cost cost = 0;
        const Cost MAX_COST = _MAX_COST;
        const Flow MAX_FLOW = _MAX_FLOW;
        for (;;) {
            vector<Cost> dist(n, MAX_COST);
            vector<Flow> am(n, 0);
            vector<Edge*> prev(n);
            vector<bool> inQ(n, false);
            queue<int> que;

            dist[vs] = 0;
            am[vs] = MAX_FLOW;
            que.push(vs);
            inQ[vs] = true;

            while (!que.empty()) {
                int u = que.front();
                Cost c = dist[u];
                que.pop();
                inQ[u] = false;
                for (Edge*e = E[u]; e; e = e->next)
                    if (e->f > 0) {
                        Cost nc = c + e->c;
                        if (nc < dist[e->t]) {
                            dist[e->t] = nc;
                            prev[e->t] = e;
                            am[e->t] = min(am[u], e->f);
                            if (!inQ[e->t]) {
                                que.push(e->t);
                                inQ[e->t] = true;
                            }
                        }
                    }
            }

            if (dist[vt] == MAX_COST) // careful with double
                break;
            Flow by = am[vt];
            int u = vt;
            flow += by;
            cost += by * dist[vt];
            while (u != vs) {
                Edge*e = prev[u];
                e->f -= by;
                e->rev->f += by;
                u = e->rev->t;
            }
        }
        return make_pair(flow, cost);
    }
};


//std::ios::sync_with_stdio(false);   
int comp(int a,int b){
    return (a>b);
}
int copm(pistr a,pistr b){
    return (a.ff > b.ff);
}


int n,m;
int b[500];
vector< pistr > vec;
int fulluse(){
    if(m<=n)
        return -1;
  //  cout<<"hii"<<endl;
   // sort(vec.begin(),vec.end(),copm);
    int i,j;
    MinCostFlow<int,int> flowe;

    rep(i,2*m+30){
        flowe.addV();
    }
    //return -1;
    int haha;
    j=0;
    rep(i,m){
        rep(j,n){

            if(vec[j].ff < b[i]){
                if(vec[j].ss[0]=='D'){
                    haha=0;
                }
                else{
                    haha=b[i]-vec[j].ff;
                }
                //cout<<"dasd"<<endl;

                flowe.addEdge(i,j+m+1,1,-1*haha);


            }
            else if(vec[j].ff == b[i] && vec[j].ss[0]=='A'){
                haha=b[i]-vec[j].ff;
                flowe.addEdge(i,j+m+1,1,-1*haha);
            }   
            
        }
        //return -1;
        f(j,n,m){
            //cout<<"dasads";
            haha=b[i];
            flowe.addEdge(i,j+m+1,1,-1*haha);
            //return -1;
        }
    }
    rep(i,m){
        flowe.addEdge(2*m+20,i,1,0);
    }
    rep(j,m){
        flowe.addEdge(j+m+1,2*m+21,1,0);
    }
    //return -1;
    pii lol=flowe.minCostFlow(2*m+20,2*m+21);
    if(lol.ff==m)
        return -1*lol.ss;
    else
        return -1;

    


}
int main(){
    std::ios::sync_with_stdio(false);
    int i,j;
    string str;
    int val;
    cin>>n>>m;
    rep(i,n){
        cin>>str>>val;
        vec.pb(mp(val,str));
    }
    //sort(vec)
    rep(i,m){
        cin>>b[i];
    }
    sort(b,b+m,comp);
    sort(vec.begin(),vec.end());
    int answ=0;
    int cost1=fulluse();
    j=0;
    rep(i,m){
        while( j<n && vec[j].ss[0]=='D'){
            j++;
        }
        if(j==n)
            break;
        if(b[i]<vec[j].ff)
            break;
        answ+=b[i]-vec[j].ff;
        j++;
    }
    //cout<<cost1<<endl;
    cout<<max(answ,cost1)<<endl;

}