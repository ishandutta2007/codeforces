#pragma GCC optimize("Ofast,unroll-loops")
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

ull eq[20][8][9][5][7];
ull dp[20][8][9][5][7];
ull res[8][9][5][7];

void calc_dp(string N, vector<int> digits){
    memset(dp, 0, sizeof(dp));
    memset(res, 0, sizeof(res));
    memset(eq, 0, sizeof(eq));
    eq[0][0][0][0][0] = 1;
    for(size_t pos = 0; pos < N.length(); pos++){
        for(int r2 = 0; r2 < 8; r2++){
            for(int r3 = 0; r3 < 9; r3++){
                for(int r5 = 0; r5 < 5; r5++){
                    for(int r7 = 0; r7 < 7; r7++){
                        ull val = dp[pos][r2][r3][r5][r7];
                        for(auto d: digits){
                            int nr2 = (r2*10 + d)%8;
                            int nr3 = (r3*10 + d)%9;
                            int nr5 = (r5*10 + d)%5;
                            int nr7 = (r7*10 + d)%7;
                            dp[pos + 1][nr2][nr3][nr5][nr7] += val;
                            if(d < N[pos] - '0'){
                                dp[pos + 1][nr2][nr3][nr5][nr7] += eq[pos][r2][r3][r5][r7];
                            }
                            else if(d == N[pos] - '0'){
                                eq[pos + 1][nr2][nr3][nr5][nr7] += eq[pos][r2][r3][r5][r7];
                            }
                        }
                    }
                }
            }
        }
    }
    for(int r2 = 0; r2 < 8; r2++)
        for(int r3 = 0; r3 < 9; r3++)
            for(int r5 = 0; r5 < 5; r5++)
                for(int r7 = 0; r7 < 7; r7++)
                    res[r2][r3][r5][r7] = dp[N.size()][r2][r3][r5][r7] + eq[N.size()][r2][r3][r5][r7];
}

inline int intpow(int x, int p){
    int res = 1;
    while(p){
        res *= x;
        --p;
    }
    return res;
}

inline vector<int> generate_rem(int x, int m){
    vector<int> ans;
    for(int i = 1; i <= m; i++){
        if(i%x == 0 && __gcd(i/x, max(x, m/x)) == 1){ans.pb(i%m);}
    }
    return ans;
}

ull solve(ull N){
    string s = to_string(N);
    ull ans[4][3][2][2];//, no6[4][3][2][2];
    memset(ans, 0, sizeof(ans));
    //memset(no6, 0, sizeof(ans));
    ull out = 0;
    for(int p2 = 3; p2 >= 0; p2--){
        for(int p3 = 2; p3 >= 0; p3--){
            for(int p5 = 1; p5 >= 0; p5--){
                for(int p7 = 1; p7 >= 0; p7--){
                    vector<int> digits = {0};
                    int ziga = 1;
                    for(int kek = 0; kek <= p2; kek++){
                        digits.pb(ziga);
                        ziga *= 2;
                    }
                    ziga = 1;
                    for(int kek = 0; kek <= p3; kek++){
                        digits.pb(ziga);
                        ziga *= 3;
                    }
                    if(p5)
                        digits.pb(5);
                    if(p7)
                        digits.pb(7);
                    if(p2 && p3){
                        digits.pb(6);
                    }
                    sort(all(digits));
                    digits.erase(unique(all(digits)), digits.end());
                    calc_dp(s, digits);
                    auto r2 = generate_rem(intpow(2, p2), 8);
                    auto r3 = generate_rem(intpow(3, p3), 9);
                    auto r5 = generate_rem(intpow(5, p5), 5);
                    auto r7 = generate_rem(intpow(7, p7), 7);
                    int mask = 0;
                    for(auto d: digits)mask |= 1<<d;
                    for(int rr2: r2)
                        for(int rr3: r3)
                            for(int rr5: r5)
                                for(int rr7: r7)
                                    ans[p2][p3][p5][p7] += res[rr2][rr3][rr5][rr7];
                    //if(p2 == 2){cout << r2[0] << ' ' << r2[1] << endl;}
                    //cout << res[4][4][4][4] << endl;
                    //cout << res[0][0][0][0] << endl;
                    //cout << p2 << ' ' << p3 << ' ' << p5 << ' ' << p7 << endl;
                    //cout << ans[p2][p3][p5][p7] << endl;
                    out += ans[p2][p3][p5][p7];
                }
            }
        }
    }
    return out;
}

signed main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--){
        ull L, R;
        cin >> L >> R;
        //cout << solve(L - 1) << ' ' << solve(R) << endl;
        auto ans = solve(R) - solve(L - 1);
        cout << ans << '\n';
    }
    return 0;
}