//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,tune=native")
#include<bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(),(x).end()
#define pb push_back
#define X first
#define Y second
#define mp make_pair

typedef long long ll;
typedef unsigned long long ull;
typedef double dbl;
typedef pair<int, int> pii;

const int N = 55;

int n;
int f[2][N][N];
bool dp[2][N][N][N][N];
int know[N][N];
int real_f[N][N];
bool real_dp[N][N][N][N];

int ask(int x1, int y1, int x2, int y2){
#ifdef LOCAL
    return int(real_dp[x1][y1][x2][y2]);
#else
    cout << "? " << x1 + 1 << ' ' << y1 + 1 << ' ' << x2 + 1 << ' ' << y2 + 1 << endl;
    int ans;
    cin >> ans;
    return ans;
#endif
}

void out(int c){
#ifdef LOCAL
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            assert(f[c][i][j] == real_f[i][j]);
    exit(0);
#else
    cout << "!\n";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            cout << f[c][i][j];
        cout << '\n';
    }
    cout.flush();
    exit(0);
#endif
}

void calc(int c){
    for(int i = n - 1; i >= 0; i--){
        for(int j = n - 1; j >= 0; j--){
            for(int i1 = i; i1 < n; i1++){
                for(int j1 = j; j1 < n; j1++){
                    if(i1 == i && j1 == j){
                        dp[c][i][j][i1][j1] = 1;
                        continue;
                    }
                    if(f[c][i][j] != f[c][i1][j1])
                        continue;
                    if(abs(i - i1) + abs(j - j1) == 1){
                        dp[c][i][j][i1][j1] = 1;
                        continue;
                    }
                    if(j < j1)
                        dp[c][i][j][i1][j1] |= dp[c][i][j + 1][i1][j1 - 1];
                    if(i < i1)
                        dp[c][i][j][i1][j1] |= dp[c][i + 1][j][i1 - 1][j1];
                    if(j < j1 && i < i1){
                        dp[c][i][j][i1][j1] |= dp[c][i][j + 1][i1 - 1][j1];
                        dp[c][i][j][i1][j1] |= dp[c][i + 1][j][i1][j1 - 1];
                    }
                }
            }
        }
    }
}

void solve(){
#ifdef LOCAL
    srand(time(0));
    n = 7;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            real_f[i][j] = rand()%2;
    real_f[0][0] = 1;
    real_f[n-1][n-1] = 0;
    memcpy(f[0], real_f, sizeof(real_f));
    calc(0);
    memcpy(real_dp, dp[0], sizeof(real_dp));
    memset(f, 0, sizeof(f));
    memset(dp, 0, sizeof(dp));
#else
    cin >> n;
#endif
    know[0][0] = 1;
    know[n-1][n-1] = 0;
    know[n-2][n-1] = 0;
    for(int j = n - 1; j >= 0; j--){
        for(int i = n - 1; i >= 0; i--){
            if((i+j)&1){
                if(i == n - 1)
                    continue;
                if(i == n - 2){
                    if(j < n - 1){
                        int x = ask(i, j, i, j + 2);
                        know[i][j] = know[i][j + 2]^1^x;
                    }
                }
                else if(i == n - 3){
                    int x = ask(i, j, i + 1, j + 1);
                    know[i][j] = know[i + 1][j + 1]^1^x;
                }
                else{
                    int x = ask(i, j, i + 2, j);
                    know[i][j] = know[i + 2][j]^1^x;
                }
            }
            else{
                if(i == n - 1 && j == n - 1)continue;
                if(j == n - 1){
                    int x = ask(i, j, i + 2, j);
                    know[i][j] = know[i + 2][j]^1^x;
                }
                else if(j == n - 2){
                    int x = ask(i, j, i + 1, j + 1);
                    know[i][j] = know[i + 1][j + 1]^1^x;
                }
                else{
                    int x = ask(i, j, i, j + 2);
                    know[i][j] = know[i][j + 2]^1^x;
                }
            }
        }
    }
    for(int j = 1; j < n; j += 2){
        int x = ask(n - 3, j, n - 1, j);
        know[n - 1][j] = know[n - 3][j]^1^x;
    }
    for(int c = 0; c <= 1; c++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if((i+j)&1){
                    f[c][i][j] = know[i][j]^c;
                }
                else{
                    f[c][i][j] = know[i][j];
                }
            }
        }
    }
/*    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cout << real_f[i][j] << ' ' << f[0][i][j] << ' ' << f[1][i][j] << endl;*/
    calc(0);
    calc(1);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int i1 = i; i1 < n; i1++){
                for(int j1 = j; j1 < n; j1++){
                    if(j1 + i1 - i - j < 2)continue;
                    if(dp[0][i][j][i1][j1] != dp[1][i][j][i1][j1]){
                        int x = ask(i, j, i1, j1);
                        if(x == int(dp[0][i][j][i1][j1]))
                            out(0);
                        else
                            out(1);
                    }
                }
            }
        }
    }
    assert(false);
}

signed main(){
#ifdef LOCAL
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    while(T--)
        solve();
    return 0;
}