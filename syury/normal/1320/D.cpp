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
#define sz(a) ((int)a.size())

typedef long long ll;
typedef unsigned long long ull;
typedef long double dbl;
typedef pair<int, int> pii;

const int N = (int)2e5 + 5;
const int NH = 2;
const int MOD[NH] = {(int)1e9 + 7, 999999883};
const int P[NH] = {29, 31};

inline int modpow(ll x, int p, int mod){
    ll res = 1;
    while(p){
        if(p&1)
            res = res * x % mod;
        x = x * x % mod;
        p >>= 1;
    }
    return res;
}

string s;
string t;
int n, q;
int zid[N];
int nZ[N], pZ[N];
int h[N][2];
int pw[N][2];
int rpw[N][2];

inline void calc_hash(){
    for(size_t i = 0; i < t.length(); i++){
        for(int c = 0; c < NH; c++){
            h[i][c] = i ? h[i - 1][c] : 0;
            pw[i][c] = !i ? 1 : (pw[i - 1][c] * 1ll * P[c] % MOD[c]);
            rpw[i][c] = modpow(pw[i][c], MOD[c] - 2, MOD[c]);
            int curr = (t[i] - '0' + 1) * 1ll * pw[i][c] % MOD[c];
            h[i][c] += curr;
            h[i][c] -= h[i][c] >= MOD[c] ? MOD[c] : 0;
        }
    }
}

inline pii get_hash(int l, int r){
    return l ? mp(
        int((h[r][0] - h[l-1][0] + (ll)MOD[0]) * 1ll * rpw[l][0] % MOD[0]),
        int((h[r][1] - h[l-1][1] + (ll)MOD[1]) * 1ll * rpw[l][1] % MOD[1])
        )
    : mp(h[r][0], h[r][1]);
}

inline int countz(int l, int r){
    int fst = nZ[l], la = pZ[r];
    return fst <= la ? zid[la] - zid[fst] + 1 : 0;
}

void solve(){
    cin >> n;
    cin >> s;
    int nzeros = 0;
    int la = -1;
    for(int i = 0; i < n; i++){
        if(s[i] == '0'){
            t += (i - la)%2 + '0';
            pZ[i] = i;
            la = i;
            zid[i] = nzeros++;
        }
        else{
            pZ[i] = i ? pZ[i - 1] : -1;
        }
    }
    zid[n] = nzeros;
    t += (n - la)%2 + '0';
    for(int i = n - 1; i >= 0; i--){
        nZ[i] = s[i] == '0' ? i : (i + 1 == n ? n : nZ[i + 1]);
    }
    calc_hash();
    cin >> q;
    for(int i = 0; i < q; i++){
        int l1, l2, len;
        cin >> l1 >> l2 >> len;
        --l1; --l2;
        int hz = countz(l1, l1 + len - 1);
        if(hz != countz(l2, l2 + len - 1)){
            cout << "No\n";
            continue;
        }
        if(!hz){
            cout << "Yes\n";
            continue;
        }
        if((nZ[l1] - l1)%2 != (nZ[l2] - l2)%2 || (l1 + len - 1 - pZ[l1 + len - 1])%2 != (l2 + len - 1 - pZ[l2 + len - 1])%2){
            cout << "No\n";
            continue;
        }
        int f1 = zid[nZ[l1]], s1 = zid[pZ[l1 + len - 1]];
        int f2 = zid[nZ[l2]], s2 = zid[pZ[l2 + len - 1]];
        if(f1 != s1){
            auto h1 = get_hash(f1 + 1, s1);
            auto h2 = get_hash(f2 + 1, s2);
            if(h1 != h2){
                cout << "No\n";
                continue;
            }
        }
        cout << "Yes\n";
    }
}

signed main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(11);
    int T = 1;
    while(T--)
        solve();
    return 0;
}