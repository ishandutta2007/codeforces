#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize ("Ofast")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;


#define TRACE

#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif

#define rep(i, n)    for(int i = 0; i < (n); ++i)
#define repA(i, a, n)  for(int i = a; i <= (n); ++i)
#define repD(i, a, n)  for(int i = a; i >= (n); --i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define fill(a)  memset(a, 0, sizeof (a))
#define fst first
#define snd second
#define mp make_pair
#define pb push_back
typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> VI;
const int N = 300009;
const int M = 300009;

    VI tree[N]; // The bridge edge tree formed from the given graph
    VI graph[N];int U[M],V[M];  //edge list representation of the graph. 
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

void pre(){


}

void solve(){


}
int mxdist,mxn;
int dist[N];
void dfs(int u,int v){
	trav(i,tree[u]){
		if(i!=v){
			dist[i] = dist[u]+1;
			if(dist[i]>mxdist) mxdist = dist[i],mxn=i;
			dfs(i,u);
		}
	}
}
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	int n,m,q;
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++)
	{
		scanf("%d %d",U+i,V+i);
		graph[U[i]].pb(i);
		graph[V[i]].pb(i);
	}
			dfs0(1,-1);
		
	fill(visited);
			dfs1(1);
	dfs(0,-1);
	int x=mxn;
	fill(dist);
	dfs(x,-1);
	cout<<mxdist;
	return 0;
}