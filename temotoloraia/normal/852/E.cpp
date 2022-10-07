#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define ll long long
#define LEFT(a) ((a)<<1)
#define RIGHT(a) (LEFT(a) + 1)
#define MID(a,b) ((a+b)>>1)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
using namespace std;
const int N=100005,MOD=1e9+7;
int n,ans;
vector<int>g[N];
int C[N];
int B[N];
void DFS (int k, int p){
    if (p){
        C[k]=C[p];
        if ((int)g[k].size()==1)C[k]--;
        if ((int)g[p].size()==1)C[k]++;
    }
    for (int i=0;i<g[k].size();i++)
        if (g[k][i]!=p)
            DFS(g[k][i],k);
}
int main(){
    cin>>n;
    for (int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }
    for (int i=2;i<=n;i++)
        if ((int)g[i].size()==1)
            C[1]++;
    DFS(1,0);
    B[0]=1;
    for (int i=1;i<=n;i++)
        B[i]=B[i-1]*2%MOD;
    for (int i=1;i<=n;i++){
        ans=(ans+B[n-C[i]])%MOD;
        //cout<<C[i]<<" ";
    }
    //cout<<endl;
    cout<<ans<<endl;
    return 0;
}