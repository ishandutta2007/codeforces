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
const ll MAX = (1LL << 60);

int main(){
    StarBurstStream

    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    vector<int> ans(n, -1);
    queue<int> q;
    vector<vector<int>> g(n);
    for(int i = 0; i < n; i++){
        if(i + a[i] < n && a[i + a[i]] % 2 != a[i] % 2){
            ans[i] = 1;
            q.push(i);
            continue;
        }
        if(i - a[i] >= 0 && a[i - a[i]] % 2 != a[i] % 2){
            ans[i] = 1;
            q.push(i);
            continue;
        }
        if(i + a[i] < n) g[i + a[i]].eb(i);
        if(i - a[i] >= 0) g[i - a[i]].eb(i);
    }

    /*for(int i = 0; i < n; i++){
        cerr << i << "  ";
        printv(g[i], cerr);
    }*/

    while(!q.empty()){
        int f = q.front();
        q.pop();
        for(int i : g[f]){
            if(ans[i] != -1) continue;
            //cerr << f << " " << i << "\n";
            ans[i] = ans[f] + 1;
            q.push(i);
        }
    }

    printv(ans, cout);

    return 0;
}