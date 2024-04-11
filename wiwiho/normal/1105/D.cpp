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

int main(){
    StarBurstStream

    int n, m, p;
    cin >> n >> m >> p;

    vector<ll> s(p);
    for(int i = 0; i < p; i++) cin >> s[i];

    vector<queue<pair<pii, int>>> q(p);
    vector<string> a(n + 2);
    a[0] = a[n + 1] = string(m + 2, '#');
    vector<int> ans(p);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        a[i] = '#' + a[i] + '#';
        for(int j = 1; j <= m; j++){
            if('1' <= a[i][j] && a[i][j] <= '9'){
                q[a[i][j] - '1'].push(mp(mp(i, j), 0));
                ans[a[i][j] - '1']++;
            }
        }
    }
    vector<pii> d = {mp(0, 1), mp(1, 0), mp(0, -1), mp(-1, 0)};

    for(int r = 0; ; r++){
        bool nxt = false;
        for(int i = 0; i < p; i++){
            while(!q[i].empty() && q[i].front().S < (r + 1) * s[i]){
                pii now = q[i].front().F;
                int mv = q[i].front().S;
                q[i].pop();
                if(a[now.F][now.S] != '1' + i) continue;
                for(pii j : d){
                    int nx = now.F + j.F, ny = now.S + j.S;
                    if(a[nx][ny] != '.') continue;
                    a[nx][ny] = '1' + i;
                    q[i].push(mp(mp(nx, ny), mv + 1));
                    ans[i]++;
                    nxt = true;
                }
            }
        }
        if(!nxt) break;
    }
    printv(ans, cout);

    return 0;
}