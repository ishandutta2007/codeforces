#include <bits/stdc++.h>
using namespace std;

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
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
vi stk,cyl;
bool visited[509],recStack[509];
class Graph
{
    int V;    // No. of vertices
    vector<vi> adj;    // Pointer to an array containing adjacency lists
    bool isCyclicUtil(int v);  // used by isCyclic()
public:
    Graph(int V);   // Constructor
    void addEdge(int v, int w);   // to add an edge to graph
    bool isCyclic();    // returns true if there is a cycle in this graph
};
 
Graph::Graph(int V)
{
	adj.resize(V);
}
 
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to vs list.
}
 
// This function is a variation of DFSUytil() in https://www.geeksforgeeks.org/archives/18212
bool Graph::isCyclicUtil(int v)
{
    if(visited[v] == false)
    {
        // Mark the current node as visited and part of recursion stack
        visited[v] = true;
        recStack[v] = true;
        stk.pb(v);
 
        // Recur for all the vertices adjacent to this vertex
        for(auto i = adj[v].begin(); i != adj[v].end(); ++i)
        {
            if ( !visited[*i] && isCyclicUtil(*i))
                return true;
            else if (recStack[*i]){
            	cyl.pb(*i);
            	while(stk.back()!=*i) cyl.pb(stk.back()),stk.pop_back();
            	cyl.pb(stk.back());
                return true;
            }
        }
    stk.pop_back();
 
    }
    recStack[v] = false;  // remove the vertex from recursion stack
    return false;
}
 
// Returns true if the graph contains a cycle, else false.
// This function is a variation of DFS() in https://www.geeksforgeeks.org/archives/18212
int n,m;
bool Graph::isCyclic()
{
    fill(visited);fill(recStack);
    for(int i = 0; i < n+1; i++){
        if (isCyclicUtil(i))
            return true;
	}
    return false;
}
pii edges[100009];
bool check(pii z){
	cyl.clear();
	stk.clear();
	Graph g(n+1);
	rep(i,m){
		if(edges[i]!=z) g.addEdge(edges[i].fst,edges[i].snd);
	}
	return g.isCyclic();
}
vi ans;
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	cin>>n>>m;
	rep(i,m) cin>>edges[i].fst>>edges[i].snd;
	pii z = mp(-1,-1);
		if(!check(z)) {cout<<"YES"<<endl;return 0;}
	ans = cyl;
	bool f = false;
	rep(i,sz(ans)-1){
		z = mp(ans[i+1],ans[i]);
		if(!check(z)) {cout<<"YES"<<endl;f = true;break;}
	}
	if(!f) cout<<"NO";
	return 0;
}