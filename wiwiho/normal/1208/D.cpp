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
#define iceil(a) ((int)ceil((int)a))
#define ifloor(a) ((int)floor((int)a))

//#define TEST

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const ll MOD = 1000000007;
const ll MAX = (1LL << 40);

struct Node{
    ll mn = 0;
    ll tag = 0;

    ll realMin(){
        return mn + tag;
    }
};

typedef struct Node Node;

#define lc(x) ((x) * 2) + 1
#define rc(x) ((x) * 2) + 2

vector<Node> st;
vector<ll> s;

void pull(int id){
    st[id].mn = min(st[lc(id)].realMin(), st[rc(id)].realMin());
}

void push(int id){
    st[lc(id)].tag += st[id].tag;
    st[rc(id)].tag += st[id].tag;
    st[id].mn = st[id].realMin();
    st[id].tag = 0;
}

void build(int l, int r, int id){
    if(l == r){
        st[id].mn = s[l];
        return;
    }
    int m = (l + r) / 2;
    build(l, m, lc(id));
    build(m + 1, r, rc(id));
    pull(id);
}

void modify(int l, int r, ll v, int L, int R, int id){
    if(l == L && r == R){
        st[id].tag += v;
        return;
    }
    int M = (L + R) / 2;
    if(r <= M) modify(l, r, v, L, M, lc(id));
    else if(l > M) modify(l, r, v, M + 1, R, rc(id));
    else{
        modify(l, M, v, L, M, lc(id));
        modify(M + 1, r, v, M + 1, R, rc(id));
    }
    pull(id);
}

int query(int l, int r, int id){
    if(l == r) return l;
    int m = (l + r) / 2;
    push(id);
    if(st[rc(id)].realMin() == 0) return query(m + 1, r, rc(id));
    else return query(l, m, lc(id));
}

int main(){
    StarBurstStream

    int n;
    cin >> n;

    s.resize(n);
    st.resize(n * 4);

    for(int i = 0; i < n; i++) cin >> s[i];

    build(0, n - 1, 0);

    vector<int> ans(n);
    for(int i = 1; i <= n; i++){
        int lst = query(0, n - 1, 0);
        //cerr << i << " " << lst << "\n";
        ans[lst] = i;
        modify(lst, lst, MAX, 0, n - 1, 0);
        modify(lst, n - 1, -i, 0, n- 1, 0);
    }
    printv(ans, cout);

    return 0;
}