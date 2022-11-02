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

const int N = 25;
const int H = 13;

vector<ll> can[N];
int n, k, h;
int a[N];
ll fac[N];
ll S;
ll ans = 0;

void right(int i, ll s, int f){
    if(s > S || f > k)ret;
    if(i == n){
        E(j, f, k)
            can[j].pb(s);
        ret;
    }
    right(i + 1, s, f);
    right(i + 1, s + a[i], f);
    if(a[i] < N && fac[a[i]])
        right(i + 1, s + fac[a[i]], f + 1);
}

void left(int i, ll s, int f){
    if(s > S || f > k)ret;
    if(i == h){
        auto it = equal_range(all(can[k - f]), S - s);
        ans += it.Y - it.X;
        ret;
    }
    left(i + 1, s, f);
    left(i + 1, s + a[i], f);
    if(a[i] < N && fac[a[i]])
        left(i + 1, s + fac[a[i]], f + 1);
}

signed main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k >> S;
    fac[0] = 1;
    F(i, 1, N){
        fac[i] = fac[i - 1] * i;
        if(fac[i] > S){
            fac[i] = 0;
            brk;
        }
    }
    F(i, 0, n)cin >> a[i];
    h = min(n - 1, H);
    right(h, 0, 0);
    E(i, 0, k)
        sort(all(can[i]));
    left(0, 0, 0);
    cout << ans << endl;
    return 0;
}