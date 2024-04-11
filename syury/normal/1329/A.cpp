//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
//#pragma GCC target("tune=native")
#include<bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(),(x).end()
#define I(x, a) for(auto x : (a))
#define ins insert
#define F(i, l, r) for(auto i = (l); i < (r); i++)
#define DF(i, l, r) for(auto i = (l); i >= (r); i--)
#define E(i, l, r) for(auto i = (l); i <= (r); i++)
#define pb emplace_back
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

const int N = (int)1e5 + 5;

int n, m;
int l[N];
int p[N];
int suff[N];

void fail(){
    cout << -1;
    exit(0);
}

signed main(){
#ifdef LOCAL
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    int r = 0;
    F(i, 0, m){
        cin >> l[i];
        p[i] = i;
        if(p[i] + l[i] > n)
            fail();
        r = max(r, p[i] + l[i]);
    }
    DF(i, m - 1, 0){
        suff[i] = p[i] + l[i];
        if(i + 1 < m)suff[i] = max(suff[i], suff[i + 1]);
    }
    r = 0;
    int shift = 0;
    F(i, 0, m){
        if(r < n && shift + suff[i] < n){
            int delta = min(n - shift - suff[i], r - i);
            shift += delta;
        }
        p[i] += shift;
        r = max(r, p[i] + l[i]);
    }
    if(r < n)fail();
    else{
        F(i, 0, m)
            cout << p[i] + 1 << ' ';
    }
    return 0;
}