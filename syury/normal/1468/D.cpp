//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,tune=native")
#include<bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(),(x).end()
#define pb push_back
#define X first
#define Y second
#define mp make_pair

typedef long long ll;
typedef unsigned long long ull;
typedef double dbl;
typedef pair<int, int> pii;

bool can(int* s, int k, int cat){
    for(int i = 0; i < k; i++){
        int t = k - 1 - i + s[i];
        if(t > cat)
            return false;
    }
    return true;
}

void solve(){
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    int s[m];
    for(int i = 0; i < m; i++)
        cin >> s[i];
    sort(s, s + m);
    int sz = min(m, abs(a - b) - 1);
    int mv = a < b ? a - 1 : (n - a);
    int cat = abs(a - b) - 1 + mv;
    int l = 0, r = sz;
    if(can(s, r, cat))l = r;
    while(r - l > 1){
        int mid = (l + r)/2;
        if(can(s, mid, cat))
            l = mid;
        else
            r = mid;
    }
    cout << l << '\n';
}

signed main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T=1;
    cin >> T;
    while(T--)
        solve();
    return 0;
}