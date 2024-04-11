//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,tune=native")
#include<bits/stdc++.h>

using namespace std;

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
#define sz(a) ((int)a.size())

typedef long long ll;
typedef unsigned long long ull;
typedef long double dbl;
typedef pair<int, int> pii;

const int N = (int)1e5 + 5;

int n;
int a[N], b[N], d[N];
pii A[N], B[N];
int sza = 0, szb = 0;

void readnum(int* x){
    string s;
    cin >> s;
    for(auto c: s)
        *(x++) = c - '0';
}

void solve(){
    cin >> n;
    readnum(a);
    readnum(b);
    int sum = 0;
    for(int i = 0; i < n; i++){
        d[i] = b[i] - a[i];
        sum += (i&1) ? -d[i] : d[i];
    }
    if(sum != 0){
        cout << "-1\n";
        return;
    }
    int delta = 0;
    ll ans = 0;
    for(int i = 0; i < n; i++){
        int curr = d[i] - delta;
        ans += abs(curr);
        if(curr)
            A[sza++] = make_pair(curr, i);
        delta = curr;
    }
    vector<pii> seq;
    while(sza && seq.size() < (int)1e5){
        szb = 0;
        int old = -1;
        for(int i = 0; i < sza; i++){
            int pos = A[i].Y;
            int dd = A[i].X > 0 ? 1 : -1;
            if(a[pos] + dd > 9 || a[pos] + dd < 0 || a[pos + 1] + dd > 9 || a[pos + 1] + dd < 0)
                continue;
            int ob = szb;
            for(int j = i; j > old; j--){
                int pos = A[j].Y;
                seq.emplace_back(A[j].Y + 1, A[j].X > 0 ? 1 : -1);
                if(A[j].X > 0){++a[pos]; ++a[pos + 1]; --A[j].X;}
                else {--a[pos]; --a[pos + 1]; ++A[j].X;}
                if(A[j].X)
                    B[szb++] = A[j];
            }
            if(ob < szb)
                reverse(B + ob, B + szb);
            old = i;
        }
        //cerr << sza << ' ' << szb << endl;
        assert(old == sza - 1);
        copy(B, B + szb, A);
        sza = szb;
    }
    cout << ans << endl;
    ans = min(ans, (ll)1e5);
    for(int i = 0; i < ans; i++)
        cout << seq[i].X << ' ' << seq[i].Y << '\n';
}

signed main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T;
    T = 1;
    while(T--)
        solve();
    //cerr << fixed << clock()/(double)CLOCKS_PER_SEC << endl;
    return 0;
}