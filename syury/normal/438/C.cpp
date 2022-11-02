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

struct pt{
    ll x, y;
    pt operator + (const pt & p)const{
        return pt{x + p.x, y + p.y};
    }
    pt operator - (const pt & p)const{
        return pt{x - p.x, y - p.y};
    }
    ll cross(const pt & p)const{
        return x * p.y - y * p.x;
    }
    ll dot(const pt & p)const{
        return x * p.x + y * p.y;
    }
    bool operator < (const pt & p)const{
        return make_pair(x, y) < make_pair(p.x, p.y);
    }
};

inline char sgn(ll x){
    return x < 0 ? -1 : !!x;
}

inline char line_sgn(pt A, pt B, pt C){
    return sgn((B - A).cross(C - A));
}

inline bool has(pt A, pt B, pt C){
    return line_sgn(A, B, C) == 0 && (A - C).dot(B - C) <= 0;
}

inline bool intersect(pt A, pt B, pt C, pt D){
    if(line_sgn(A, B, C) != line_sgn(A, B, D) && line_sgn(C, D, A) != line_sgn(C, D, B))
        return true;
    if(has(A, B, C) || has(A, B, D) || has(C, D, A) || has(C, D, B))
        return true;
    return false;
}

inline bool ccw(pt A, pt B){
    return A.cross(B) > 0;
}

const int N = 222;
const int mod = (int)1e9 + 7;

pt p[N];
bool valid[N][N];
int dp[N][N];
int n;

inline int adv(int i, int j){
    return (i + j)%n;
}

inline int retr(int i, int j){
    return (i - j + 2*n)%n;
}

void solve(){
    scanf("%d", &n);
    if(n == 3){
        printf("1\n");
        return;
    }
    for(int i = 0; i < n; i++){
        scanf("%lld%lld", &p[i].x, &p[i].y);
    }
    auto pos = min_element(p, p + n) - p;
    if(!ccw(p[pos] - p[retr(pos, 1)], p[adv(pos, 1)] - p[pos])){
        reverse(p, p + n);
    }
    for(int i = 0; i < n; i++){
        int j = adv(i, 1);
        for(int d = 2; d < n - 1; d++){
            j = adv(j, 1);
            valid[i][j] = 1;
            if(ccw(p[retr(i, 1)] - p[i], p[adv(i, 1)] - p[i])){
                if(ccw(p[retr(i, 1)] - p[i], p[j] - p[i]) && ccw(p[j] - p[i], p[adv(i, 1)] - p[i])){
                    valid[i][j] = 0;
                    continue;
                }
            }
            else{
                if(ccw(p[retr(i, 1)] - p[i], p[j] - p[i]) || ccw(p[j] - p[i], p[adv(i, 1)] - p[i])){
                    valid[i][j] = 0;
                    continue;
                }
            }
            //cout << i << ' ' << j << endl;
            for(int k = 0; k < n; k++){
                int nxt = adv(k, 1);
                if(k == i || k == j || nxt == i || nxt == j){
                    int other = (k == i || k == j) ? nxt : k;
                    int adj = nxt + k - other;
                    if(has(p[i], p[j], p[other]) || has(p[k], p[nxt], p[i + j - adj])){
                        valid[i][j] = 0;
                        break;
                    }
                    continue;
                }
                if(intersect(p[i], p[j], p[k], p[nxt])){
                    valid[i][j] = 0;
                    break;
                }
            }
            /*if(valid[i][j]){
                cout << i << ' ' << j << endl;
            }*/
        }
    }
    for(int i = 0; i < n; i++){
        int j = adv(i, 2);
        if(valid[i][j])
            dp[i][2] = 1;
    }
    for(int len = 3; len < n; len++){
        for(int i = 0; i < n; i++){
            for(int d = 1; d < len; d++){
                int mid = adv(i, d);
                if((d > 1 && !valid[i][mid]) || (d + 1 < len && !valid[mid][adv(i, len)]))
                    continue;
                //cout << "transition " << i << ' ' << adv(i, len) << " <= " << i << ' ' << mid << ", " << mid << ' ' << adv(i, len) << endl;
                //cout << "with values " << dp[i][d] << ' ' << dp[mid][len - d] << endl;
                ll curr = (d == 1 ? 1 : dp[i][d]) * 1ll * (d + 1 == len ? 1 : dp[mid][len - d]) % mod;
                dp[i][len] += curr;
                dp[i][len] -= dp[i][len] >= mod ? mod : 0;
            }
            //cout << dp[i][len] << ' ';
            //cout << endl;
        }
    }
    printf("%d\n", dp[0][n - 1]);
}

signed main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(11);
    int T = 1;
    while(T--)
        solve();
    return 0;
}