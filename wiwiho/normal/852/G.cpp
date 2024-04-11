//#define NDEBUG

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
#define pob pop_back()
#define pof pop_front()
#define mp(a, b) make_pair(a, b)
#define F first
#define S second
#define mt make_tuple
#define gt(t, i) get<i>(t)
#define iceil(a, b) (((a) + (b) - 1) / (b))
#define tomax(a, b) ((a) = max((a), (b)))
#define printv(a, b) {bool pvaspace=false; \
for(auto pva : a){ \
    if(pvaspace) b << " "; pvaspace=true;\
    b << pva;\
}\
b << "\n";}

//#define TEST

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
    vector<int> c;
    int cnt = 0;
    Node(){
        c.resize(5, -1);
    }
};

vector<Node> tr;
int ts = 0;

int add(string& s, int now, int id){
    if(id == -1) id = ts++;
    if(now == s.size()){
        tr[id].cnt++;
        return id;
    }
    int nxt = s[now] - 'a';
    tr[id].c[nxt] = add(s, now + 1, tr[id].c[nxt]);
    return id;
}

set<int> ans;
void fnd(string& s, int now, int id){
    if(id == -1) return;
    if(now == s.size()){
        ans.insert(id);
        return;
    }
    for(int i = 0; i < 5; i++){
        if(s[now] != '?' && s[now] - 'a' != i) continue;
        fnd(s, now + 1, tr[id].c[i]);
    }
    if(s[now] == '?') fnd(s, now + 1, id);
}

int main(){
    StarBurstStream

    int n, m;
    cin >> n >> m;

    int rt = -1;
    tr.resize(5000000);

    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        rt = add(s, 0, rt);
    }

    for(int i = 0; i < m; i++){
        ans.clear();
        string s;
        cin >> s;
        fnd(s, 0, rt);
        int t = 0;
        for(int id : ans) t += tr[id].cnt;
        cout << t << "\n";
    }

    return 0;
}