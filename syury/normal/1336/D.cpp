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

const int N = 111;
const int K = 4;

vector<int> local_a;
int n;
int C2[N];
ll thr[N], seq[N];
int ans[N];
bool dp[N][1<<K];
int prv[N][1<<K];
bool unsure[N];

pair<ll, ll> init(){
#ifdef LOCAL
    ll a = 0, b = 0;
    F(i, 0, n)a += local_a[i] * 1ll * (local_a[i] - 1) * (local_a[i] - 2)/6;
    F(i, 0, n - 2)b += local_a[i] * local_a[i + 1] * local_a[i + 2];
    ret {a, b};
#else
    ll a, b;
    cin >> a >> b;
    ret {a, b};
#endif
}

pair<ll, ll> ask(int x){
#ifdef LOCAL
    ++local_a[x - 1];
    ret init();
#else
    cout << "+ " << x << endl;
    ll a, b;
    cin >> a >> b;
    ret {a, b};
#endif
}

inline int getval(int pos, int bit){
    if(bit)
        ret 1;
    else ret ans[pos];
}

inline ll deltat(int pos){
    ret seq[pos + 1] - seq[pos];
}

inline bool valid(int i, int pb, int mask){
    mask = (mask<<1)|pb;
    return (1 + getval(i - 5, mask&1)) * (1 + getval(i - 4, mask&2)) + (1 + getval(i - 4, mask&2)) * (getval(i - 2, mask&8)) + getval(i - 2, mask&8) * getval(i - 1, mask&16) == deltat(i - 3);
}

void restore(int j, int mask){
    if(j == 4){
        F(i, 0, 4)if(mask&(1<<i))ans[i] = 1;
        ret;
    }
    if(mask&8){ans[j - 1] = 1;}
    restore(j - 1, prv[j][mask]);
}

int main(){
#ifdef LOCAL
    //freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    F(i, 0, N)C2[i] = i * (i - 1)/2;
#ifndef LOCAL
    cin >> n;
#else
    n = 5;
    local_a = {2, 1, 3, 0, 2};
#endif
    tie(thr[0], seq[0]) = init();
    DF(i, n - 2, 2){
        tie(thr[n - 1 - i], seq[n - 1 - i]) = ask(i + 1);
    }
    tie(thr[n - 2], seq[n - 2]) = ask(1);
    tie(thr[n - 1], seq[n - 1]) = ask(2);
    tie(thr[n], seq[n]) = ask(1);
    F(i, 1, N)if(thr[n] - thr[n - 1] == C2[i]){ans[0] = i - 1;}
    ans[2] = (seq[n] - seq[n - 1]) - (seq[n - 2] - seq[n - 3]) - 1;
    ans[1] = (seq[n - 2] - seq[n - 3])/(ans[2] + 1);
    F(i, 3, n){
        ll sum = (ans[i - 1] + 1) * (i == 3 ? 1 + ans[i - 3] : ans[i - 3]) + (i == 3 ? 0 : (ans[i - 3] * ans[i - 4]));
        ll delta = i == 3 ? seq[n - 1] - seq[n - 2] : (seq[n - 1 - (i - 2)] - seq[n - 1 - (i - 2) - 1]);
        ans[i] = (delta - sum)/(ans[i - 1] + 1) - (i + 1 == n ? 0 : 1);
    }
    cout << "! ";
    F(i, 0, n)cout << ans[i] << ' ';
    cout << endl;
    return 0;
}