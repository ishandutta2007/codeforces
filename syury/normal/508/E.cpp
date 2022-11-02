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
#define move fjgjgjgjghd

typedef long long ll;
typedef unsigned long long ull;
typedef long double dbl;
typedef pair<int, int> pii;

const int N = 666;

bool can[N][N];
short mv[N][N];
int L[N], R[N];
int n;

void solve(int l, int r){
    if(mv[l][r] != -2)ret;
    if(l == r){
        mv[l][r] = -1;
        if(L[l] == 1)can[l][r] = 1;
        ret;
    }
    mv[l][r] = -1;
    if(L[l] <= 1 + 2*(r - l) && 1 + 2*(r - l) <= R[l]){
        solve(l + 1, r);
        if(can[l + 1][r]){
            can[l][r] = 1;
            ret;
        }
    }
    F(cnt, 1, r - l + 1){
        if(1){
            solve(l, l + cnt - 1);
            solve(l + cnt, r);
            if(can[l][l + cnt - 1] && can[l + cnt][r]){
                mv[l][r] = cnt;
                can[l][r] = 1;
                ret;
            }
        }
    }
}

string restore(int l, int r){
    if(l == r)ret "()";
    if(mv[l][r] == -1)
        ret "(" + restore(l + 1, r) + ")";
    ret restore(l, l + mv[l][r] - 1) + restore(l + mv[l][r], r);
}

signed main(){
#ifdef LOCAL
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    F(i, 0, N)F(j, 0, N)mv[i][j] = -2;
    cin >> n;
    F(i, 0, n){
        cin >> L[i] >> R[i];
    }
    solve(0, n - 1);
    if(!can[0][n - 1]){cout << "IMPOSSIBLE"; ret 0;}
    cout << restore(0, n - 1) << endl;
    return 0;
}