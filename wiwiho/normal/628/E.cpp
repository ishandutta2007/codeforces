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

int lowbit(int x){
    return x & - x;
}

struct BIT{

    vector<int> b;
    BIT(int sz){
        b.resize(sz + 1);
    }

    void modify(int x){
        for(; x < b.size(); x += lowbit(x)){
            b[x]++;
        }
    }

    int query(int x){
        int ans = 0;
        for(; x > 0; x -= lowbit(x)){
            ans += b[x];
        }
        return ans;
    }

};

int main(){
    StarBurstStream

    int n, m;
    cin >> n >> m;

    vector<BIT> bit(n + m + 2, BIT(m));

    vector<vector<pii>> pos(m + 1);

    vector<vector<int>> l(n + 2, vector<int>(m + 2)), r(n + 2, vector<int>(m + 2)), ld(n + 2, vector<int>(m + 2));

    vector<string> a(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        a[i] = " " + a[i];
        for(int j = 1; j <= m; j++){
            if(a[i][j] == 'z') l[i][j] = l[i][j - 1] + 1;
        }
    }

    for(int i = n; i >= 1; i--){
        for(int j = m; j >= 1; j--){
            if(a[i][j] != 'z') continue;
            r[i][j] = r[i][j + 1];
            ld[i][j] = ld[i + 1][j - 1];
            r[i][j]++; ld[i][j]++;
            pos[j + r[i][j] - 1].eb(mp(i, j));
        }
    }

//    for(int i = 1; i <= n; i++) printv(l[i], cerr);
//    for(int i = 1; i <= n; i++) printv(r[i], cerr);
//    for(int i = 1; i <= n; i++) printv(ld[i], cerr);

    ll ans = 0;
    for(int i = m; i >= 1; i--){
        for(pii j : pos[i]){
            bit[j.F + j.S].modify(j.S);
        }
        for(int j = 1; j <= n; j++){
            int t = min(l[j][i], ld[j][i]);
//            cerr << j << " " << i << " " << bit[i + j].query(i) - bit[i + j].query(i - t) << "\n";
            ans += bit[i + j].query(i) - bit[i + j].query(i - t);
        }
    }

    cout << ans << "\n";

    return 0;
}