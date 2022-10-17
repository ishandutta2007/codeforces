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

int a[200005], b[200005];
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        for(int i = 1; i <= n; ++i) cin >> a[i];
        int l = a[1], r = a[1], ok = 1;
        for(int i = 2; i <= n; ++i) {
            int nl = max(0, l - (k - 1)), nr = r + (k - 1);
            nl = max(nl, a[i]), nr = min(nr, a[i] + (k - 1));
            if(nl > nr) {
                ok = 0;
                break;
            }
            l = nl, r = nr;
        }
        if(ok && l == a[n]) cout << "yes\n";
        else cout << "no\n";
    }
}