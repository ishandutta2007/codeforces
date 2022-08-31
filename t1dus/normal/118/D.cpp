#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector <int> vi;
typedef vector<vi> vvi;
typedef map<int,int> mii;
typedef pair<int,int> pii;
#define pb push_back
#define INF 1000000000
#define mp make_pair
#define MOD 100000000
#define F first
#define S second
const double PI=3.14159265358979323846264338327950288419716939937510582097494459230;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REPD(i,n) for(int i=(n);i>=0;i--)
#define FORD(i,a,b) for(int i=(a);i>=b;i--)
#define all(v) v.begin(),v.end()
#define itr ::iterator it
#define WL(t) while(t --)
#define gcd(a,b) __gcd((a),(b))
#define lcm(a,b) ((a)*(b))/gcd((a),(b))
#define remin(a,b) (a) = min((a),(b))
#define remax(a,b) (a) = max((a),(b))
#define int ll

int n1,n2,k1,k2;
int dp[105][105][2];

int solve(int a, int b, int last){
    // cout << a << " " << b << " " << last << endl;
    if (a == b and b == 0) return 1;
    if ((b == 0 and last == 1) or (a == 0 and last == 0)) return 0;
    if (dp[a][b][last] != -1) return dp[a][b][last];
    int ans = 0;
    if (last == 0){
        for(int i = 1; i <= min(a,k1); i++) ans = (ans+solve(a-i,b,1))%MOD;
    }
    else{
        for(int i = 1; i <= min(b,k2); i++) ans = (ans+solve(a,b-i,0))%MOD;
    }
    // cout << a << " " << b << " " << last << " " << ans << endl;
    return dp[a][b][last] = ans;
}

signed main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n1 >> n2 >> k1 >> k2;
	REP(i,105) REP(j,105) REP(k,2) dp[i][j][k] = -1;
	cout << (solve(n1,n2,0)+solve(n1,n2,1))%MOD << endl;
}