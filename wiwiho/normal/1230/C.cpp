//#define NDEBUG

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
#define modadd(a, b) (((a % MOD) + (b % MOD)) % MOD)
#define modtimes(a, b) (((a % MOD) * (b % MOD)) % MOD)

//#define TEST

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const ll MOD = 1000000007;
const ll MAX = 2147483647;

vector<int> p;
vector<pii> e;

int six[8] = {0, 6, 36, 216, 1296, 7776, 46656, 279936};

int check(){
    vector<vector<int>> b(7, vector<int>(7));
    int cnt = 0;
    for(pii ed : e){
        pii t = mp(max(p[ed.F], p[ed.S]), min(p[ed.F], p[ed.S]));
        if(!b[t.F][t.S]){
            cnt++;
            b[t.F][t.S] = true;
        }
    }
    return cnt;
}

int main(){
    StarBurstStream

    int n, m;
    cin >> n >> m;

    e.resize(m);
    for(int i = 0; i < m; i++){
        cin >> e[i].F >> e[i].S;
        e[i].F--; e[i].S--;
    }

    int ans = 0;
    for(int i = 0; i < six[n]; i++){
        p.clear();
        int ti = i;
        vector<int> cnt(6);
        for(int j = 1; j <= n; j++){
            int t = ti % 6;
            ti /= 6;
            p.pb(t);
            cnt[t]++;
            if(cnt[t] > 2) goto next;
        }
        ans = max(ans, check());
        next:;
    }
    cout << ans << "\n";
    //cerr << c << "\n";

    return 0;
}