#include <bits/stdc++.h>
#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define ll long long
#define LEFT(a) ((a)<<1)
#define RIGHT(a) (LEFT(a) + 1)
#define MID(a,b) ((a+b)>>1)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
using namespace std;
const int N=100005;
int n,Q;
vector<int>g[N];
int in[N],out[N];
int T;
int D[N];
int P[N][22];
void DFS (int k, int p){
    in[k]=++T;
    P[k][0]=p;
    D[k]=D[p]+1;
    for (int i=0;i<g[k].size();i++)
        if (g[k][i]!=p)
            DFS(g[k][i],k);
    out[k]=++T;
}
int LCA (int u, int v){
    if (in[u]<=in[v] && out[v]<=out[u])
        return u;
    if (in[v]<=in[u] && out[u]<=out[v])
        return v;
    int I=u;
    for (int i=19;i>=0;i--){
        if (P[I][i]==0)continue;
        if (in[P[I][i]]<=in[v] && out[v]<=out[P[I][i]])continue;
        I=P[I][i];
    }
    return P[I][0];
}
int main() {
    cin>>n>>Q;
    for (int i=2;i<=n;i++){
        int p;
        cin>>p;
        //cout<<i<<" "<<p<<endl;
        g[i].pb(p);
        g[p].pb(i);
    }
    DFS(1,0);
    for (int i=1;(1<<i)<=n;i++)
        for (int j=1;j<=n;j++)
            P[j][i]=P[P[j][i-1]][i-1];
    //cout<<in[1]<<" "<<out[1]<<" "<<in[2]<<" "<<out[2]<<endl;
    //cout<<LCA(1,2)<<endl;
    while (Q--){
        int a,b,c;
        cin>>a>>b>>c;
        int x,y,z;
        x=LCA(b,c);
        y=LCA(a,c);
        z=LCA(a,b);
        if (x==z){
            swap(b,c);
            swap(y,z);
        }
        if (y==z){
            swap(a,c);
            swap(x,z);
        }
        //cout<<LCA(1,2)<<"           "<<a<<" "<<b<<" "<<c<<" "<<x<<" "<<y<<" "<<z<<" ";
        cout<<MAX(MAX(D[a]-D[z]+1,D[b]-D[z]+1),D[z]+D[c]-2*D[x]+1)<<endl;
    }
    return 0;
}