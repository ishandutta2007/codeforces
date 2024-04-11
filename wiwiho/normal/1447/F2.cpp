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

    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> cnt(n + 1);
    for(int i = 0; i < n; i++) cin >> a[i], cnt[a[i]]++;
    int f = max_element(iter(cnt)) - cnt.begin();
    int sn = ceil(sqrt(n));

    vector<vector<int>> pos(n + 1);
    vector<int> from(n), to(n);

    int p = -1;
    for(int i = 0; i < n; i++){
        pos[a[i]].eb(i);
        if(a[i] == f){
            p++;
            continue;
        }
        from[i] = max(0, p - sn);
    }
    p = (int)pos[f].size() - 1;
    for(int i = n - 1; i >= 0; i--){
        if(a[i] == f){
            p--;
            continue;
        }
        to[i] = min((int)pos[f].size() - 1, p + sn);
    }

    int ans = 0;
    vector<int> t(2 * n + 1, n);
    t[n] = -1;
    for(int i = 1; i <= n; i++){
        if(i == f) continue;

        if(pos[i].size() > sn){

            t[n] = -1;
            int now = 0, c = 0;
            for(int j = 0; j < n; j++){
                if(a[j] == f) now++;
                if(a[j] == i) c++;
                int qq = c - now;
                if(t[qq + n] != n) ans = max(ans, j - t[qq + n]);
                else t[qq + n] = j;
            }
            now = 0; c = 0;
            for(int j = 0; j < n; j++){
                if(a[j] == f) now++;
                if(a[j] == i) c++;
                int qq = c - now;
                if(qq != 0) t[qq + n] = n;
            }

            continue;
        }

        vector<int> tmp;
        int k = 0;
        tmp.eb(-1);
        for(int jj = 0; jj < pos[i].size(); jj++){
            int j = pos[i][jj];
            for(k = max(k, from[j]); k <= to[j] && pos[f][k] < j; k++){
                tmp.eb(pos[f][k]);
            }
            tmp.eb(j);
            for(k = max(k, from[j]); k <= to[j] && (jj == pos[i].size() - 1 || pos[f][k] < pos[i][jj + 1]); k++){
                tmp.eb(pos[f][k]);
            }
        }
        tmp.eb(n);
//        cerr << i << "  ";
//        printv(tmp, cerr);

        int now = 0, c = 0;
        t[0] = -1;
        for(int jj = 1; jj + 1 < tmp.size(); jj++){
            int j = tmp[jj];
            if(a[j] == f) now++;
            else c++;
            int qq = c - now;
            if(t[qq + n] != n){
                ans = max(ans, tmp[jj + 1] - t[qq + n] - 1);
//                cerr << i << " " << j << " " << t[qq] << " " << tmp[i][jj + 1] - t[qq] - 1 << "\n";
            }
            else t[qq + n] = j;
        }
        now = 0; c = 0;
        for(int jj = 1; jj + 1 < tmp.size(); jj++){
            int j = tmp[jj];
            if(a[j] == f) now++;
            else c++;
            int qq = c - now;
            if(qq != 0) t[qq + n] = n;
        }

    }

    cout << ans << "\n";

    return 0;
}