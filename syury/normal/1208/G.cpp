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

typedef long long ll;
typedef unsigned long long ull;
typedef long double dbl;
typedef pair<int, int> pii;

const int N = (int)1e6 + 6;

int a[N];
int phi[N];
int n, k;

signed main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    iota(phi, phi + N, 0);
    F(i, 1, N){
        for(int j = i * 2; j < N; j += i)
            phi[j] -= phi[i];
    }

    cin >> n >> k;
    if(k == 1){cout << 3; ret 0;}
    ll ans = 0;
    iota(a, a + N - 1, 1);
    sort(a, a + n, [](int l, int r){return phi[l] < phi[r];});
    F(i, 0, k + 2){
        ans += phi[a[i]];
    }
    cout << ans << endl;
    return 0;
}