#include<bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;
mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define all(x) x.begin(),x.end()
#define al(x) x+1,x+1+n
#define asd cout<<"ok"<<endl;
#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vii vector<pair<int,int>>
#define pc(x) __builtin_popcount(x)
#define pb push_back

int a[200005];
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        for(int i = 1; i <= n; ++i) a[i] = i;
        vector<pair<int,int>> ans;
        int m = n;
        while(m > 2) {
            int sq = sqrt(m + 1);
            for(int i = sq + 1; i < m; ++i) {
                ans.push_back({i, n});
            }
            if(sq == 2) {
                m = 2;
                break;
            }
            ans.push_back({n, sq});
            a[n] = (a[n] + sq - 1) / sq;
            assert(a[n] >= a[sq]);
            ans.push_back({sq, n});
            m = sq;
        }
        while(a[n] > 1) {
            ans.push_back({n, 2});
            a[n] = (a[n] + 1) / 2;
        }
        cout << ans.size() << endl;
        for(auto p : ans) {
            cout << p.first << " " << p.second << endl;
        }
    }
}