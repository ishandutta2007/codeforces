#include <bits/stdc++.h>

#define StarBurstStream ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define iter(a) a.begin(), a.end()
#define riter(a) a.rbegin(), a.rend()
#define lsort(a) sort(iter(a))
#define gsort(a) sort(riter(a))
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define pf(a) push_front(a)
#define pob pop_back()
#define pof pop_front()
#define fr front()
#define po pop()
#define ba back()
#define F first
#define S second
#define printv(a, b) {bool pvaspace=false; \
for(auto pva : a){ \
    if(pvaspace) b << " "; pvaspace=true;\
    b << pva;\
}\
b << "\n";}
#define pii pair<int, int>
#define pll pair<ll, ll>

//#define TEST

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const ll MOD = 1000'000'007;
const ll MAX = 1000000001;

int main(){
    StarBurstStream

    int n;
    cin >> n;

    vector<int> h1(n), h2(n);
    for(int i = 0; i < n; i++){
        cin >> h1[i];
    }
    for(int i = 0; i < n; i++){
        cin >> h2[i];
    }

    vector<ll> dp1(n), dp2(n);
    dp1[0] = h1[0];
    dp2[0] = h2[0];
    ll ans = max(dp1[0], dp2[0]);
    for(int i = 1; i < n; i++){

        ll t1 = i - 2 >= 0 ? dp2[i - 2] : 0;
        dp1[i] = max(t1, dp2[i - 1]) + h1[i];
        ans = max(ans, dp1[i]);

        ll t2 = i - 2 >= 0? dp1[i - 2] : 0;
        dp2[i] = max(t2, dp1[i - 1]) + h2[i];
        ans = max(ans, dp2[i]);

    }

    //printv(dp1, cerr);
    //printv(dp2, cerr);

    cout << ans << "\n";

    return 0;
}