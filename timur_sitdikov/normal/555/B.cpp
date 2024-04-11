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
const int MAXN = 6e5 + 5;
const ll MOD = 1e9 + 7;

set<pair<ll, int> > st;

pair<ll, pii> pp[MAXN];

ll rr[MAXN];

int ans[MAXN];

void solve(){
    int n, m, i, top = 0;
    ll l1, r1, l, r, vl, vr;
    scanf("%d%d%I64d%I64d", &n, &m, &l1, &r1);
    REP(i, 1, n){
        scanf("%I64d%I64d", &l, &r);
        vl = l - r1;
        vr = r - l1;
        pp[top++] = mp(vl, mp(1, i - 1));
        pp[top++] = mp(vr, mp(3, i - 1));
        rr[i - 1] = vr;
        l1 = l;
        r1 = r; 
    }
    REP(i, 0, m){
        scanf("%lld", &l);
        pp[top++] = mp(l, mp(2, i));
    }
    sort(pp, pp + top);
    REP(i, 0, top){
        int tt = pp[i].second.first;
        int ind = pp[i].second.second;
        l = pp[i].first;
        if (tt == 1){
            st.insert(mp(rr[ind], ind));
        } else if (tt == 3){
            if (ans[ind] == 0){
                printf("No\n");
                return;
            }
        } else {
            if (st.empty()){
                continue;
            }
            ans[st.begin()->second] = ind + 1;
            st.erase(st.begin());
        }
    }
    printf("Yes\n");
    REP(i, 0, n - 1){
        printf("%d ", ans[i]);
    }
    putchar('\n');
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