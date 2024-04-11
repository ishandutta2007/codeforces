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
ostream &operator<<(ostream &o, pair<A, B> p){
    return o << '(' << p.F << ',' << p.S << ')';
}

const ll inf = 1LL << 60;

template<typename T>
struct Line{
    mutable T a, b, r = 0;

    Line(T a, T b) : a(a), b(b){}

    bool operator<(Line<T> l)const{
        return a < l.a;
    }

    bool operator<(T v)const{
        return r < v;
    }
};

template<typename T>
T divfloor(T a, T b){
    return a / b - ((a ^ b) < 0 && a % b);
}

template<typename T>
struct DynamicHull{
    multiset<Line<T>, less<>> s;

    int size(){
        return s.size();
    }

    bool intersect(typename set<Line<T>>::iterator a, typename set<Line<T>>::iterator &b){
        if(b == s.end()){
            a->r = inf;
            return false;
        }
        if(a->a == b->a){
            if(a->b > b->b) a->r = inf;
            else a->r = -inf;
        }
        else{
            a->r = divfloor(b->b - a->b, a->a - b->a);
        }
        return a->r >= b->r;
    }

    void insert(T a, T b){
        Line<T> l(a, b);
        auto it = s.insert(l), after = next(it), before = it;
        while(intersect(it, after)) after = s.erase(after);
        if(before != s.begin() && intersect(--before, it)){
            it = s.erase(it);
            intersect(before, it);
        }
        while((it = before) != s.begin() && (--before)->r >= it->r) intersect(before, it = s.erase(it));
    }

    T query(T v){
        Line<T> l = *s.lower_bound(v);
        return l.a * v + l.b;
    }
};

vector<vector<int>> g;
vector<ll> a, b;

vector<DynamicHull<ll> *> dh;
vector<ll> ans;

void dfs(int now, int p){
    int tmp = -1;

    for(int i : g[now]){
        if(i == p) continue;
        dfs(i, now);
        if(tmp == -1 || dh[i]->size() > dh[tmp]->size()){
            tmp = i;
            dh[now] = dh[i];
        }
    }
    if(tmp == -1) dh[now] = new DynamicHull<ll>();

    for(int i : g[now]){
        if(i == p || i == tmp) continue;
        for(auto l : dh[i]->s){
            dh[now]->insert(l.a, l.b);
        }
    }

    if(tmp == -1) ans[now] = 0;
    else ans[now] = -dh[now]->query(a[now]);
    //cerr << now << " " << tmp << "\n";

    dh[now]->insert(-b[now], -ans[now]);

    //for(auto i : dh[now]->s){
    //    cerr << i.a << ' ' << i.b << ' ' << i.r << "\n";
    //}
}

int main(){
    StarBurstStream

    int n;
    cin >> n;

    a.resize(n + 1);
    b.resize(n + 1);
    g.resize(n + 1);
    dh.resize(n + 1);
    ans.resize(n + 1);

    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> b[i];

    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        g[u].eb(v);
        g[v].eb(u);
    }

    dfs(1, 1);

    ans.erase(ans.begin());
    printv(ans, cout);

    return 0;
}