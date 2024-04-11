#include<bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;
mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
//mt19937_64 mrand(42);
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define al(x) x+1,x+1+n
#define asd cout<<"ok"<<endl;
#define asdd cout<<"okok"<<endl;
#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vii vector<pair<int,int>>
#define pr(v) for(auto i:v) cout<<i<<" ";cout<<endl;
#define prt(a, l, r) for(auto i=l;i<=r;++i) cout<<a[i]<<" ";cout<<endl;
#define pc(x) __builtin_popcount(x)
#define pb push_back
#define PS string qqwwee;cin>>qqwwee;
typedef pair<int, int> pii;

char a[105][105];
struct node {
    int x1,y1,x2,y2,x3,y3;
};
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--) {
        int n,m;
        cin>>n>>m;
        ii jj {
            cin>>a[i][j];
            if(a[i][j]=='1') a[i][j]=1;
            else a[i][j]=0;
        }
        vector<node> ans;
        auto add = [&](int x1,int y1,int x2,int y2,int x3,int y3) {
            ans.push_back({x1,y1,x2,y2,x3,y3});
            a[x1][y1]^=1;
            a[x2][y2]^=1;
            a[x3][y3]^=1;
        };
        // n-2 line
        for(int i=1;i<=n-2;++i) {
            for(int j=1;j<=m;++j) {
                if(j<m) {
                    if(a[i][j]) add(i,j,i+1,j+1,i+1,j);
                } else {
                    if(a[i][j]) add(i,j,i+1,j-1,i+1,j);
                }
            }
        }
        // last 2 line
        int x=n-1,y=n;
        for(int j=1;j<=m-2;++j) {
            if(!a[x][j] && !a[y][j]) continue;
            if(a[x][j] && a[y][j]) {
                add(x,j,y,j,x,j+1);
            } else if(a[x][j]) {
                add(x,j,y,j+1,x,j+1);
            } else {
                add(y,j,y,j+1,x,j+1);
            }
        }
        int x1=n-1,x2=n,y1=m-1,y2=m;
        int cnt=a[x1][y1]+a[x1][y2]+a[x2][y1]+a[x2][y2];
        vector<pair<int,int>> v{{x1,y1},{x2,y2},{x1,y2},{x2,y1}};
        if(cnt == 4) {
            vector<int> v2;
            for(auto p:v)
                if(a[p.first][p.second]) {
                    v2.push_back(p.first);
                    v2.push_back(p.second);
                    if(v2.size() == 6) break;
                }
            add(v2[0],v2[1],v2[2],v2[3],v2[4],v2[5]);
        }
        cnt=a[x1][y1]+a[x1][y2]+a[x2][y1]+a[x2][y2];
        if(cnt == 1) {
            int xx,yy;
            for(auto p:v) if(a[p.first][p.second]) xx=p.first,yy=p.second;
            vector<int> v2{xx,yy};
            for(auto p:v) if(!a[p.first][p.second]) {
                v2.push_back(p.first);
                v2.push_back(p.second);
                if(v2.size() == 6) break;
            }
            add(v2[0],v2[1],v2[2],v2[3],v2[4],v2[5]);
        }
        cnt=a[x1][y1]+a[x1][y2]+a[x2][y1]+a[x2][y2];
        if(cnt == 2) {
            vector<int> v2;
            for(auto p:v)
                if(!a[p.first][p.second]) {
                    v2.push_back(p.first);
                    v2.push_back(p.second);
                    if(v2.size() == 6) break;
            }
            for(auto p:v)
                if(a[p.first][p.second]) {
                    v2.push_back(p.first);
                    v2.push_back(p.second);
                    if(v2.size() == 6) break;
            }
            add(v2[0],v2[1],v2[2],v2[3],v2[4],v2[5]);
        }
        cnt=a[x1][y1]+a[x1][y2]+a[x2][y1]+a[x2][y2];
        if(cnt == 3) {
            vector<int> v2;
            for(auto p:v)
                if(a[p.first][p.second]) {
                    v2.push_back(p.first);
                    v2.push_back(p.second);
                    if(v2.size() == 6) break;
                }
            add(v2[0],v2[1],v2[2],v2[3],v2[4],v2[5]);
        }
        ii jj assert(!a[i][j]);
        cout<<ans.size()<<endl;
        for(node p:ans) {
            cout<<p.x1<<" "<<p.y1<<" "<<p.x2<<" "<<p.y2<<" "<<p.x3<<" "<<p.y3<<endl;
        }
    }
}