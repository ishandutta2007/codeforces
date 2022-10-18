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

int main(){
    StarBurstStream

    int h, w;
    cin >> h >> w;

    vector<string> a(h);
    for(int i = 0; i < h; i++) cin >> a[i];

    int x = 0, y = 0;
    vector<pii> dir = {mp(0, 1), mp(1, 0)};
    int ans = a[0][0] == '*';
    while(x != h || y != w){

        queue<pii> q;
        vector<vector<bool>> vst(h, vector<bool>(w));
        q.push(mp(x, y));
        vst[x][y] = true;
        pii p = mp(-1, -1);
        while(!q.empty()){
            pii now = q.front();
            q.pop();
            for(pii d : dir){
                int nx = now.F + d.F, ny = now.S + d.S;
                if(nx >= h || ny >= w || vst[nx][ny]) continue;
                q.push(mp(nx, ny));
                vst[nx][ny] = true;
                if(a[nx][ny] == '*'){
                    p = mp(nx, ny);
                    goto out;
                }
            }
        }
        out:;

        if(p == mp(-1, -1)){
            x = h; y = w;
        }
        else{
            x = p.F, y = p.S;
            ans++;
        }
    }

    cout << ans << "\n";

    return 0;
}