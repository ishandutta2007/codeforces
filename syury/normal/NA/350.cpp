//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("tune=native")
#include<bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

using namespace std;

typedef
tree<
  int,
  null_type,
  less<int>,
  rb_tree_tag,
  tree_order_statistics_node_update>
ordered_set;

#define all(x) (x).begin(),(x).end()
#define I(x, a) for(auto x : (a))
#define ins insert
#define F(i, l, r) for(auto i = (l); i < (r); i++)
#define DF(i, l, r) for(auto i = (l); i >= (r); i--)
#define E(i, l, r) for(auto i = (l); i <= (r); i++)
#define pb push_back
#define X first
#define Y second
#define mp make_pair
#define ret return
#define brk break
#define cont continue
#define move fjgjgjgjghd

typedef long long ll;
typedef unsigned long long ull;
typedef long double dbl;
typedef pair<int, int> pii;

const int N = (int)2e5 + 5;

int n;
int a[N], pos[N];
int le[N];
int le_tree[N];
ll t[4*N][2];
ll add[4*N][2];

int le_prefix(int r){
    ++r;
    int ans = 0;
    while(r){
        ans += le_tree[r];
        r -= r&-r;
    }
    return ans;
}

void le_set(int pos){
    ++pos;
    while(pos < N){
        le_tree[pos]++;
        pos += pos&-pos;
    }
}

inline void push(int v, int l, int r){
    int mid = (r + l)/2;
    F(c, 0, 2){
        t[2*v][c] += add[v][c]*(mid - l + 1);
        add[2*v][c] += add[v][c];
        t[2*v+1][c] += add[v][c]*(r - mid);
        add[2*v+1][c] += add[v][c];
        add[v][c] = 0;
    }
}

ll get(int v, int l, int r, int ul, int ur, int c){
    if(ul > ur)ret 0;
    if(l == ul && r == ur){
        ret t[v][c];
    }
    push(v, l, r);
    int mid = (l + r)/2;
    ret get(2*v, l, mid, ul, min(ur, mid), c) + get(2*v + 1, mid + 1, r, max(ul, mid + 1), ur, c);
}

void inc(int v, int l, int r, int ul, int ur, int c){
    if(ul > ur)ret;
    if(l == ul && r == ur){
        t[v][c] += r - l + 1;
        add[v][c]++;
        ret;
    }
    push(v, l, r);
    int mid = (l + r)/2;
    inc(2*v, l, mid, ul, min(ur, mid), c);
    inc(2*v + 1, mid + 1, r, max(ul, mid + 1), ur, c);
    t[v][c] = t[2*v][c] + t[2*v+1][c];
}

signed main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    F(i, 0, n){
        cin >> a[i];
        --a[i];
        pos[a[i]] = i;
    }
    DF(i, n - 1, 0){
        le[a[i]] = le_prefix(a[i]);
        le_set(a[i]);
    }
    ll inv = 0;
    ordered_set s;
    F(k, 0, n){
        int i = pos[k];
        inv += le[k];
        s.insert(i);
        inc(1, 0, n - 1, i, n - 1, 0);
        inc(1, 0, n - 1, 0, i - 1, 1);
        int median = *s.find_by_order(k/2);
        ll ans = inv;
        ans += get(1, 0, n - 1, 0, median, 0) + get(1, 0, n - 1, median + 1, n - 1, 1);
        ans -= (k/2+1)*1ll*(k/2+2)/2 + (k-k/2-1)*1ll*(k-k/2)/2;
        cout << ans << ' ';
    }
    return 0;
}