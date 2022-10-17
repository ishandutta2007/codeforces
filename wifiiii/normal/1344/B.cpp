#include<bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;
mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define al(x) x+1,x+1+n
#define asd cout<<"ok"<<endl;
#define asdasd cout<<"okok"<<endl;
#define pii pair<int,int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vii vector<pair<int,int>>
#define pr(v) for(auto i:v) cout<<i<<" ";cout<<endl
#define prt(a, l, r) for(auto i=l;i<=r;++i) cout<<a[i]<<" ";cout<<endl;
#define pc(x) __builtin_popcount(x)
#define endl '\n'

char a[1005][1005];
int vis[1005][1005];
int cx[1005],cy[1005];
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;cin>>n>>m;
    ii jj cin>>a[i][j];
    int c=0;
    ii jj if(a[i][j]=='#') c++,cx[i]++,cy[j]++;
    if(!c) return cout<<0<<endl,0;
    int zx=0,zy=0;
    ii if(!cx[i]) zx++;
    jj if(!cy[j]) zy++;
    if(!zx || !zy) {
        if(zx || zy) return cout << -1 << endl, 0;
    }
    for(int i=1;i<=n;++i) {
        int f = 0;
        for(int j=1;j<=m;++j) {
            if(f == 0 && a[i][j] == '#') f = 1;
            if(f == 1 && a[i][j] == '.') f = 2;
            if(f == 2 && a[i][j] == '#') return cout<<-1<<endl,0;
        }
    }
    for(int j=1;j<=m;++j) {
        int f = 0;
        for(int i=1;i<=n;++i) {
            if(f == 0 && a[i][j] == '#') f = 1;
            if(f == 1 && a[i][j] == '.') f = 2;
            if(f == 2 && a[i][j] == '#') return cout<<-1<<endl,0;
        }
    }
    int dir1[4]={-1,1,0,0};
    int dir2[4]={0,0,-1,1};
    int cnt=0;
    for(int i=1;i<=n;++i) {
        for(int j=1;j<=m;++j) {
            if(vis[i][j] || a[i][j] == '.') continue;
            queue<pii> q;
            q.push({i,j});
            vis[i][j]=1;
            while(!q.empty()) {
                auto cur=q.front();q.pop();
                for(int k=0;k<4;++k) {
                    int xx=cur.first+dir1[k],yy=cur.second+dir2[k];
                    if(xx==0||yy==0||xx>n||yy>m||vis[xx][yy]||a[xx][yy]=='.') continue;
                    q.push({xx,yy});
                    vis[xx][yy]=1;
                }
            }
            cnt++;
        }
    }
    cout<<cnt<<endl;
}