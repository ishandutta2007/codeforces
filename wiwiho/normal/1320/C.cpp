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


template<typename T>
struct Node{
    T v = 0, tag = 0;
    int l = -1, r = -1;
    T rv(){
        return v + tag;
    }
    void addTag(T t){
        tag += t;
    }
};

template<typename T>
T pullValue(T b, T c){
    return max(b, c);
}

template<typename T>
void pull(Node<T> &a, Node<T> &l, Node<T> &r){
    a.v = pullValue(l.rv(), r.rv());
}

template<typename T>
void push(Node<T> &a, Node<T> &l, Node<T> &r){
    l.addTag(a.tag);
    r.addTag(a.tag);
    a.v = a.rv();
    a.tag = 0;
}

template<typename T>
struct SegmentTree{
    vector<Node<T>> st;
    int cnt = 0;

    explicit SegmentTree(int sz){
        st.resize(4 * sz);
    }

    int build(int l, int r, vector<T>& o){
        int id = cnt++;
        if(l == r){
            st[id].v = o[l];
            return id;
        }
        int m = (l + r) / 2;
        st[id].l = build(l, m, o);
        st[id].r = build(m + 1, r, o);
        pull(st[id], st[st[id].l], st[st[id].r]);
        return id;
    }

    void modify(int l, int r, int v, int L, int R, int id){
        if(l == L && r == R){
            st[id].addTag(v);
            return;
        }
        int M = (L + R) / 2;
        if(r <= M) modify(l, r, v, L, M, st[id].l);
        else if(l > M) modify(l, r, v, M + 1, R, st[id].r);
        else{
            modify(l, M, v, L, M, st[id].l);
            modify(M + 1, r, v, M + 1, R, st[id].r);
        }
        pull(st[id], st[st[id].l], st[st[id].r]);
    }

    T query(int l, int r, int L, int R, int id){
        if(l == L && r == R) return st[id].rv();
        push(st[id], st[st[id].l], st[st[id].r]);
        int M = (L + R) / 2;
        if(r <= M) return query(l, r, L, M, st[id].l);
        else if(l > M) return query(l, r, M + 1, R, st[id].r);
        else{
            return pullValue(query(l, M, L, M, st[id].l), query(M + 1, r, M + 1, R, st[id].r));
        }
    }

};


bool comp(pii a, pii b){
    return a.F > b.F ? true : (a.F < b.F ? false : a.S < b.S);
}

int main(){
    StarBurstStream

    int n, m, p;
    cin >> n >> m >> p;

    vector<pii> t(n);
    for(int i = 0; i < n; i++) cin >> t[i].F >> t[i].S;
    sort(iter(t), comp);

    vector<pii> a;
    int tmp = MAX;
    for(int i = 0; i < n; i++){
        if(t[i].S < tmp){
            a.eb(t[i]);
            tmp = t[i].S;
        }
    }

    t.clear();
    t.resize(m);
    for(int i = 0; i < m; i++) cin >> t[i].F >> t[i].S;
    sort(iter(t), comp);

    vector<pii> b;
    tmp = MAX;
    for(int i = 0; i < m; i++){
        if(t[i].S < tmp){
            b.eb(t[i]);
            tmp = t[i].S;
        }
    }

    n = a.size();
    m = b.size();
    lsort(a);
    lsort(b);

//    printv(a, cerr);
//    printv(b, cerr)

    SegmentTree<ll> st(m);
    vector<ll> tmpv(m, 0);
    st.build(0, m - 1, tmpv);

    for(int i = 0; i < m; i++){
        if(i == 0) st.modify(i, m - 1, -b[i].S, 0, m - 1, 0);
        else st.modify(i, m - 1, b[i - 1].S - b[i].S, 0, m -1, 0);
    }

//    for(int i = 0 ; i < m; i++) cerr << st.query(i, i, 0, m - 1, 0) << "\n";

    vector<pair<pii, int>> xyz(p);
    for(int i = 0; i < p; i++) cin >> xyz[i].F.F >> xyz[i].F.S >> xyz[i].S;

    lsort(xyz);
//    printv(xyz, cerr);
    ll ans = -a[0].S - b[0].S;
    for(int i = 0; i < p ; i++){
        if(upper_bound(iter(a), mp(xyz[i].F.F, (int)MAX)) == a.end() || upper_bound(iter(b), mp(xyz[i].F.S, (int)MAX)) == b.end()) continue;
        ll now = -upper_bound(iter(a), mp(xyz[i].F.F, (int)MAX))->S;
        int tt = upper_bound(iter(b), mp(xyz[i].F.S, (int)MAX)) - b.begin();
        st.modify(tt, m - 1, xyz[i].S, 0, m - 1, 0);

//        cerr << i << " " << now << "  ";
//        for(int i = 0 ; i < m; i++) cerr << st.query(i, i, 0, m - 1, 0) << " ";
//        cerr << "\n";

        now += st.query(0, m - 1, 0, m - 1, 0);
        ans = max(ans, now);
    }

    cout << ans << "\n";

    return 0;
}