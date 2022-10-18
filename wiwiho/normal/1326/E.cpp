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


struct Node{
    int v = 0, l = -1, r = -1, tag = 0;
    int rv(){
        return v + tag;
    }
};

struct minst{
    vector<Node> st;
    int cnt = 0;

    minst(int sz){
        st.resize(4 * sz);
    }

    int build(int l, int r, int id){
        if(id == -1) id = cnt++;
        if(l == r) return id;
        int m = (l + r) / 2;
        st[id].l = build(l, m, -1);
        st[id].r = build(m + 1, r, -1);
        return id;
    }

    void modify(int l, int r, int v, int L, int R, int id){
        if(l == L && r == R){
            st[id].tag += v;
            return;
        }
        int M = (L + R) / 2;
        if(r <= M) modify(l, r, v, L, M, st[id].l);
        else if(l > M) modify(l, r, v, M + 1, R, st[id].r);
        else{
            modify(l, M, v, L, M, st[id].l);
            modify(M + 1, r, v, M + 1, r, st[id].r);
        }
        st[id].v = min(st[st[id].l].rv(), st[st[id].r].rv());
    }

    void push(int id){
        st[st[id].l].tag += st[id].tag;
        st[st[id].r].tag += st[id].tag;
        st[id].v = st[id].rv();
        st[id].tag = 0;
    }

    int query(int l, int r, int L, int R, int id){
        if(l == L && r == R) return st[id].rv();
        push(id);
        int M = (L + R) / 2;
        if(r <= M) return query(l, r, L, M, st[id].l);
        else if(l > M) return query(l, r, M + 1, R, st[id].r);
        else{
            return min(query(l, M, L, M, st[id].l), query(M + 1, r, M + 1, R, st[id].r));
        }
    }
};

vector<int> p;

int maxarg(int a, int b){
    if(p[a] > p[b]) return a;
    else return b;
}

struct maxst{
    vector<Node> st;
    int cnt = 0;

    maxst(int sz){
        st.resize(4 * sz);
    }

    int build(int l, int r, int id){
        if(id == -1) id = cnt++;
        if(l == r){
            st[id].v = l;
            return id;
        }
        int m = (l + r) / 2;
        st[id].l = build(l, m, -1);
        st[id].r = build(m + 1, r, -1);
        st[id].v = maxarg(st[st[id].l].v, st[st[id].r].v);
        return id;
    }

    void modify(int x, int L, int R, int id){
        if(L == R){
            p[x] = 0;
            return;
        }
        int M = (L + R) / 2;
        if(x <= M) modify(x, L, M, st[id].l);
        else if(x > M) modify(x, M + 1, R, st[id].r);
        st[id].v = maxarg(st[st[id].l].v, st[st[id].r].rv());
    }

    int query(int l, int r, int L, int R, int id){
        if(l == L && r == R) return st[id].v;
        int M = (L + R) / 2;
        if(r <= M) return query(l, r, L, M, st[id].l);
        else if(l > M) return query(l, r, M + 1, R, st[id].r);
        else{
            return maxarg(query(l, M, L, M, st[id].l), query(M + 1, r, M + 1, R, st[id].r));
        }
    }
};

int main(){
    StarBurstStream

    int n;
    cin >> n;

    minst st1(n);
    vector<int> q(n + 1);
    p.resize(n + 1);

    for(int i = 1; i <= n; i++) cin >> p[i];
    for(int i = 1; i <= n; i++) cin >> q[i];
    maxst st2(n);

    st1.build(1, n, -1);
    st2.build(1, n, -1);

    vector<int> ans(n);
    for(int i = 1; i <= n; i++){
        ans[i - 1] = p[st2.query(1, n, 1, n, 0)];
        st1.modify(q[i], n, -1, 1, n, 0);

//        for(int j = 1; j <= n; j++) cerr << st1.query(j, j, 1, n, 0) << " ";
//        cerr << "\n";
//        for(int j = 1; j <= n; j++) cerr << st1.query(1, j, 1, n, 0) << " ";
//        cerr << "\n";

        int l = q[i], r = n;
        while(l < r){
            int m = (l + r) / 2;
            if(st1.query(1, m, 1, n, 0) < 0) r = m;
            else l = m + 1;
        }
        int pos = st2.query(1, l, 1, n, 0);
//        cerr << i << " " << l << " " << pos << "\n";

        st1.modify(pos, n, 1, 1, n, 0);
        st2.modify(pos, 1, n, 0);
    }

    printv(ans, cout);

    return 0;
}