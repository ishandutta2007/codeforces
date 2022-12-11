#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("A.inp","r",stdin)
#define OUTPUT freopen("A.out","w",stdout)
#define FOR(i,l,r) for(auto i=l;i<=r;i++)
#define REP(i,l,r) for(auto i=l;i<r;i++)
#define FORD(i,l,r) for(auto i=l;i>=r;i--)
#define REPD(i,l,r) for(auto i=l;i>r;i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=1e9;
const int MOD=1e9+7;
const int N=4e2+10;

int n,m,v[N][N],h[N];
queue <int> q;
void prepare(){
    cin>>n>>m;
    int x,y;
    while (m--){
        cin>>x>>y;
        v[x][y]=v[y][x]=1;
    }
    int val=v[1][n];
    FOR(i,1,n)
        FOR(j,1,n) v[i][j]^=val;
//    FOR(i,1,n)
//        FOR(j,1,n) cout<<v[i][j]<<" \n"[j==n];
}
int solve(){
    q.push(1);
    h[1]=1;
    while (!q.empty()){
        int x=q.front();q.pop();
        FOR(y,1,n) if (v[x][y]&&!h[y]){
            h[y]=h[x]+1;
            q.push(y);
        }
    }
//    FOR(i,1,n) cout<<h[i]<<" \n"[i==n];;
    return h[n]-1;
}
int main(){
    prepare();
    cout<<solve();
}