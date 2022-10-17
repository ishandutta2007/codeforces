#include<bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define sz(s) (int)s.size()
#define pb push_back
#define all(s) s.begin(), s.end()
#define vi vector<int>

#define ll long long
#define ld long double
#define vvi vector<vi>
#define ii pair<int, int>
#define vii vector<ii>

const int N = 1e6 + 7;
const int INF = 1e9 + 7;
const int mod = 998244353;
const int T = (1 << 20);

ld dp[N][10];
bool czy[N][10];
int krok[N][10];
int tab[N];

void solve(){
    int n, k; cin >> n >> k;

    for(int i = 0; i < N; i++)
        for(int j = 0; j < 10; j++)
            dp[i][j] = -INF;
    dp[0][1] = 0.0;

    for(int i = 1; i <= n; i++){
        int temp;
        cin >> temp;
        tab[i] = temp;

        long double siema = temp;

        for(int j = 0; j < 10; j++){
            int dig = (j * temp) % 10;
            ld val = dp[i -1 ][j] + std::log(siema);
            if(dp[i][dig] < val){
                krok[i][dig] = j;
                czy[i][dig] = 1;
                dp[i][dig] = val;
            }
        }

        for(int j = 0; j < 10; j++)
            if(dp[i][j] < dp[i - 1][j]){
                dp[i][j] = dp[i - 1][j];
                czy[i][j] = false;
            }
    }

    vi ans;

    if(dp[n][k] < 0){
        cout << "-1\n";
        exit(0);
    }
    
    int pom = k;

    for(int i = n; i >= 1; i--){
        if(czy[i][pom]){
            ans.pb(tab[i]);
            pom = krok[i][pom];
        }
    }
    if(sz(ans) == 0){
        cout << -1 << '\n';
        exit(0);
    }
    cout << sz(ans) << '\n';
    for(auto & u : ans)
        cout << u << ' ';
    cout << '\n';
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    //cin >> t;

    while(t--)
        solve();
}