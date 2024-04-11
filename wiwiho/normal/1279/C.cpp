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
#define tiii tuple<int, int, int>
#define mt make_tuple
#define gt(t, i) get<i>(t)

//#define TEST

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const ll MOD = 1000000007;
const ll MAX = 2147483647;

vector<int> BIT;

int lowbit(int x){
    return x & (-x);
}

void modify(int x, int v){
    for(; x < BIT.size(); x += lowbit(x)) BIT[x] = BIT[x] + v;
}

int sum(int x){
    int ans = 0;
    for(; x > 0; x -= lowbit(x)) ans += BIT[x];
    return ans;
}

int main(){
    StarBurstStream

    int T;
    cin >> T;
    while(T--){

        int n, m;
        cin >> n >> m;

        BIT.clear();
        BIT.resize(n);

        ll ans = 0;
        vector<int> a(n + 1), b(n + 1);
        vector<pii> p(n + 1, mp(-1, -1));
        vector<bool> t(n + 1);
        for(int i = 1; i <= n; i++) cin >> a[i], p[a[i]].S = i;
        for(int i = 1; i <= m; i++) cin >> b[i], p[b[i]].F = i;

        lsort(p);

        for(int i = 1; i <= n; i++){
            if(p[i].F == -1) continue;
            if(t[p[i].S]){
                ans++;
                modify(p[i].S, 1);
                continue;
            }
            ans += (p[i].S - 1 - sum(p[i].S - 1)) * 2 + 1;
            for(int j = p[i].S - 1; j > 0 && !t[j]; j--)
                t[j] = true;
            //cerr << p[i].F << " " << p[i].S << " " << sum(p[i].S - 1) << "\n";
            //cerr << ans << "\n";
            modify(p[i].S, 1);
        }

        cout << ans << "\n";

    }

    return 0;
}