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
    int dpt = 0;
    vector<int> c;
    multiset<int> s;
    bool f = false;
    Node(){
        c.resize(26, -1);
    }
};

vector<Node> tr(200001);
int ts = 1;

int ed = -1;
int add(string& s, int now, int id){
    if(id == -1){
        id = ts++;
        tr[id].dpt = now;
    }
    if(now == s.size()){
        ed = id;
        tr[id].f = true;
        tr[id].s.insert(now);
        return id;
    }
    tr[id].c[s[now] - 'a'] = add(s, now + 1, tr[id].c[s[now] - 'a']);
    return id;
}

void mergeset(multiset<int>& a, multiset<int>& b){
    if(a.size() < b.size()) a.swap(b);
    for(int i : b) a.insert(i);
}

void dfs(int now){
    for(int i : tr[now].c){
        if(i == -1) continue;
        dfs(i);
        mergeset(tr[now].s, tr[i].s);
    }
    if(tr[now].f || now == 0) return;
//    cerr << now << "  ";
    tr[now].s.erase(prev(tr[now].s.end()));
    tr[now].s.insert(tr[now].dpt);
//    printv(tr[now].s, cerr);
}

int main(){
    StarBurstStream

    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        ed = -1;
        add(s, 0, 0);
    }

    dfs(0);

//    printv(tr[0].s, cerr);

    int ans = 0;
    for(int i : tr[0].s){
//        cerr << i << "\n";
        ans += i;
    }
    cout << ans << "\n";

    return 0;
}