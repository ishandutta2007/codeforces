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

const int N = 2002;
const int ST = 95;

int pr[N];
int sz = 0;
uint32_t dp[2][ST][ST][ST];
int ba[N], bb[N], bc[N];
int ca, cb, cc;
int pw[N];
int ida[N], idb[N], idc[N];
int ta[N][N], tb[N][N], tc[N][N];
int a, b, c;

void genprimes(){
    for(int i = 2; i < N; i++){
        bool ok = 1;
        for(int j = 2; j * j <= i; j++)
            if(i%j == 0){ok = 0; break;}
        if(ok)
            pr[sz++] = i;
    }
}

int genb(int n, int * b, int * id){
    int cu = 0;
    for(int i = 1; i <= n; i++)
        b[cu++] = n/i;
    sort(b, b + cu);
    cu = unique(b, b + cu) - b;
    for(int i = 0; i < cu; i++)
        id[b[i]] = i;
    return cu;
}

void genborders(){
    ca = genb(a, ba, ida);
    cb = genb(b, bb, idb);
    cc = genb(c, bc, idc);
}

void solve(){
    cin >> a >> b >> c;
    genprimes();
    genborders();
    memset(dp, 0, sizeof(dp));
    for(int i = 0; i < ca; i++)
        for(int j = 0; j < cb; j++)
            for(int k = 0; k < cc; k++)
                dp[0][i][j][k] = 1;
    for(int p = sz - 1; p >= 0; p--){
        memset(dp[1], 0, sizeof(dp[1]));
        int ptr = 1;
        pw[0] = 1;
        while(pw[ptr - 1] * pr[p] < N){
            pw[ptr] = pw[ptr - 1] * pr[p];
            ++ptr;
        }
        pw[ptr] = N;
        for(int ia = 0; ia < ca; ia++){
            int A = ba[ia];
            for(int pa = 0; pw[pa] <= A; pa++)
                ta[ia][pa] = ida[A/pw[pa]];
        }
        for(int ib = 0; ib < cb; ib++){
            int B = bb[ib];
            for(int pb = 0; pw[pb] <= B; pb++)
                tb[ib][pb] = idb[B/pw[pb]];
        }
        for(int ic = 0; ic < cc; ic++){
            int C = bc[ic];
            for(int pc = 0; pw[pc] <= C; pc++)
                tc[ic][pc] = idc[C/pw[pc]];
        }
        for(int ia = 0; ia < ca; ia++){
            int A = ba[ia];
            for(int ib = 0; ib < cb; ib++){
                int B = bb[ib];
                for(int ic = 0; ic < cc; ic++){
                    int C = bc[ic];
                    uint32_t& val = dp[1][ia][ib][ic];
                    for(int pa = 0; pw[pa] <= A; pa++){
                        int ra = ta[ia][pa];
                        for(int pb = 0; pw[pb] <= B; pb++){
                            int rb = tb[ib][pb];
                            for(int pc = 0; pw[pc] <= C; pc++){
                                int rc = tc[ic][pc];
                                uint32_t mul = pa + pb + pc + 1;
                                val += mul * dp[0][ra][rb][rc];
                            }
                        }
                    }
                }
            }
        }
        memcpy(dp[0], dp[1], sizeof(dp[1]));
    }
    cout << (dp[0][ida[a]][idb[b]][idc[c]]&((1u<<30)-1)) << endl;
    cerr << clock()/double(CLOCKS_PER_SEC) << endl;
}

signed main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}