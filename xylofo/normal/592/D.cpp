#include <map>
#include <set>
#include <stack>
#include <queue>
#include <cmath>
#include <cstdio>
#include <string>
#include <vector>
#include <climits>
#include <cstring>
#include <sstream>
#include <cstdlib>
#include <complex>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define rep(it,st,en) for(int it=(st);it<(int)(en);++it)
#define trav(it,c) for(auto it=(c).begin();it!=(c).end();++it)
#define allof(c) (c).begin(), (c).end()
#define pb push_back
#define mp make_pair
#define X first
#define Y second
typedef long long int ll; 
typedef long double ld;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
const int INF=(int)1e9; 
const double EPS=(ld)1e-7;

vector<set<int> > e;
vi h,dis;

int dfs(int a,int p=-1,int d=0){
    dis[a]=d;
    int m=a;
    for(int b:e[a]) if(b!=p){
       int k=dfs(b,a,d+1);
       if(dis[k]==dis[m])m=min(m,k);
       if(dis[k]>dis[m])m=k;
    }
    return m;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    e.resize(n);
    h.resize(n,0);
    dis.resize(n,0);
    rep(i,0,n-1){
        int a,b;
        cin>>a>>b;
        --a,--b;
        e[a].insert(b);
        e[b].insert(a);
    }
    rep(i,0,m){
        int a;
        cin>>a;
        --a;
        h[a]=1;
    }
    stack<int> q;
    rep(i,0,n)if(e[i].size()==1)q.push(i);
    int nodes=n;
    while(!q.empty()){
        int a=q.top();
        q.pop();
        if(h[a]==0){
            h[a]=-1;
            nodes--;
            int b=*e[a].begin();
            e[b].erase(a);
            if(e[b].size()==1)q.push(b);
        }
    }
    rep(a,0,n){
        if(h[a]==1 && e[a].size()<=1){
            q.push(a);
        }
    }
    vector<set<int> > e2(e);
    int a;
    int aa;
    rep(i,0,n)if(e[i].size()<=1 && h[i]!=-1)q.push(i);
    while(!q.empty()){
        aa=a;
        a=q.top();
        q.pop();
        int b=*e[a].begin();
        e[b].erase(a);
        if(e[b].size()==1)q.push(b);
    }
    e=move(e2);
    int kk=dfs(aa);
    int dd=dis[kk];
    int k=dfs(a);
    int d=dis[k];
    if(d==dd) k=min(k,kk);
    int p=dfs(k);
    cout<<min(k,p)+1<<endl<<2*nodes-2-dis[p]<<endl;
    return 0;
}