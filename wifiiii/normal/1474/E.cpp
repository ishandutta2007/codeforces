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

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> mid((n-1)/2);
        iota(al(mid), n-mid.size());
        vector<int> pre(n-mid.size()-2);
        iota(al(pre), 0);
        vector<int> a;
        a.push_back(n-mid.size()-1);
        for(int i:pre) a.push_back(i);
        for(int i:mid) a.push_back(i);
        a.push_back(n-mid.size()-2);
        vector<int> aa = a;
        ll ans = 0;
        vector<pair<int,int>> b;
        for(int i=0;i<(n-1)/2;++i) {
            ans += 1ll * a[0] * a[0];
            int tmp = a[0];
            swap(a[0], a[tmp]);
            b.push_back({tmp, 0});
        }
        for(int i=0;i<n-mid.size()-2;++i) {
            ans += 1ll * (n-1-a[n-1]) * (n-1-a[n-1]);
            int tmp = a[n-1];
            swap(a[n-1], a[tmp]);
            b.push_back({tmp, n-1});
        }
        ans += 1ll * (n-1) * (n-1);
        swap(a[0], a[n-1]);
        b.push_back({0, n-1});
        assert(is_sorted(al(a)));
        cout << ans << endl;
        for(int i : aa) cout << i + 1 << " "; cout << endl;
        cout << b.size() << endl;
        for(auto &p : b) cout << p.first + 1 << " " << p.second + 1 << '\n';
    }
}