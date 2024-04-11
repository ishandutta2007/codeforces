#include<bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;
mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define al(x) x.begin(),x.end()
#define asd cout<<"ok"<<endl;
#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vii vector<pair<int,int>>
#define pc(x) __builtin_popcount(x)
#define pb push_back

char a[1005][1005];
int b[1005][1005];
int up[1005][1005], dn[1005][1005], lf[1005][1005], rt[1005][1005];
struct node {
    int x, y, w;
};
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    vector<node> ans;
    int n,m;
    cin>>n>>m;
    ii jj cin>>a[i][j];
    for(int i=1;i<=n;++i) {
        for(int j=1;j<=m;++j) {
            if(a[i][j] == '*') {
                up[i][j] = up[i-1][j]+1;
                lf[i][j] = lf[i][j-1]+1;
            }
        }
        for(int j=m;j>=1;--j) {
            if(a[i][j] == '*') {
                rt[i][j] = rt[i][j+1]+1;
            }
        }
    }
    for(int i=n;i>=1;--i) {
        for(int j=1;j<=m;++j) {
            if(a[i][j] == '*')
                dn[i][j] = dn[i+1][j]+1;
        }
    }
    auto add = [&](int x1,int y1,int x2,int y2) {
        assert(x1 <= x2);
        assert(y1 <= y2);
        b[x1][y1]++;
        b[x1][y2+1]--;
        b[x2+1][y1]--;
        b[x2+1][y2+1]++;
    };
    for(int i=1;i<=n;++i) {
        for(int j=1;j<=m;++j) {
            if(a[i][j] == '*') {
                int mn = min(min(up[i][j], dn[i][j]), min(lf[i][j], rt[i][j])) - 1;
                assert(mn >= 0);
                if(mn > 0) {
                    ans.push_back({i, j, mn});
                    // [i - mn, j, i + mn, j]
                    // [i, j - mn, i, j + mn]
                    add(i - mn, j, i + mn, j);
                    add(i, j - mn, i , j + mn);
                }
            }
        }
    }
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            b[i][j] = b[i][j] + b[i-1][j] + b[i][j-1] - b[i-1][j-1];
    int ok = 1;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j) {
            char tmp = '*';
            assert(b[i][j] >= 0);
            if(b[i][j] == 0) tmp = '.';
            if(a[i][j] != tmp) ok = 0;
        }
    if(ok) {
        cout << ans.size() << endl;
        for(auto &p : ans) {
            cout << p.x << " " << p.y << " " << p.w << endl;
        }
    } else {
        cout << -1 << endl;
    }
}