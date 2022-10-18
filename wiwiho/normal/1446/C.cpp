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

struct Node{
    int z = -1, o = -1;
};

vector<Node> tr;
int ts = 1;

int add(string& s, int now, int id){
    if(id == -1) id = ts++;
    if(now == s.size()){
        return id;
    }
    if(s[now] == '0') tr[id].z = add(s, now + 1, tr[id].z);
    else tr[id].o = add(s, now + 1, tr[id].o);
    return id;
}

int ans = 0;

int dfs(int now, int d){
    if(d == 30) return 1;
    if(tr[now].o == -1) return dfs(tr[now].z, d + 1);
    else if(tr[now].z == -1) return dfs(tr[now].o, d + 1);
    else{
        int a = dfs(tr[now].o, d + 1);
        int b = dfs(tr[now].z, d + 1);
        if(a > b) swap(a, b);
        ans += a - 1;
        return 1 + b;
    }
}

int main(){
    StarBurstStream

    int n;
    cin >> n;
    tr.resize(n * 35);

    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        bitset<30> b(a);
        string s = b.to_string();
        add(s, 0, 0);
    }

    dfs(0, 0);

    cout << ans << "\n";

    return 0;
}