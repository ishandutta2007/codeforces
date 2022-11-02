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

int n;
vector<int> primes;

inline vector<ll> generate(vector<int> ps, ll N){
    vector<ll> ans = {1};
    for(auto p: ps){
        vector<ll> new_ans;
        ll pw = 1;
        while(1){
            for(auto prv: ans){
                if(prv > N/pw)
                    break;
                new_ans.push_back(prv * pw);
            }
            if(pw > N/p)
                break;
            pw *= p;
        }
        sort(all(new_ans));
        ans.swap(new_ans);
    }
    return ans;
}

inline ll cnt(ll mid, vector<ll> & L, vector<ll> & R){
    ll ans = 0;
    int ptr = (int)R.size() - 1;
    for(auto a: L){
        while(ptr >= 0 && R[ptr] > mid/a)
            --ptr;
        ans += ptr + 1;
    }
    return ans;
}

signed main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    primes.resize(n);
    for(int i = 0; i < n; i++)
        cin >> primes[i];
    vector<int> lp, rp;
    for(int i = 0; i < n; i++)
        if(i&1)rp.pb(primes[i]); else lp.pb(primes[i]);
    auto LP = generate(lp, (ll)1e18), RP = generate(rp, (ll)1e18);
    ll L = 1, R = (ll)1e18;
    ll k;
    cin >> k;
    if(k == 1){cout << 1; return 0;}
    while(R - L > 1){
        ll mid = (L + R)/2;
        if(cnt(mid, LP, RP) < k)
            L = mid;
        else
            R = mid;
    }
    cout << R << endl;
    return 0;
}