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

bool check(int n, vector<vector<int>>& s, int f){
    bool ta = false, tb = false;
    vector<int> ans(n);
    ans[0] = s[f][0];
    ans[1] = s[f][1];
    for(auto& i : s){
        bool a = false, b = false;
        for(int j : i){
            if(j == ans[0]) a = true;
            if(j == ans[1]) b = true;
        }
        if(a && !b) ta = true;
        if(!a && b) tb = true;
    }
    if(ta && tb) return false;

    if(ta) swap(ans[0], ans[1]);
    vector<int> id(n + 1, -1);
    id[ans[0]] = 0; id[ans[1]] = 1;

    for(int i = 2; i < n; i++){
        int found = 0;
        for(auto& j : s){
            int un = 0, mn = n, mx = -1;
            for(int k : j){
                if(id[k] == -1) un++;
                else mn = min(id[k], mn), mx = max(id[k], mx);
            }
            if(un == j.size()) continue;
            if(mx - mn + 1 != j.size() - un) return false;
            if(un != 1) continue;
            if(found) return false;

            for(int k : j){
                if(id[k] == -1){
                    found = k;
                    break;
                }
            }
        }
        if(!found) return false;
        id[found] = i;
        ans[i] = found;
    }

    printv(ans, cout);
    return true;
}

int main(){
    StarBurstStream

    int T;
    cin >> T;

    while(T--){

        int n;
        cin >> n;

        vector<vector<int>> s(n - 1);
        for(int i = 0; i < n - 1; i++){
            int k;
            cin >> k;
            s[i].resize(k);
            for(int j = 0; j < k; j++) cin >> s[i][j];
        }

        for(int i = 0; i < n - 1; i++){
            if(s[i].size() != 2) continue;
            if(check(n, s, i)) break;
        }

    }

    return 0;
}