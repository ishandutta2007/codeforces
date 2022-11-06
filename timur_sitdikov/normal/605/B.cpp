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

pair<int, pii> vv[MAXN];
pii ans[MAXN];

int top[MAXN];

set<pii> st;

void solve(){
    int n, m, cur, i, j;
    scanf("%d%d", &n, &m);
    for(i = 0; i < m; i++){
        scanf("%d%d", &vv[i].first, &vv[i].second.first);
        vv[i].second.first *= -1;
        vv[i].second.second = i;
    }
    sort(vv, vv + m);
    cur = 1;
    int cnte = MAXN * 3;
    for(i = 0; i < m; i++){
        int ind = vv[i].second.second, a = vv[i].first, b = vv[i].second.first;
        if (b == -1){
            ans[ind] = mp(cur, cur + 1);
            cur++;
            for(j = 1; cnte && j + 1 < cur; j++){
                st.insert(mp(j, cur));
                cnte--;
            }
        } else {
            if (st.empty()){
                printf("-1\n");
                return;
            }
            ans[ind] = *st.begin();
            st.erase(st.begin());
        }
    }
    for(i = 0; i < m; i++){
        printf("%d %d\n", ans[i].first, ans[i].second);
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