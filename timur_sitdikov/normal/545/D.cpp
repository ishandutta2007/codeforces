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

map<int, int> vv;
map<int, int>::iterator it;


void solve(){
    int n, i, sum, a, ans;
    scanf("%d", &n);
    REP(i, 0, n){
        scanf("%d", &a);
        vv[a]++;
    }
    sum = vv.begin()->first;
    ans = 1;
    vv[sum]--;
    if (vv[sum] == 0){
        vv.erase(sum);
    }
    while(1){
        it = vv.lower_bound(sum);
        if (it == vv.end()){
            break;
        }
        sum += it->first;
        ans++;
    }
    printf("%d\n", ans);
    
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