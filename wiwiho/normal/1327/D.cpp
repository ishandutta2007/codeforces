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

bool check(vector<int>& t, int k, vector<int>& c){
    vector<int> st(k, -1);
    for(int i = 0; i < t.size(); i++){
        if(st[i % k] == -1) st[i % k] = c[t[i]];
        else if(st[i % k] != c[t[i]]) st[i % k] = -2;
    }
    for(int i = 0; i < k; i++) if(st[i % k] != -2) return true;
    return false;
}

int main(){
    StarBurstStream

    int T;
    cin >> T;

    while(T--){
        int n;
        cin >> n;

        vector<int> p(n + 1), c(n + 1);
        for(int i = 1; i <= n; i++) cin >> p[i];
        for(int i = 1; i <= n; i++) cin >> c[i];

        vector<bool> vst(n + 1);
        int ans = n;
        for(int i = 1; i <= n; i++){
//            cerr << "test\n";
            if(vst[i]) continue;
            vst[i] = true;

            vector<int> t;
            t.eb(i);
            int now = p[i];
            while(now != i){
//                cerr << now << " " << p[now] << "\n";
                vst[now] = true;
                t.eb(now);
                now = p[now];
            }
            printv(t, cerr);

            for(int j = 1; j * j <= t.size(); j++){
                if(t.size() % j) continue;
                if(check(t, j, c)) ans = min(j, ans);
                if(check(t, t.size() / j, c)) ans = min((int)t.size() / j, ans);
            }
        }

        cout << ans << "\n";
    }

    return 0;
}