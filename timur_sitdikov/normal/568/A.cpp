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
const int MAXN = 1e5 + 5;
const ll MOD = 1e9 + 7;

const int LIM = 2e6;

char p1[LIM], p2[LIM];
int sum1[LIM], sum2[LIM];

char c[100];

int check(int v){
    int i, n;
    for(n = 0; v; v /= 10, n++){
        c[n] = v % 10;
    }
    for(i = 0; i < n; i++){
        if (c[i] != c[n - 1 - i]){
            return 0;
        }
    }
    return 1;
}

void solve(){
    int i, j, k, v1, v2, v3;
    ll p, q;
    p1[1] = 1;
    REP(i, 2, LIM){
        if (!p1[i]){
            for(j = 2 * i; j < LIM; j += i){
                p1[j] = 1;
            }
        }
        sum1[i] = sum1[i - 1] + 1 - p1[i];
    }
    /*printf("#\n");
    return;*/
    REP(i, 1, LIM){
        p2[i] = check(i);
        sum2[i] = sum2[i - 1] + p2[i];
    }
    cin >> p >> q;
    int ans = 0;
    for(i = 1; i < LIM; i++){
        if (sum1[i] * q <= sum2[i] * p){
            ans = i;
        }
    }
    if (ans == 0){
        cout << "Palindromic tree is better than splay tree" << endl;
    } else {
        cout << ans << endl;
        //cout << sum1[ans] << " " << sum2[ans] << endl;
    }
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