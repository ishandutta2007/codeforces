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
typedef long double dbl;
typedef pair<int, int> pii;

void solve(){
    string s;
    cin >> s;
    int n = s.length();
    int as = 0, bs = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == 'A')
            ++as;
        else{
            if(as){--as;}
            else{++bs;}
        }
    }
    bs %= 2;
    cout << as + bs << '\n';
}

signed main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--)
        solve();
    return 0;
}