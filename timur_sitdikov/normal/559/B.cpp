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
const int MAXN = 2e5 + 5;
const ll MOD = 1e9 + 7;

char c1[MAXN], c2[MAXN];

void rec_edit(char *c, int n){
    if (n & 1){
        return;
    }
    int n2 = n >> 1, i;
    rec_edit(c, n2);
    rec_edit(c + n2, n2);
    REP(i, 0, n2){
        if (c[i] != c[i + n2]){
            if (c[i] > c[i + n2]){
                REP(i, 0, n2){
                    swap(c[i], c[i + n2]);
                }
            }
            break;
        }
    }
}

void solve(){
    int n, i;
    scanf("%s%s", &c1[0], &c2[0]);
    n = strlen(c1);
    rec_edit(c1, n);
    rec_edit(c2, n);
    REP(i, 0, n){
        if (c1[i] != c2[i]){
            printf("NO\n");
            return;
        }
    }
    printf("YES\n");
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