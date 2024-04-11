#include <map>
#include <set>
#include <stack>
#include <list>
#include <queue>
#include <cmath>
#include <cstdio>
#include <string>
#include <vector>
#include <climits>
#include <cstring>
#include <sstream>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define FOR(it,st,en) for(int it=(st);it<(int)(en);++it)
#define REP(it,en) FOR(it,0,en)
#define ITE(it,c) for(auto it=(c).begin();it!=(c).end();++it)
#define ALLOF(c) (c).begin(), (c).end()
#define PB push_back
#define MP make_pair
#define X first
#define Y second
typedef long long int LL; 
typedef long double LD;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int,int> PII;
const int INF=(int)1e9; 
const double EPS=(LD)1e-7;

struct edge{
    int to;
    bool sign;
    int ind;
    list<edge>::iterator rev; 
    edge(int a, bool b,int c):to(a),sign(b),ind(c){};
};

vector<list<edge> > g;
VI states;
VI pushed,popped;
queue<int> fixes;

void fix(int x){
    for(edge e:g[x]){
        g[e.to].erase(e.rev);
        states[e.ind]=(e.sign?-1:1);
        if(!pushed[e.to])fixes.push(e.to),pushed[e.to]=true;
    }
    popped[x]=true;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m; //n,m confusion
    cin>>m>>n;
    VI on(n,-1);
    VI off(n,-1);
    states.resize(n);
    pushed.resize(m,false);
    popped.resize(m,false);
    REP(i,m){
        int a,b;
        cin>>a;
        REP(j,a){
            cin>>b;
            if(b>0){
                b--;
                if(on[b]!=-1){
                    states[b]=1;
                    if(!pushed[i])fixes.push(i),pushed[i]=true;
                    if(!pushed[on[b]])fixes.push(on[b]),pushed[on[b]]=true;
                    on[b]=-1;
                }
                else on[b]=i;
            }
            else{
                b=-b-1;
                if(off[b]!=-1){
                    states[b]=-1;
                    if(!pushed[i])fixes.push(i),pushed[i]=true;
                    if(!pushed[off[b]])fixes.push(off[b]),pushed[off[b]]=true;
                    off[b]=-1;
                }
                else off[b]=i;
            }
        }
    }
    g.resize(m);
    REP(i,n){
        if(!states[i]){
            if(on[i]==-1 && off[i]==-1)continue;
            if(on[i]==off[i]){
                states[i]=1;
                if(!pushed[off[i]])fixes.push(off[i]),pushed[off[i]]=true;
                continue;
            }
            if(on[i]==-1){
                states[i]=-1;
                if(!pushed[off[i]])fixes.push(off[i]),pushed[off[i]]=true;
                continue;
            }
            if(off[i]==-1){
                states[i]=1;
                if(!pushed[on[i]])fixes.push(on[i]),pushed[on[i]]=true;
                continue;
            }
            g[on[i]].push_back(edge(off[i],true,i));
            g[off[i]].push_back(edge(on[i],false,i));
            g[on[i]].back().rev=(--g[off[i]].end());
            g[off[i]].back().rev=(--g[on[i]].end());
        }
    }

    queue<int> pre;
    REP(i,m){
        if(g[i].size()==1 && !pushed[i])pre.push(i);
    }
    while(!pre.empty()){
        int i=pre.front();
        pre.pop();
        if(g[i].size()==0){
            cout<<"NO"<<endl;
            //cout<<i<<endl;
            //REP(i,n)cout<<states[i]<<" ";
            //cout<<endl;
            return 0;
        }
        edge& e = g[i].back();
        g[e.to].erase(e.rev);
        states[e.ind]=(e.sign?1:-1);
        if(g[e.to].size()==1 && !pushed[e.to])pre.push(e.to);
        g[i].pop_back();
        fixes.push(i),pushed[i]=true;
    }
    REP(i,m){
        while(!fixes.empty()){
            fix(fixes.front());
            fixes.pop();
        }
        if(popped[i])continue;
        if(g[i].size()==0){
            cout<<"NO"<<endl;
            //cout<<i<<endl;
            //REP(i,n)cout<<states[i]<<" ";
            //cout<<endl;
            return 0;
        }
        edge& e = g[i].back();
        g[e.to].erase(e.rev);
        states[e.ind]=(e.sign?1:-1);
        g[i].pop_back();
        fixes.push(i),pushed[i]=true;
    }
    cout<<"YES"<<endl;
    REP(i,n)cout<<(states[i]==1);
    cout<<endl;
	return 0;
    cout<<endl;
}