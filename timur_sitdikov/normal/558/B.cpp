#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef complex<double> point;
#define xx real()
#define yy imag()

#define REP(i, a, b) for((i) = (a); (i) < (int)(b); (i)++)
#define FA(it, x) for(__typeof((x).begin()) it = (x).begin(); it != (x).end(); it++)
#define SZ(x) (int)(x).size()
#define BE(x) (x).begin(), (x).end()
#define SORT(x) sort(BE(x))

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

#define file "cycle"

const double EPS = 1e-9;
const double PI = acos(-1.);
const int INF = 1e9;
const int MAXN = 1e6 + 5;
const ll MOD = 1e9 + 7;

int l[MAXN], r[MAXN], cnt[MAXN];

void solve(){
    int n, i, a, mx = 0, mxl = 0, mxr = 0;
    scanf("%d", &n);
    REP(i, 0, n){
        scanf("%d", &a);
        if (cnt[a] == 0){
            l[a] = i;
        }
        r[a] = i;
        cnt[a]++;
        if (cnt[a] > mx || cnt[a] == mx && mxr - mxl > r[a] - l[a]){
            mx = cnt[a];
            mxl = l[a];
            mxr = r[a];
        }
    }
    printf("%d %d\n", mxl + 1, mxr + 1);
}   

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    //freopen(file".in", "r", stdin); freopen(file".out", "w", stdout);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();    
    }
}