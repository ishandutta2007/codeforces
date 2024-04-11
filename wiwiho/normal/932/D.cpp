//#define NDEBUG

#include <bits/stdc++.h>
#include <bits/extc++.h>

#define StarBurstStream ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define iter(a) a.begin(), a.end()
#define riter(a) a.rbegin(), a.rend()
#define lsort(a) sort(iter(a))
#define gsort(a) sort(riter(a))
#define pb(a) push_back(a)
#define eb(a) emplace_back(a)
#define pf(a) push_front(a)
#define pob pop_back()
#define pof pop_front()
#define mp(a, b) make_pair(a, b)
#define F first
#define S second
#define mt make_tuple
#define gt(t, i) get<i>(t)
#define iceil(a, b) (((a) + (b) - 1) / (b))
#define tomax(a, b) ((a) = max((a), (b)))
#define printv(a, b) {bool pvaspace=false; \
for(auto pva : a){ \
    if(pvaspace) b << " "; pvaspace=true;\
    b << pva;\
}\
b << "\n";}

//#define TEST

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<ld, ld>;
using tiii = tuple<int, int, int>;

const ll MOD = 1000000007;
const ll MAX = 2147483647;

template<typename A, typename B>
ostream& operator<<(ostream& o, pair<A, B> p){
    return o << '(' << p.F << ',' << p.S << ')';
}

vector<vector<ll>> anc, pw, sum;
vector<ll> w, d;

void add(int p, ll v){
    int now = anc.size();
//    cerr << now << " " << p << "\n";
    anc.eb(vector<ll>(25));
    pw.eb(vector<ll>(25));
    sum.eb(vector<ll>(25));
    w.eb(v);
    d.eb(d[p] + 1);


    anc[now][0] = p;
    pw[now][0] = w[p];
    sum[now][0] = w[p];

    for(int i = 1; i < 25; i++){
        anc[now][i] = anc[anc[now][i - 1]][i - 1];
        pw[now][i] = pw[anc[now][i - 1]][i - 1];
        sum[now][i] = sum[now][i - 1] + sum[anc[now][i - 1]][i - 1];
    }
//    printv(anc[now], cerr);
//    printv(pw[now], cerr);
//    printv(sum[now], cerr);
}

int s1(int now, ll x){
    if(w[now] >= x) return now;
    for(int i = 24; i >= 0; i--){
        if(pw[now][i] < x){
            now = anc[now][i];
        }
    }
    now = anc[now][0];
    return now;
}

int s2(int now, ll x){
    if(x < w[now]) return 0;
    int ans = 0;
    x -= w[now];
    for(int i = 24; i >= 0; i--){
        if((1 << i) > d[now]) continue;
        if(sum[now][i] <= x){
            x -= sum[now][i];
            now = anc[now][i];
            ans += 1 << i;
        }
    }
//    cerr << "test " << now << "\n";
    return ans + 1;
}

int main(){
    StarBurstStream

    int Q;
    cin >> Q;

    anc.eb(vector<ll>(25));
    pw.eb(vector<ll>(25, 1LL << 60));
    sum.eb(vector<ll>(25));
    w.eb(1LL << 60);
    d.eb(0);

    add(0, 0);

    ll lst = 0;

    while(Q--){

        int t;
        cin >> t;

        if(t == 1){
            ll r, w;
            cin >> r >> w;
            r = r ^ lst;
            w = w ^ lst;
            int pr = s1(r, w);
            add(pr, w);
        }
        else{
            ll r, x;
            cin >> r >> x;
            r = r ^ lst;
            x = x ^ lst;
            int ans = s2(r, x);
            cout << ans << "\n";
            lst = ans;
        }

    }

    return 0;
}