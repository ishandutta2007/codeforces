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

#define lc(a) a * 2 + 1
#define rc(a) a * 2 + 2

struct Node{
    ll max = 0;
    ll min = 0;
    ll tag = 0;
    ll realMax(){
        return max + tag;
    }
    ll realMin(){
        return min + tag;
    }
};

typedef struct Node Node;

vector<Node> st;

void build(int l, int r, int node){
    if(l == r){
        return;
    }
    int m = (l + r) / 2;
    build(l, m, lc(node));
    build(m + 1, r, rc(node));
    st[node].max = max(st[lc(node)].max, st[rc(node)].max);
    st[node].min = min(st[lc(node)].min, st[rc(node)].min);
}

void push(int node){
    if(st[node].tag == 0) return;
    st[lc(node)].tag += st[node].tag;
    st[rc(node)].tag += st[node].tag;
    st[node].max = st[node].realMax();
    st[node].min = st[node].realMin();
    st[node].tag = 0;
}

ll queryMax(int l, int r, int L, int R, int node){
    if(l == L && r == R) return st[node].realMax();
    push(node);
    int m = (L + R) / 2;
    if(r <= m) return queryMax(l, r, L, m, lc(node));
    if(l > m) return queryMax(l, r, m + 1, R, rc(node));
    return max(queryMax(l, m, L, m, lc(node)), queryMax(m + 1, r, m + 1, R, rc(node)));
}

ll queryMin(int l, int r, int L, int R, int node){
    if(l == L && r == R) return st[node].realMin();
    push(node);
    int m = (L + R) / 2;
    if(r <= m) return queryMin(l, r, L, m, lc(node));
    if(l > m) return queryMin(l, r, m + 1, R, rc(node));
    return min(queryMin(l, m, L, m, lc(node)), queryMin(m + 1, r, m + 1, R, rc(node)));
}

void modify(int l, int r, int v, int L, int R, int node){
    if(L == R){
        st[node].min += v;
        st[node].max += v;
        return;
    }
    if(l == L && r == R){
        st[node].tag += v;
        return;
    }
    int m = (L + R) / 2;
    if(r <= m) modify(l, r, v, L, m, lc(node));
    else if(l > m) modify(l, r, v, m + 1, R, rc(node));
    else{
        modify(l, m, v, L, m, lc(node));
        modify(m + 1, r, v, m + 1, R, rc(node));
    }
    st[node].max = max(st[lc(node)].realMax(), st[rc(node)].realMax());
    st[node].min = min(st[lc(node)].realMin(), st[rc(node)].realMin());
}

int main(){
    StarBurstStream
    cerr.tie(0);

    int n;
    cin >> n;
    st.resize(4 * n);
    build(0, n - 1, 0);

    int now = 0;
    string s;
    cin >> s;

    string t(n, ' ');
    for(char c : s){
        if(c == 'R'){
            now++;
        }
        else if(c == 'L'){
            now = max(0, now - 1);
        }
        else{
            if(t[now] == '(') modify(now, n - 1, -1, 0, n - 1, 0);
            else if(t[now] == ')') modify(now, n - 1, 1, 0, n - 1, 0);
            if(c == '('){
                t[now] = '(';
                modify(now, n - 1, 1, 0, n - 1, 0);
            }
            else if(c == ')'){
                t[now] = ')';
                modify(now, n - 1, -1, 0, n - 1, 0);
            }
            else{
                t[now] = ' ';
            }
        }
        //cerr << queryMin(0 , n -1, 0, n -1, 0) << "\n";
        //for(int i = 0; i < n - 1; i++) cerr << queryMin(i, i, 0, n - 1, 0) << " ";
        //cerr << "\n";
        if(queryMin(0, n - 1, 0, n - 1, 0) < 0 || queryMin(n - 1, n - 1, 0, n - 1, 0) != 0) cout << "-1 ";
        else cout << queryMax(0, n - 1, 0, n - 1, 0) << " ";
        //cerr << t << "\n";
    }


    return 0;
}