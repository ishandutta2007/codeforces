//#define NDEBUG

#include <bits/stdc++.h>

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
#define B back()
#define FR front()
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
#define iceil(a) ((int)ceil(a))
#define ifloor(a) ((int)floor(a))

//#define TEST

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const ll MOD = 1000000007;
const ll MAX = 2147483647;

int main(){
    StarBurstStream

    int n;
    cin >> n;

    vector<vector<int>> t(n + 1);
    vector<tuple<int, int, int>> q(n - 2);
    for(int i = 0; i < n - 2; i++){
        cin >> get<0>(q[i]) >> get<1>(q[i]) >> get<2>(q[i]);
        t[get<0>(q[i])].eb(i);
        t[get<2>(q[i])].eb(i);
        t[get<1>(q[i])].eb(i);
    }

    vector<bool> c(n + 1);
    vector<int> ans;

    for(int i = 1; i <= n; i++){
        if(t[i].size() != 1) continue;
        ans.eb(i);
        c[i] = true;
        int nxt = 0;
        if(t[get<0>(q[t[i][0]])].size() == 2) nxt = get<0>(q[t[i][0]]);
        if(t[get<1>(q[t[i][0]])].size() == 2) nxt = get<1>(q[t[i][0]]);
        if(t[get<2>(q[t[i][0]])].size() == 2) nxt = get<2>(q[t[i][0]]);
        ans.eb(nxt);
        c[nxt] = true;
        break;
    }

    while(ans.size() < n){
        int lst = ans.back();
        for(int i : t[lst]){
            vector<int> nxt;
            if(!c[get<0>(q[i])]) nxt.eb(get<0>(q[i]));
            if(!c[get<1>(q[i])]) nxt.eb(get<1>(q[i]));
            if(!c[get<2>(q[i])]) nxt.eb(get<2>(q[i]));
            if(nxt.size() == 1){
                ans.eb(nxt[0]);
                c[nxt[0]] = true;
                break;
            }
        }
    }

    printv(ans, cout);

    return 0;
}