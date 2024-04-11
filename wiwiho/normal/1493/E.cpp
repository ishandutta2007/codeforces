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
void minus1(string& s){
    for(int i = (int) s.size() - 1; i >= 0; i--){
        if(s[i] == '0') continue;
        s[i] = '0';
        for(int j = i + 1; j < s.size(); j++) s[j] = '1';
        return;
    }
    ok = false;
}

int main(){
    StarBurstStream

    int n;
    cin >> n;

    string l, r;
    cin >> l >> r;

    if(l == "0" && r == "0"){
        cout << "0\n";
        return 0;
    }

    if(l[0] == '0'){
        cout << string(n, '1') << "\n";
        return 0;
    }

    if(r.back() == '1'){
        cout << r << "\n";
        return 0;
    }

    string t = r;
    minus1(t);
    minus1(t);
    if(t >= l && ok) r.back() = '1';
    cout << r << "\n";

    return 0;
}