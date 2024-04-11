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

vector<set<int>> g;
vector<int> ans;
vector<bool> vst;
bool flag = true;

void dfs(int now){
    ans.eb(now);
    vst[now] = true;
    if(g[now].size() > 2){
        flag = false;
        return;
    }

    for(int i : g[now]){
        if(vst[i]) continue;
        dfs(i);
    }
}

int main(){
    StarBurstStream

    int T;
    cin >> T;

    while(T--){

        ll n, m;
        cin >> n >> m;

        vector<int> cnt(64);
        for(int i = 0 ; i < m; i++){
            int a;
            cin >> a;
            cnt[__lg(a)]++;
        }

        int ans = 0;
        for(ll i = 0; n > 0; i++, n >>= 1){
            if(!(n & 1)){
                cnt[i + 1] += cnt[i] / 2;
                continue;
            }

            if(cnt[i] > 0){
                cnt[i]--;
                cnt[i + 1] += cnt[i] / 2;
                continue;
            }

            ll j = i;
            for(; j < 64 && !cnt[j]; j++);
            if(j == 64){
                ans = -1;
                break;
            }
            for(; j > i; j--){
                cnt[j]--;
                cnt[j - 1] += 2;
                ans++;
            }
        }

        cout << ans << "\n";

    }

    return 0;
}