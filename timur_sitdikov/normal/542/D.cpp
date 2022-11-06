#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef complex<double> point;
#define xx real()
#define yy imag()

#define REP(i, a, b) for((i) = (a); (i) < (int)(b); (i)++)
#define FA(it, x) for(__typeof((x).begin()) it = (x).begin(); it != (x).end(); it++)
#define SZ(x) (int)(x).size()
#define BE(x) (x).begin(), (x).end()
#define SORT(x) sort(BE(x))

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

#define file "cycle"

const double EPS = 1e-9;
const double PI = acos(-1.);
const int INF = 1e9;
const int MAXN = 1e5 + 5;
const ll MOD = 1e9 + 7;

set<ll> divs_st;

map<ll, vector<ll> >st;

map<ll, ll> dp[2];

int check(ll v){
    ll i;
    if (v == 1){
        return 0;
    }
    for(i = 2; i * i <= v; i++){
        if (!(v % i)){
            return 0;
        }
    }
    return 1;
}

ll get(ll v){
    ll i;
    if (v == 1){
        return 0ll;
    }
    if (check(v)){
        return v;
    }
    ll sq = (ll)sqrt(v + 0.5);
    if (sq * sq == v && check(sq)){
        return sq;
    }
    return 0ll;
}

void solve(){
    ll n, i, j;
    cin >> n;
    for(i = 1; i * i <= n; i++){
        if (!(n % i)){
            divs_st.insert(i);
            divs_st.insert(n / i);
        }
    }
    FA(it, divs_st){
        ll tmp = *it;
        divs_st.insert(tmp);
        ll tmp1 = get(tmp - 1);
        if (tmp1){
            st[tmp1].pb(tmp);   
        }
    }
    ll LIM1 = 1e4;
    for(i = 2; i <= LIM1; i++){
        if (!check(i)){
            continue;
        }
        for(j = i * i * i; j <= n; j *= i){
            if (divs_st.find(j + 1) != divs_st.end()){
                st[i].pb(j + 1);
            }
        }
    }
    FA(it, st){
        SORT(it->second);
        /*for(i = 0; i < SZ(it->second); i++){
            cout << it->first << " " << (it->second)[i] << endl;
        }*/
    }
    int m = SZ(st);
    dp[0][1] = 1;
    j = 0;
    FA(it, st){
        j = j ^ 1;
        dp[j].clear();
        FA(it1, dp[j ^ 1]){
            ll tmp = it1->first;
            ll add = it1->second;
            dp[j][tmp] += add;
            ll tmp1 = n / tmp;
            for(i = 0; i < SZ(it->second); i++){
                ll cur = (it->second)[i];
                if (cur > tmp1){
                    break;
                }
                ll tmp2 = tmp * cur;
                if (!(n % tmp2)){
                    dp[j][tmp2] += add;
                }
            }
        }
        /*FA(it1, dp[j]){
            cout << it1->first << " " << it1->second << endl;
        }*/
    }
    //j ^= 1;
    ll ans = 0ll;
    if (dp[j].find(n) != dp[j].end()){
        ans = dp[j][n];
    }
    cout << ans << endl;
}   

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    //freopen(file".in", "r", stdin); freopen(file".out", "w", stdout);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();    
    }
}