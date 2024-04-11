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
const ll MAX = 2147483647;

#define lc(x) ((x) * 2 + 1)
#define rc(x) ((x) * 2 + 2)

struct Node{
    int a = 0, b = 0, c = 0;
};

typedef struct Node Node;

vector<Node> st;
string s;

void pull(Node& a, Node& b, Node& ans){
    int t = min(a.b, b.c);
    ans.a = a.a + b.a + t;
    ans.b = a.b + b.b - t;
    ans.c = a.c + b.c - t;
}

void build(int l, int r, int id){
    if(l == r){
        if(s[l] == '(') st[id].b++;
        else st[id].c++;
        return;
    }
    int m = (l + r) / 2;
    build(l, m, lc(id));
    build(m + 1, r, rc(id));
    pull(st[lc(id)], st[rc(id)], st[id]);
}

void query(int l, int r, int L, int R, int id, Node& ans){
    if(l == L && r == R){
        ans = st[id];
        return;
    }
    int M = (L + R) / 2;
    if(r <= M) query(l, r, L, M, lc(id), ans);
    else if(l > M) query(l, r, M + 1, R, rc(id), ans);
    else{
        Node a, b;
        query(l, M, L, M, lc(id), a);
        query(M + 1, r, M + 1, R, rc(id), b);
        pull(a, b, ans);
    }
}

int main(){
    StarBurstStream

    cin >> s;

    int n = s.size();
    st.resize(n * 4);
    build(0, n - 1, 0);

    int m;
    cin >> m;
    while(m--){
        int l, r;
        cin >> l >> r;
        Node ans;
        query(l - 1, r - 1, 0, n - 1, 0, ans);
        cout << ans.a * 2 << "\n";
    }

    return 0;
}