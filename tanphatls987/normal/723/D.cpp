#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> ii;
#define X first
#define Y second

const int N=60;
const int dx[4]={0,0,1,-1};
const int dy[4]={1,-1,0,0};

vector <ii> g[N*N];

ii q[N*N];
int p[N*N],a[N][N];
int n,m,k;
int h[N][N];

string s;

ii operator +(ii a,ii b){
    return ii(a.X+b.X,a.Y+b.Y);
}
int BFS(int sx,int sy){
    q[1]=ii(sx,sy);
    h[sx][sy]=1;
    int top=1,bot=1;
    while (top<=bot){
        ii cur=q[top++];
        for(int dir=0;dir<4;dir++){
            ii ncur=cur+ii(dx[dir],dy[dir]);
            if (!a[ncur.X][ncur.Y]&&!h[ncur.X][ncur.Y]){
                h[ncur.X][ncur.Y]=1;
                q[++bot]=ncur;
            }
        }
    }
    return bot;
}
bool comp(int x,int y){
    return g[x].size()>g[y].size();
}
void solve(){
    for(int i=1;i<=n;i++) a[i][0]=a[i][m+1]=1;
    for(int i=1;i<=m;i++) a[0][i]=a[n+1][i]=1;
    for(int i=1;i<=m;i++) if (!a[1][i]&&!h[1][i]) BFS(1,i);
    for(int i=1;i<=m;i++) if (!a[n][i]&&!h[n][i]) BFS(n,i);
    for(int i=1;i<=n;i++) if (!a[i][1]&&!h[i][1]) BFS(i,1);
    for(int i=1;i<=n;i++) if (!a[i][m]&&!h[i][m]) BFS(i,m);
    int n2=0;
//    for(int i=1;i<=n;i++)
//        for(int j=1;j<=m;j++) cout<<h[i][j]<<" \n"[j==m];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) if (!a[i][j]&&!h[i][j]){
            int n1=BFS(i,j);
            n2++;
            while (n1) g[n2].push_back(q[n1--]);
        }
    for(int i=1;i<=n2;i++) p[i]=i;
    sort(p+1,p+n2+1,comp);
    int ans=0;
    while (n2>k){
        ans+=g[p[n2]].size();
        for(auto i:g[p[n2]]) a[i.X][i.Y]=1;
        n2--;
    }
    cout<<ans<<'\n';
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) if (a[i][j]) cout<<"*";
        else cout<<".";
        cout<<'\n';
    }
}
int main(){
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++) {
        cin>>s;
        for(int j=1;j<=m;j++) a[i][j]=(s[j-1]=='*');
    }
    solve();
}