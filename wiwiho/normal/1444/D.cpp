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
#define ef(a) emplace_front(a)
#define pob pop_back()
#define pof pop_front()
#define mp(a, b) make_pair(a, b)
#define F first
#define S second
#define mt make_tuple
#define gt(t, i) get<i>(t)
#define iceil(a, b) (((a) + (b) - 1) / (b))
#define tomax(a, b) ((a) = max((a), (b)))
#define tomin(a, b) ((a) = min((a), (b)))
#define topos(a) ((a) = (((a) % MOD + MOD) % MOD))
#define uni(a) a.resize(unique(iter(a)) - a.begin())
#define printv(a, b) {bool pvaspace=false; \
for(auto pva : a){ \
    if(pvaspace) b << " "; pvaspace=true;\
    b << pva;\
}\
b << "\n";}

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

bool ok = true;

vector<vector<int>> qq(int n, vector<int>& a){
    int sum = 0;
    for(int i : a) sum += i;
    if(sum % 2){
        ok = false;
        return vector<vector<int>>();
    }
    vector<int> dp(sum / 2 + 1, -1);
    dp[0] = 0;
    for(int ii = 0; ii < n; ii++){
        int i = a[ii];
        for(int j = sum / 2; j >= i; j--){
            if(dp[j - i] == -1 || dp[j] != -1) continue;
            dp[j] = ii;
        }
    }

    if(dp[sum / 2] == -1){
        ok = false;
        return vector<vector<int>>();
    }

    vector<bool> b(n);
    int now = sum / 2;
    while(now != 0){
        b[dp[now]] = true;
        now -= a[dp[now]];
    }

    vector<vector<int>> t(2);
    for(int i = 0; i < n; i++){
        if(b[i]) t[0].eb(a[i]);
        else t[1].eb(a[i]);
    }
    return t;
}

bool comp(pii a, pii b){
    return a.S * b.F > a.F * b.S;
}

int main(){
    StarBurstStream

    int T;
    cin >> T;
    while(T--){

        int h;
        cin >> h;
        vector<int> l(h);
        for(int i = 0; i < h; i++) cin >> l[i];

        int v;
        cin >> v;
        vector<int> p(v);
        for(int i = 0; i < v; i++) cin >> p[i];

        if(h != v){
            cout << "No\n";
            continue;
        }

        ok = true;
        vector<vector<int>> th = qq(h, l);
        vector<vector<int>> tv = qq(v, p);
        if(!ok){
            cout << "No\n";
            continue;
        }

        if(th[0].size() < th[1].size()) th[0].swap(th[1]);
        if(tv[0].size() > tv[1].size()) tv[0].swap(tv[1]);

        vector<pii> a, b, c;
        for(int i = 0; i < tv[0].size(); i++){
            a.eb(mp(-th[0][i], tv[0][i]));
        }
        for(int i = 0; tv[0].size() + i < th[0].size(); i++){
            c.eb(mp(-th[0][tv[0].size() + i], -tv[1][i]));
        }
        for(int i = 0; i < th[1].size(); i++){
            b.eb(mp(th[1][i], -tv[1][th[0].size() - tv[0].size() + i]));
        }

        sort(iter(a), comp);
        sort(iter(b), comp);
        sort(iter(c), comp);

//        printv(a, cerr);
//        printv(b, cerr);
//        printv(c, cerr);

        cout << "Yes\n";
        int x = 0, y = 0;
        for(pii i : a){
            x += i.F;
            cout << x << " " << y << "\n";
            y += i.S;
            cout << x << " " << y << "\n";
        }
        for(pii i : b){
            x += i.F;
            cout << x << " " << y << "\n";
            y += i.S;
            cout << x << " " << y << "\n";
        }
        for(pii i : c){
            x += i.F;
            cout << x << " " << y << "\n";
            y += i.S;
            cout << x << " " << y << "\n";
        }

    }

    return 0;
}