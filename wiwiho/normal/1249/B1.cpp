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

vector<bool> visit;
vector<int> g;
vector<int> ans;
int dfs(int now, int sz){
    visit[now] = true;
    int t;
    if(!visit[g[now]]) t = dfs(g[now], sz + 1);
    else t = sz;
    ans[now] = t;
    return t;
}

int main(){
    StarBurstStream

    int q;
    cin >> q;
    while(q--){

        int n;
        cin >> n;
        visit.clear(); visit.resize(n + 1);
        g.clear(); g.resize(n + 1);
        ans.clear(); ans.resize(n + 1);

        for(int i = 1; i <= n; i++){
            cin >> g[i];
        }

        for(int i = 1; i <= n; i++){
            if(!visit[i]) dfs(i, 1);
        }

        for(int i = 1; i <= n; i++){
            cout << ans[i] << " ";
        }
        cout << "\n";

    }


    return 0;
}