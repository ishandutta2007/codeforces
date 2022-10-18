#include <bits/stdc++.h>
#include <bits/extc++.h>

#define StarBurstStream ios_base::sync_with_stdio(false); cin.tie(0);
#define iter(a) a.begin(), a.end()
#define riter(a) a.rbegin(), a.rend()
#define lsort(a) sort(iter(a))
#define gsort(a) sort(riter(a))
#define eb emplace_back
#define ef emplace_front
#define pob pop_back()
#define pof pop_front()
#define mp make_pair
#define F first
#define S second
#define uni(a) a.resize(unique(iter(a)) - a.begin())
#define printv(a, b) { \
    for(auto pv : a) b << pv << " "; \
    b << "\n"; \
}

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;

using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<ld, ld>;

const ll MOD = 1000000007;
const ll MAX = 2147483647;

template<typename A, typename B>
ostream& operator<<(ostream& o, pair<A, B> p){
    return o << '(' << p.F << ',' << p.S << ')';
}

ll ifloor(ll a, ll b){
    if(b < 0) a *= -1, b *= -1;
    if(a < 0) return (a - b + 1) / b;
    else return a / b;
}

ll iceil(ll a, ll b){
    if(b < 0) a *= -1, b *= -1;
    if(a > 0) return (a + b - 1) / b;
    else return a/ b;
}

//vector<int> ta = {0, 0, 1, 2, 3};

int query(int i, int j, int k){
    cout << "? " << i << " " << j << " " << k << "\n" << flush;
    int r;
    cin >> r;
    //r = max({ta[i], ta[j], ta[k]}) - min({ta[i], ta[j], ta[k]});
    assert(r != -1);
    return r;
}

void answer(int i, int j){
    cout << "! " << i << " " << j << "\n" << flush;
}

void solve(){

    int n;
    cin >> n;
    //n = ta.size() - 1;

    int mx = query(1, 2, 3), mxp = 3;
    vector<int> q12(n + 1, -1), q13(n + 1, -1);
    q12[3] = mx;
    for(int i = 4; i <= n; i++){
        int t = query(1, 2, i);
        q12[i] = t;
        if(t <= mx) continue;
        mx = t;
        mxp = i;
    }

    int a1 = mxp;
    mx = query(1, a1, 2), mxp = 2;
    for(int i = 3; i <= n; i++){
        if(i == a1) continue;
        int t = query(1, a1, i);
        q13[i] = t;
        if(t <= mx) continue;
        mx = t;
        mxp = i;
    }

    if(mxp != 2){
        answer(a1, mxp);
        return;
    }

    int tmp = q12[a1];
    
    { // except a1
        int tmx = 0;
        for(int i = 3; i <= n; i++){
            if(i == a1) continue;
            tmx = max(tmx, q12[i]);
        }

        if(tmx == tmp){
            answer(1, 2);
            return;
        }
    }

    { // except 2
        int tmx = 0;
        for(int i = 3; i <= n; i++){
            if(i == a1) continue;
            tmx = max(tmx, q13[i]);
        }

        if(tmx == tmp){
            answer(1, a1);
            return;
        }
    }

    answer(2, a1);
}

int main(){
    StarBurstStream;

    int T;
    cin >> T;
    while(T--) solve();

    return 0;
}