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

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n; cin >> n;
	int a[n+5]; REP(i,n) cin >> a[i+1];
	
    int dp[n+5][3]; 
    
    dp[0][0] = dp[0][1] = dp[0][2] = 0;
    FOR(i,1,n+1){
        if (a[i] == 0){
            dp[i][0] = max(dp[i-1][0],max(dp[i-1][1],dp[i-1][2]));
            dp[i][1] = 0;
            dp[i][2] = 0;
        }
        else if(a[i] == 1){
            dp[i][0] = max(dp[i-1][0],max(dp[i-1][1],dp[i-1][2]));
            dp[i][1] = 1+max(dp[i-1][0],dp[i-1][2]);
            dp[i][2] = 0;
        }
        else if(a[i] == 2){
            dp[i][0] = max(dp[i-1][0],max(dp[i-1][1],dp[i-1][2]));
            dp[i][1] = 0;
            dp[i][2] = 1+max(dp[i-1][0],dp[i-1][1]);
        }
        else{
            dp[i][0] = max(dp[i-1][0],max(dp[i-1][1],dp[i-1][2]));
            dp[i][1] = 1+max(dp[i-1][0],dp[i-1][2]);
            dp[i][2] = 1+max(dp[i-1][0],dp[i-1][1]);
        }
    }
    cout << n-max(max(dp[n][0],dp[n][1]),dp[n][2]);
}