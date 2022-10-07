#include <bits/stdc++.h>
#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define ll long long int
#define LEFT(a) ((a)<<1)
#define RIGHT(a) (LEFT(a) + 1)
#define MID(a,b) ((a+b)>>1)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
using namespace std;
int n;
vector<int>g[100005];
double D[100005];
double P[100005];
double ans=0;
void DFS (int k, int p){
    D[k]=D[p]+1;
    double pp=0;
    for (int i=0;i<g[k].size();i++)
        if (g[k][i]!=p)
            pp+=1;
    for (int i=0;i<g[k].size();i++)
        if (g[k][i]!=p){
            P[g[k][i]]=P[k]/pp;
            DFS(g[k][i],k);
        }
}
int main() {
    cin>>n;
    for (int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }
    D[0]=-1;
    P[1]=1;
    DFS(1,0);
    for (int i=2;i<=n;i++)
        if (g[i].size()==1)
            ans+=D[i]*P[i];
    printf("%.10f",ans);
    return 0;
}