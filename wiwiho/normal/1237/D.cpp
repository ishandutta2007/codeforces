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

#define lowbit(x) (x&-x)

vector<int> BIT;

void modify(int x, int v){
    for(; x < BIT.size(); x += lowbit(x)){
        BIT[x] = min(BIT[x], v);
    }
}

int query(int x){
    int ans = MAX;
    for(; x > 0; x -= lowbit(x)){
        ans = min(ans, BIT[x]);
    }
    return ans;
}

int main(){
    StarBurstStream

    int n;
    cin >> n;
    vector<int> a(3 * n);
    set<int> ts;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        a[i + n] = a[i];
        a[i + n + n] = a[i];
        ts.insert(a[i]);
    }
    vector<int> b(1);
    b.reserve(ts.size());
    for(int i : ts) b.eb(i);

    BIT.resize(b.size(), MAX);

    int lst = MAX;
    vector<int> ans(n);
    for(int i = 3 * n - 1; i >= 0; i--){
        auto it = lower_bound(iter(b), iceil((double) a[i] / 2));
        lst = min(lst, (int)(it == b.begin() ? MAX : query(it - b.begin() - 1)));
        //cerr << i << " " << lst << "\n";
        if(i < n) ans[i] = lst == MAX ? -1 : lst - i;
        modify(lower_bound(iter(b), a[i]) - b.begin(), i);
    }
    printv(ans, cout);

    return 0;
}