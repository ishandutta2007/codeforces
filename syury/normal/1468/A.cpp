//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,tune=native")
#include<bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(),(x).end()
#define pb push_back
#define X first
#define Y second
#define mp make_pair

typedef long long ll;
typedef unsigned long long ull;
typedef double dbl;
typedef pair<int, int> pii;

const int N = (int)5e5 + 5;
const int inf = (int)1e9;

int mx[4*N][2];
bool need_push[4*N];

void build(int v, int l, int r){
    mx[v][0] = mx[v][1] = -inf;
    need_push[v] = false;
    if(l == r)
        return;
    int mid = (l + r)/2;
    build(2*v, l, mid);
    build(2*v + 1, mid + 1, r);
}

inline void push(int v){
    if(need_push[v]){
        need_push[2*v] = need_push[2*v+1] = true;
        for(int c = 0; c <= 1; c++){
            mx[2*v+c][0] = max(mx[2*v+c][0], mx[2*v+c][1] + 1);
            mx[2*v+c][1] = -inf;
        }
        need_push[v] = false;
    }
}

void inc(int v, int l, int r, int ul, int ur){
    if(ul > ur)
        return;
    if(l == ul && r == ur){
        mx[v][0] = max(mx[v][0], mx[v][1] + 1);
        mx[v][1] = -inf;
        need_push[v] = true;
        return;
    }
    push(v);
    int mid = (l + r)/2;
    inc(2*v, l, mid, ul, min(ur, mid));
    inc(2*v + 1, mid + 1, r, max(ul, mid + 1), ur);
    mx[v][0] = max(mx[2*v][0], mx[2*v+1][0]);
    mx[v][1] = max(mx[2*v][1], mx[2*v+1][1]);
}

void upd(int v, int l, int r, int pos, int val){
    if(l == r){
        if(mx[v][0] < 0 && mx[v][1] >= val)
            return;
        if(val + 1 <= mx[v][0])return;
        mx[v][1] = val;
        mx[v][0] = -inf;
        return;
    }
    push(v);
    int mid = (l + r)/2;
    if(pos <= mid)
        upd(2*v, l, mid, pos, val);
    else
        upd(2*v + 1, mid + 1, r, pos, val);
    mx[v][0] = max(mx[2*v][0], mx[2*v+1][0]);
    mx[v][1] = max(mx[2*v][1], mx[2*v+1][1]);
}

int get(int v, int l, int r, int ul, int ur){
    if(ul > ur)
        return -inf;
    if(l == ul && r == ur)
        return max(mx[v][0], mx[v][1]);
    push(v);
    int mid = (l + r)/2;
    return max(get(2*v, l, mid, ul, min(ur, mid)), get(2*v + 1, mid + 1, r, max(ul, mid + 1), ur));
}

int n;
int a[N];

void solve(){
    cin >> n;
    a[0] = 0;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    build(1, 0, n);
    upd(1, 0, n, 0, 0);
    for(int i = 1; i <= n; i++){
        int x = a[i];
        int val = get(1, 0, n, 0, x) + 1;
        inc(1, 0, n, 0, x);
        upd(1, 0, n, x, val);
    }
    cout << max(mx[1][0], mx[1][1]) << '\n';
}

signed main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T=1;
    cin >> T;
    while(T--)
        solve();
    return 0;
}