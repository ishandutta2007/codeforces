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

string ans[2] = {"Daenerys", "Stannis"};

void solve(){
    int n, k, m, a = 0, b = 0, tmp, i;
    scanf("%d%d", &n, &k);
    m = n - k;
    REP(i, 0, n){
        scanf("%d", &tmp);
        if (tmp & 1){
            b++;
        } else {
            a++;
        }
    }
    /*if (b < m){
        int dif = m - b;
        a -= dif;
        m -= dif;
        fl ^= (dif & 1);
    }
    if (a < m){
        int dif = m - a;
        b -= dif;
        m -= dif;
        fl ^= (dif & 1);
    }*/
    //cout << m  << " " << a << " " << b << endl;
    /*if (m / 2 >= b){
        cout << ans[0] << endl;
        return;
    }*/
    /*if (b == 0){
        cout << ans[0] << endl;
        return;
    }*/
    /*if (a == 0){
        cout << ans[(m & 1) ^ fl] << endl;
        return;
    }*/
    if (m == 0){
        cout << ans[b & 1] << endl;
        return;
    }
    if (m / 2 >= a){
        int v = (b - (m - a)) & 1;
        if (v != (m & 1)){
            cout << ans[(m & 1) ^ 1] << endl;
            return;
        }
    }
    if (m / 2 >= b){
        cout << ans[0] << endl;
        return;
    }
    cout << ans[m & 1] << endl;
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