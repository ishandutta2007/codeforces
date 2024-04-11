#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define ll long long
#define LEFT(a) ((a)<<1)
#define RIGHT(a) (LEFT(a) + 1)
#define MID(a,b) ((a+b)>>1)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define l1 l1228
#define l2 l2228
#define r1 r1228
#define r2 r2228
#define x1 x1228
#define y1 y1228
using namespace std;

const int N = 253, M = 2e5;

int n, Q;
string S;
int dp[N][N][N];

char ch[4][N];
int nn[4];
int a[4];
int mas[26][M];

int main()
{
    //freopen ("in.in", "r", stdin);freopen ("out.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin >> n >> Q >> S;
    S = "#" + S;
    for (int i = 0; i < 26; i++)
        mas[i][n + 1] = n + 1;
    for (int i = 0; i < 26; i++)
        mas[i][n + 2] = n + 1;
    for (int i = n; i >= 1; i--){
        for (int j = 0; j < 26; j++)
            mas[j][i] = mas[j][i + 1];
        mas[S[i] - 'a'][i] = i;
    }
    while (Q--){
        char cc;
        cin >> cc;
        if (cc == '-'){
            int t;
            cin >> t;
            nn[t]--;
            if (dp[nn[1]][nn[2]][nn[3]] == n + 1)
                cout << "NO\n";
            else
                cout << "YES\n";
            continue;
        }
        int t;
        cin >> t >> cc;
        nn[t]++;
        ch[t][nn[t]] = cc;
        a[1] = 0;
        a[2] = 0;
        a[3] = 0;
        a[t] = nn[t];
        int pas;
        for (int i = a[1]; i <= nn[1]; i++)
            for (int j = a[2]; j <= nn[2]; j++)
                for (int k = a[3]; k <= nn[3]; k++){
                    if (i + j + k == 0)
                        continue;
                    dp[i][j][k] = n + 1;
                    if (i){
                        pas = dp[i - 1][j][k];
                        pas = mas[ch[1][i] - 'a'][pas + 1];
                        dp[i][j][k] = min (dp[i][j][k], pas);
                    }
                    if (j){
                        pas = dp[i][j - 1][k];
                        pas = mas[ch[2][j] - 'a'][pas + 1];
                        dp[i][j][k] = min (dp[i][j][k], pas);
                    }
                    if (k){
                        pas = dp[i][j][k - 1];
                        pas = mas[ch[3][k] - 'a'][pas + 1];
                        dp[i][j][k] = min (dp[i][j][k], pas);
                    }
                }
        if (dp[nn[1]][nn[2]][nn[3]] == n + 1)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
    return 0;
}