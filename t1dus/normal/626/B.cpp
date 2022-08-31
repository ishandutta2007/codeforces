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
#define MOD 1000000007
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

int dp[205][205][205];
int solve(int a,int b,int c){
    if(dp[a][b][c] != -1) return dp[a][b][c];
    int ans = 0;
    if (a > 1) ans |= solve(a-1,b,c);
    if (b > 1) ans |= solve(a,b-1,c);
    if (c > 1) ans |= solve(a,b,c-1);
    if (a > 0 and b > 0) ans |= solve(a-1,b-1,c+1);
    if (c > 0 and b > 0) ans |= solve(a+1,b-1,c-1);
    if (a > 0 and c > 0) ans |= solve(a-1,b+1,c-1);
    return dp[a][b][c] = ans;
}

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	REP(i,205) REP(j,205) REP(k,205) dp[i][j][k] = -1;
	dp[0][0][0] = 0;
	dp[1][0][0] = 1;
	dp[0][1][0] = 2;
	dp[0][0][1] = 4;
	int n,a = 0,b = 0,c = 0;
	cin >> n;
	REP(i,n){
	    char col; cin >> col;
	    if (col == 'B') a ++;
	    else if(col == 'G') b++;
	    else c++;
	}
	int x = solve(a,b,c);
	if (x & 1) cout << "B";
	if (x & 2) cout << "G";
	if (x & 4) cout << "R";
}