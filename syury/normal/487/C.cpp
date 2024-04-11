//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,tune=native")
#include<bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(),(x).end()
#define I(x, a) for(auto x : (a))
#define ins insert
#define F(i, l, r) for(auto i = (l); i < (r); i++)
#define DF(i, l, r) for(auto i = (l); i >= (r); i--)
#define E(i, l, r) for(auto i = (l); i <= (r); i++)
#define pb push_back
#define X first
#define Y second
#define mp make_pair
#define ret return
#define brk break
#define cont continue
#define move fjgjgjgjghd

typedef long long ll;
typedef unsigned long long ull;
typedef long double dbl;
typedef pair<int, int> pii;

int inv(int x, int p){
    int res = 1, pw = p - 2;
    while(pw){
        if(pw&1)res = res * 1ll * x % p;
        x = x * 1ll * x % p;
        pw >>= 1;
    }
    ret res;
}

signed main(){
#ifdef LOCAL
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    if(n == 1){cout << "YES\n1"; ret 0;}
    if(n == 4){cout << "YES\n1\n3\n2\n4"; ret 0;}
    for(int i = 2; i * i <= n; i++){
        if(n%i == 0){cout << "NO"; ret 0;}
    }
    int old = 1;
    cout << "YES\n";
    F(i, 0, n){
        int kek = inv(old, n) * 1ll * (i + 1)%n;
        if(kek == 0)kek = n;
        old = i + 1;
        cout << kek << '\n';
    }
    return 0;
}