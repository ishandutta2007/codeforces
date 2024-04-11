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
typedef long double dbl;
typedef pair<int, int> pii;

const int N = (int)2e6 + 5;

ll t[N], mx[N];
ll settype[N], info[N];

inline void push(int v, int l, int r){
    if(!settype[v])
        return;
    int mid = (l + r)/2;
    if(settype[v] == 2){
        mx[2*v] = mx[2*v+1] = info[2*v] = info[2*v+1] = info[v];
        settype[2*v] = settype[2*v+1] = 2;
        t[2*v] = info[v] * 1ll * (mid - l + 1);
        t[2*v+1] = info[v] * 1ll * (r - mid);
        info[v] = settype[v] = 0;
    }
    else{
        mx[2*v] = mid - info[v];
        mx[2*v+1] = r - info[v];
        t[2*v] = (l + mid - 2 * info[v]) * 1ll * (mid - l + 1)/2;
        t[2*v+1] = (r + mid + 1 - 2 * info[v]) * 1ll * (r - mid)/2;
        settype[2*v] = settype[2*v+1] = 1;
        info[2*v] = info[2*v+1] = info[v];
        info[v] = settype[v] = 0;
    }
}

void setval(int v, int l, int r, int ul, int ur, int x){
    if(ul > ur)
        return;
    if(ul == l && ur == r){
        mx[v] = x;
        t[v] = (r - l + 1) * 1ll * x;
        settype[v] = 2;
        info[v] = x;
        return;
    }
    push(v, l, r);
    int mid = (l + r)/2;
    setval(2*v, l, mid, ul, min(ur, mid), x);
    setval(2*v + 1, mid + 1, r, max(ul, mid + 1), ur, x);
    t[v] = t[2*v] + t[2*v+1];
    mx[v] = max(mx[2*v], mx[2*v+1]);
}

void setseq(int v, int l, int r, int ul, int ur, int bg){
    if(ul > ur)
        return;
    if(ul == l && ur == r){
        mx[v] = r - bg;
        t[v] = (l + r - 2*bg) * 1ll * (r - l + 1)/2;
        settype[v] = 1;
        info[v] = bg;
        return;
    }
    push(v, l, r);
    int mid = (l + r)/2;
    setseq(2*v, l, mid, ul, min(ur, mid), bg);
    setseq(2*v+1, mid+1, r, max(ul, mid+1), ur, bg);
    t[v] = t[2*v] + t[2*v+1];
    mx[v] = max(mx[2*v], mx[2*v+1]);
}

int getbig(int v, int l, int r, int x){
    if(l == r){
        if(mx[v] < x)
            return l + 1;
        else
            return l;
    }
    push(v, l, r);
    int mid = (l + r)/2;
    if(mx[2*v] >= x)
        return getbig(2*v, l, mid, x);
    else
        return getbig(2*v+1, mid+1, r, x);
}

int n;
string s;

void suffmax(int l, int x){
    if(l >= n)
        return;
    int l1 = getbig(1, 0, n - 1, x);
    int r = max(l - 1, l1 - 1);
    setval(1, 0, n - 1, l, r, x);
}

void seqmax(int l, int r){
    if(l > r)
        return;
    int d = l - 1;
    setseq(1, 0, n - 1, l, r, d);
}

void solve(){
    cin >> n >> s;
    ll ans = 0;
    int seq = 0;
    for(int i = n - 1; i >= 0; i--){
        if(s[i] == '1')++seq;
        else seq = 0;
        suffmax(i + seq, seq);
        seqmax(i, i + seq - 1);
        ans += t[1];
    }
    cout << ans << endl;
}

signed main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    while(T--)
        solve();
    return 0;
}