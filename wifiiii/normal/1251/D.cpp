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
        ll s;
        cin >> n >> s;
        vector<int> l(n), r(n);
        for(int i=0;i<n;++i) cin>>l[i]>>r[i];
        vector<int> ord(n);
        iota(al(ord), 0);
        sort(al(ord), [&](int i,int j) {return l[i] > l[j];});
        ll lo = 1, hi = 1e15;
        while(lo < hi) {
            ll mid = (lo + hi + 1) >> 1;
            int cnt = 0;
            for(int i=0;i<n;++i) if(r[i]>=mid) cnt++;
            if(cnt <= n / 2) {
                hi = mid - 1;
                continue;
            }
            vector<int> use(n);
            int used = 0;
            ll tot = 0;
            for(int i:ord) {
                if(r[i]>=mid) use[i]=1, ++used, tot += max((ll)l[i], mid);
                if(used == n / 2 + 1) break;
            }
            assert(used == n / 2 + 1);
            for(int i:ord) {
                if(use[i]) continue;
                tot += l[i];
            }
            if(tot > s) hi = mid - 1;
            else lo = mid;
        }
        cout << lo << endl;
    }
}