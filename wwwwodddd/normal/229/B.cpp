#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<set>
#include<queue>
using namespace std;
#define fr(i,n) for(int i=0;i<n;i++)
#define fo(i,n) for(int i=1;i<=n;i++)
#define fe(i,n) for(__typeof(n.begin()) i=n.begin();i!=n.end();i++)
const int N = 100009;

struct edge{
    int p, w;
};
vector<edge> adj[N];
int D[N]; bool C[N];
int n, m;

set<int> A[N];


struct comp{
    bool operator()(int a, int b){
        return (D[a]>D[b]);
    }
};

priority_queue< int, vector<int>, comp > Q;


void init(){
    cin >> n >> m;

    int a, b; edge x;
    for (int i=0;i<m;i++){
        cin >> a >> b >> x.w;
        x.p = b; adj[a].push_back(x);
        x.p = a; adj[b].push_back(x);
    }

    fo(i, n){
        int t;
        scanf("%d",&t);
        fr(j,t)
		{
			int w;
			scanf("%d",&w);
            A[i].insert(w);
        }
    }

}
void dijkstra(){
	memset(D,0x3f,sizeof D);
	memset(C,1,sizeof C);

    while (!Q.empty())
		Q.pop();
    Q.push(1);
    D[1] = 0;

    int u, v;
    for (int i=0;i<n;i++){
        while (!Q.empty()){
            u = Q.top(), Q.pop();
            if (C[u]) break;
        }
        if (!C[u]||u==n) return;
        C[u] = false;


        int Du = D[u];
		while(A[u].count(Du))
			Du++;


        for (vector<edge>::iterator it=adj[u].begin();it!=adj[u].end();it++){
            v = (*it).p;
            if (C[v]&&Du + (*it).w < D[v]){
                D[v] = Du + (*it).w;
                Q.push(v);
            }
        }
    }
}

int main(){



    init(); dijkstra();
    cout<<(D[n] == 0x3f3f3f3f ? -1 : D[n]);
}