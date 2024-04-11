#include<bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define endl '\n'
#define pb push_back
#define pob pop_back
#define mp make_pair
#define upb upper_bound
#define lwb lower_bound
#define fi first
#define se second
#define For(indx, a, b) for (int indx = a; indx < b; indx++)
#define ForE(indx, a, b) for (int indx = a; indx <= b; indx++)
#define Ford(indx, a, b) for (int indx = a; indx > b; indx--)
#define FordE(indx, a, b) for (int indx = a; indx >= b; indx--)
#define Fora(indx, a) for (auto indx : a)

#define PrintV(x) for (int indx = 0; indx < x.size(); indx++) cout << x[indx] << ' ';
#define PrintVl(x) for (int indx = 0; indx < x.size(); indx++) cout << x[indx] << endl;
#define Ptest(x) return cout << x, 0;
#define Pmtest(x) cout << x << endl; continue;
#define isvowel(x) (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u' || x == 'y')
#define gl(x) getline(cin, x)

#define pque priority_queue
#define mts multiset
typedef vector <int> vi;
typedef pair <int, int> ii;
typedef vector <vi > vvi;
typedef vector <ii > vii;

const int N = 2e3 + 5, mod = 998244353, inf = 1e18 + 7;

int dp[N][N];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    ForE(i, 0, n){
        dp[i][0] = m;
    }
    ForE(i, 2, n){
        ForE(j, 1, k){
            dp[i][j] = (dp[i - 1][j - 1] * (m - 1)) % mod;
            dp[i][j] = (dp[i][j] + dp[i - 1][j]) % mod;
            //cout << dp[i][j] << ' ' << i << ' ' << j << endl;
        }
    }
    cout << dp[n][k];
}

/*
==================================+
INPUT:                            |
------------------------------    |
3 3 0

------------------------------    |
3 2 1

------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |
3 

------------------------------    |
4

------------------------------    |
==================================+
*/