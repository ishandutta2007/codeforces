
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

//std::ios::sync_with_stdio(false);






//BRIDGE tree taken from tanujs blog post.....



const int N = 312345;
const int M = 312345;
vector<vi> tree(N); // The bridge edge tree formed from the given graph
vector<vi> graph(N);int U[M],V[M];  //edge list representation of the graph. 
bool isbridge[M]; // if i'th edge is a bridge edge or not 
int visited[N];int arr[N],T; //supporting arrays
int cmpno;
queue<int> Q[N];
 
int adj(int u,int e){
    return U[e]==u?V[e]:U[e];
}
int dfs0(int u,int edge)    //marks all the bridges
{
    visited[u]=1;
    arr[u]=T++;
    int dbe = arr[u];
    for(int i=0;i<(int)graph[u].size();i++)
    {
        int e = graph[u][i];
        int w = adj(u,e);
        if(!visited[w])
            dbe = min(dbe,dfs0(w,e));
        else if(e!=edge)
            dbe = min(dbe,arr[w]);
    }
    if(dbe == arr[u] && edge!=-1)
        isbridge[edge]=true;
    return dbe;
}
 
void dfs1(int v) //Builds the tree with each edge a bridge from original graph
{
    int currcmp = cmpno;    // current component no.
    Q[currcmp].push(v);    // A different queue for each component, coz   during bfs we shall go to another component (step of dfs) and then come   back to this one and continue our bfs
    visited[v]=1;
    while(!Q[currcmp].empty())    //bfs. Exploring all nodes of this  component
    {
        int u = Q[currcmp].front();    
        Q[currcmp].pop();    
        for(int i=0;i<(int)graph[u].size();i++)
        {
            int e = graph[u][i];
            int w = adj(u,e);
            if(visited[w])continue;
            //if the edge under consideration is bridge and
            //other side is not yet explored, go there (step of dfs)
            if(isbridge[e])
            {
                cmpno++;
                tree[currcmp].push_back(cmpno);
                tree[cmpno].push_back(currcmp);
                dfs1(w);
            }
            else     //else continue with our bfs
            {
                Q[currcmp].push(w);
                visited[w]=1;
            }
        }
    }
}

int farthest=0;
int node=0;
int dfs2(int cur,int par,int lev){
    int i;
    if(lev>farthest){
        node=cur;
        farthest=lev;
    }
    rep(i,tree[cur].size()){
        if(tree[cur][i]!=par){
            dfs2(tree[cur][i],cur,lev+1);
        }
    }
    return 0;
}
int main(){
    std::ios::sync_with_stdio(false);
    int i;
    int n,m;
    cin>>n>>m;
    int root=1;
    rep(i,m){
        cin>>U[i]>>V[i];
        graph[U[i]].pb(i);
        graph[V[i]].pb(i);
    }
    dfs0(root,-1);
    for(int i=1;i<=n;i++)
        visited[i]=0;
    dfs1(root);
    dfs2(root,-1,0);
    int wow=node;
    farthest=0;
    dfs2(wow,-1,0);
    cout<<farthest<<endl;

}