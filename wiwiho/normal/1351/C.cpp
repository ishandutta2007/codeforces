//#define NDEBUG

#include <bits/stdc++.h>
#include <bits/extc++.h>

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
#define printv(a, b) {bool pvaspace=false; \
for(auto pva : a){ \
    if(pvaspace) b << " "; pvaspace=true;\
    b << pva;\
}\
b << "\n";}
#define pii pair<int, int>
#define pll pair<ll, ll>
#define tiii tuple<int, int, int>
#define mt make_tuple
#define gt(t, i) get<i>(t)
#define iceil(a, b) ((a) / (b) + !!((a) % (b)))

//#define TEST

typedef long long ll;
typedef unsigned long long ull;

using namespace std;
using namespace __gnu_pbds;

const ll MOD = 1000000007;
const ll MAX = 2147483647;

template<typename A, typename B>
ostream& operator<<(ostream& o, pair<A, B> p){
    return o << '(' << p.F << ',' << p.S << ')';
}

pii operator+(pii a, pii b){
    return mp(a.F + b.F, a.S + b.S);
}

int main(){
    StarBurstStream

    int T;
    cin >> T;

    map<char, pii> d;
    d['S'] = mp(-1, 0);
    d['N'] = mp(1, 0);
    d['E'] = mp(0, 1);
    d['W'] = mp(0, -1);

    while(T--){
        string str;
        cin >> str;

        set<pair<pii, pii>> s;
        pii now;

        int ans = 0;
        for(char i : str){
            pii nxt = now + d[i];
            if(s.find(mp(min(now, nxt), max(now, nxt))) == s.end()) ans += 5;
            else ans++;
            s.insert(mp(min(now, nxt), max(now, nxt)));
            now = nxt;
        }

        cout << ans << "\n";

    }

    return 0;
}