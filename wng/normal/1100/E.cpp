#include <bits/stdc++.h>
typedef long long LL;
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define RI(X) scanf("%d", &(X))
#define RII(X, Y) scanf("%d%d", &(X), &(Y))
#define RIII(X, Y, Z) scanf("%d%d%d", &(X), &(Y), &(Z))
#define DRI(X) int (X); scanf("%d", &X)
#define DRII(X, Y) int X, Y; scanf("%d%d", &X, &Y)
#define DRIII(X, Y, Z) int X, Y, Z; scanf("%d%d%d", &X, &Y, &Z)
#define RS(X) scanf("%s", (X))
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
#define MP make_pair
#define PB push_back
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define LEN(X) strlen(X)
#define PII pair<int,int>
#define VI vector<int>
#define VL vector<long long>
#define VPII vector<pair<int,int> >
#define PLL pair<long long,long long>
#define VPLL vector<pair<long long,long long> >
#define F first
#define S second

// A C++ Program to detect cycle in a graph 
#include<iostream> 
#include <list> 
#include <limits.h> 
  
using namespace std; 
  
class Graph 
{ 
    int V;    // No. of vertices 
    list<int> *adj;    // Pointer to an array containing adjacency lists 
    bool isCyclicUtil(int v, bool visited[], bool *rs);  // used by isCyclic() 
public: 
    Graph(int V);   // Constructor 
    void addEdge(int v, int w);   // to add an edge to graph 
    bool isCyclic();    // returns true if there is a cycle in this graph 
}; 
  
Graph::Graph(int V) 
{ 
    this->V = V; 
    adj = new list<int>[V]; 
} 
  
void Graph::addEdge(int v, int w) 
{ 
    adj[v].push_back(w); // Add w to vs list. 
} 
  
// This function is a variation of DFSUytil() in https://www.geeksforgeeks.org/archives/18212 
bool Graph::isCyclicUtil(int v, bool visited[], bool *recStack) 
{ 
    if(visited[v] == false) 
    { 
        // Mark the current node as visited and part of recursion stack 
        visited[v] = true; 
        recStack[v] = true; 
  
        // Recur for all the vertices adjacent to this vertex 
        list<int>::iterator i; 
        for(i = adj[v].begin(); i != adj[v].end(); ++i) 
        { 
            if ( !visited[*i] && isCyclicUtil(*i, visited, recStack) ) 
                return true; 
            else if (recStack[*i]) 
                return true; 
        } 
  
    } 
    recStack[v] = false;  // remove the vertex from recursion stack 
    return false; 
} 
  
// Returns true if the graph contains a cycle, else false. 
// This function is a variation of DFS() in https://www.geeksforgeeks.org/archives/18212 
bool Graph::isCyclic() 
{ 
    // Mark all the vertices as not visited and not part of recursion 
    // stack 
    bool *visited = new bool[V]; 
    bool *recStack = new bool[V]; 
    for(int i = 0; i < V; i++) 
    { 
        visited[i] = false; 
        recStack[i] = false; 
    } 
  
    // Call the recursive helper function to detect cycle in different 
    // DFS trees 
    for(int i = 0; i < V; i++) 
        if (isCyclicUtil(i, visited, recStack)) 
            return true; 
  
    return false; 
} 
  
 
vector<pair<int,PII>> c;
int n,m;

vector<set<int>> cs;
VI ved;
VI ving;
VI L;

bool dfs(int i){
	ving[i]=1;
	bool tr=true;
	for (auto c:cs[i]){
		if (ving[c]) {return false;}
		if (!ved[c]) {tr&=dfs(c);}
	}
	ving[i]=0;
	ved[i]=true;
	L.PB(i);
	return tr;
}


bool test(int k){
	Graph g(n);
	REP(i,m) {
		if (c[i].F>k) g.addEdge(c[i].S.F,c[i].S.S);
	}
	return !g.isCyclic();
}
  
int main() 
{ 
	RII(n,m);
	cs =vector<set<int>>(n);
	REP(i,m){
		DRIII(x,y,z);
		c.PB({z,{x-1,y-1}});
	}
	int res=-1;
	int tt=1<<30;
	while (tt){
		if (!test(res+tt)) res+=tt;
		tt>>=1;
	}
	res++;
	//printf("%d\n",res);
	
	REP(i,m){
		if (c[i].F>res) cs[c[i].S.F].insert(c[i].S.S);
	}
	ved=VI(n);
	ving=VI(n);
	REP(i,n){
		if (!ved[i]){
			assert(dfs(i));
		}
	}
	reverse(L.begin(),L.end());
//	for (auto i:L){ cout<<i<<" ";} cout<<endl;
	VI toreverse;
	VI rank(n);
	REP(i,n){
		rank[L[i]]=i;
	}
	int nbtr=0;
	REP(i,m){
		if (rank[c[i].S.F]>rank[c[i].S.S]) {
			toreverse.PB(i+1);
			nbtr++;
		}
	}
	printf("%d %d\n",res,nbtr);
	REP(i,nbtr){
		printf("%d%c",toreverse[i],i==nbtr-1?'\n':' ');
	}
}