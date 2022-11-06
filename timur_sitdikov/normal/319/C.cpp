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

ll koef[MAXN], val[MAXN];
int a[MAXN], b[MAXN];
int top, best_ind;

int erased(int ind1, int ind2, int ind3){
    //return (val[ind3] - val[ind1]) * (koef[ind1] - koef[ind2]) 
    //  <= (val[ind2] - val[ind1]) * (koef[ind1] - koef[ind3]);
    return (val[ind3] - val[ind1]) / (koef[ind1] - koef[ind3]) 
        < (val[ind2] - val[ind1]) / (koef[ind1] - koef[ind2]);
}

ll get_val(ll x){
    if (best_ind >= top){
        best_ind = top - 1;
    }
    for(; best_ind < top - 1
        && koef[best_ind + 1] * x + val[best_ind + 1] < koef[best_ind] * x + val[best_ind]; best_ind++);
    return koef[best_ind] * x + val[best_ind]; 
}

void add(ll cur_koef, ll cur_val){
    koef[top] = cur_koef;
    val[top] = cur_val;
    top++;
    for(; top > 2 && erased(top - 3, top - 2, top - 1); ){
        top--;
        koef[top - 1] = koef[top];
        val[top - 1] = val[top];
    }
}

void solve(){
    int n, i;
    scanf("%d", &n);
    REP(i, 0, n){
        scanf("%d", &a[i]);
    }
    REP(i, 0, n){
        scanf("%d", &b[i]);
    }
    add((ll)b[0], 0ll);
    ll tmp = 0ll;
    for(i = 1; i < n; i++){
        tmp = get_val((ll)a[i]);
        add((ll)b[i], tmp); 
    }
    cout << tmp << endl;
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