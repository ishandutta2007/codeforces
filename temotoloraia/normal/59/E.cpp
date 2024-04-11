#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define ll long long int
#define LEFT(a) ((a)<<1)
#define RIGHT(a) (LEFT(a) + 1)
#define MID(a,b) ((a+b)>>1)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
using namespace std;
const int N=3005,INF=1e9;
int n,m,k;
vector<int>g[N];
int D[N][N],F[N][N];
map<pair<pair<int,int>,int>,bool>M;
queue<pair<int,pair<int,int> > >Q;
bool fix[N][N];
int main() {
    cin>>n>>m>>k;
    while (m--){
        int u,v;
        cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }
    while (k--){
        int a,b,c;
        cin>>a>>b>>c;
        M[mp(mp(a,b),c)]=1;
    }
    for (int i=0;i<=n;i++)
        for (int j=0;j<=n;j++)
            D[i][j]=INF;
    D[1][0]=0;
    Q.push(mp(0,mp(1,0)));
    while (Q.size()>0){
        int A=Q.front().S.F,B=Q.front().S.S;
        Q.pop();
        if (fix[A][B])continue;
        fix[A][B]=1;
        for (int i=0;i<g[A].size();i++)
            if (D[g[A][i]][A]>D[A][B]+1)
                if (M[mp(mp(B,A),g[A][i])]==0){
                    D[g[A][i]][A]=D[A][B]+1;
                    F[g[A][i]][A]=B;
                    Q.push(mp(D[g[A][i]][A],mp(g[A][i],A)));
                }
    }
    int ans=D[n][0];
    int x=n,y=0;
    for (int i=1;i<=n;i++)
        if (D[n][i]<ans){
            ans=D[n][i];
            y=i;
        }
    if (ans==INF){
        cout<<-1;
        return 0;
    }
    cout<<ans<<endl;
    //cout<<x<<" "<<y<<" ";
    vector<int>v;
    while (y!=1){
        int z=F[x][y];
        v.pb(x);
        x=y;
        y=z;
        //cout<<y<<" ";
    }
    //cout<<endl;
    v.pb(x);
    v.pb(y);
    for (int i=v.size()-1;i>=0;i--)
        cout<<v[i]<<" ";
    cout<<endl;
    return 0;
}