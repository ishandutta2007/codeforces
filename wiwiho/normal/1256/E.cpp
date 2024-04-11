//#define NDEBUG

#include <bits/stdc++.h>

#define StarBurstStream ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define iter(a) a.begin(), a.end()
#define riter(a) a.rbegin(), a.rend()
#define lsort(a) sort(iter(a))
#define gsort(a) sort(riter(a))
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define eb(a) emplace_back(a)
#define pf(a) push_front(a)
#define pob pop_back()
#define pof pop_front()
#define F first
#define S second
#define B back()
#define FR front()
#define printv(a, b) {bool pvaspace=false; \
for(auto pva : a){ \
    if(pvaspace) b << " "; pvaspace=true;\
    b << pva;\
}\
b << "\n";}
#define pii pair<int, int>
#define pll pair<ll, ll>
#define modadd(a, b) (((a % MOD) + (b % MOD)) % MOD)
#define modtimes(a, b) (((a % MOD) * (b % MOD)) % MOD)
#define iceil(a) ((int)ceil((int)a))
#define ifloor(a) ((int)floor((int)a))

//#define TEST

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const ll MOD = 1000000007;
const ll MAX = 2147483647;

ostream& operator<<(ostream& o, pll p){
    return o << p.F << ',' << p.S;
}

int main(){
    StarBurstStream

    int n;
    cin >> n;

    vector<pll> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i].F;
        a[i].S = i;
    }

    lsort(a);

    vector<ll> d(n);

    vector<int> f0(n), f1(n), f2(n);
    vector<ll> dp0(n), dp1(n), dp2(n);

    for(int i = 1; i < n; i++) d[i] = a[i].F - a[i - 1].F;

    dp0[0] = MAX; dp1[0] = MAX; dp2[0] = MAX;
    dp0[1] = MAX; dp1[1] = d[1]; dp2[1] = MAX;
    dp0[2] = MAX; dp1[2] = MAX; dp2[2] = d[1] + d[2];
    f2[2] = 1;
    for(int i = 3; i < n; i++){

        dp0[i] = dp2[i - 1];
        f0[i] = 2;

        dp1[i] = dp0[i - 1] + d[i];
        f1[i] = 0;

        dp2[i] = dp1[i - 1] + d[i];
        f2[i] = 1;
        if(dp2[i - 1] + d[i] < dp2[i]){
            dp2[i] = dp2[i - 1] + d[i];
            f2[i] = 2;
        }

    }

    int now = 2;
    vector<bool> w(n);
    w[1] = true;
    for(int i = n - 1; i > 1; i--){
        if(now != 0) w[i] = true;
        if(now == 0) now = f0[i];
        else if(now == 1) now = f1[i];
        else now = f2[i];
    }

    vector<int> team(n);
    vector<int> ans(n);
    ans[a[0].S] = 1;
    team[0] = 1;
    for(int i = 1; i < n; i++){
        if(w[i]) team[i] = team[i - 1];
        else team[i] = team[i - 1] + 1;
        ans[a[i].S] = team[i];
    }

    cout << dp2[n - 1] << " " << team.back() << "\n";
    printv(ans, cout);

    /*printv(dp0, cerr);
    printv(dp1, cerr);
    printv(dp2, cerr);
    printv(a, cerr);
    printv(d, cerr);
    printv(f0, cerr);
    printv(f1, cerr);
    printv(f2, cerr);*/

    return 0;
}