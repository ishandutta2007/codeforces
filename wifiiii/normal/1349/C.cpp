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
queue<pii> q;
int dir1[] = {-1,1,0,0};
int dir2[] = {0,0,1,-1};
int vis[1005][1005],dis[1005][1005];
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m,t;
    cin>>n>>m>>t;
    ii jj cin>>a[i][j];
    ii jj {
        for(int k=0;k<4;++k) {
            int xx=dir1[k]+i,yy=dir2[k]+j;
            if(xx<=0 || yy<=0 || xx>n || yy>m) continue;
            if(a[i][j] == a[xx][yy]) {
                vis[i][j] = 1;
                q.push({i,j});
            }
        }
    }
    while(!q.empty()) {
        pii cur=q.front();q.pop();
        for(int k=0;k<4;++k) {
            int xx=dir1[k]+cur.first,yy=dir2[k]+cur.second;
            if(xx<=0 || yy<=0 || xx>n || yy>m || vis[xx][yy]) continue;
            dis[xx][yy] = dis[cur.first][cur.second] + 1;
            vis[xx][yy] = 1;
            q.push({xx,yy});
        }
    }
    while(t--) {
        int x,y;
        ll p;
        cin>>x>>y>>p;
        if(!vis[x][y] || p <= dis[x][y]) {
            cout << a[x][y] << endl;
        } else {
            cout << ((a[x][y]-'0')^((p-dis[x][y])&1)) << endl;
        }
    }
}