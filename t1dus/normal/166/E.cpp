#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef tree<int,null_type,less<int>,rb_tree_tag,
tree_order_statistics_node_update> indexed_set;
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
#define int long long

signed main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    int n;
    cin >> n;
    int dp[n+5][2];
    dp[1][0] = 1;dp[1][1] = 0;
    dp[2][0] = 2;dp[2][1] = 3;
    FOR(i,3,n+5){
        dp[i][1] = (3*dp[i-1][0])%MOD;
        dp[i][0] = (2*dp[i-1][0]+dp[i-1][1])%MOD;
    }
    cout << dp[n][1];
}

/*
   
n = int(input())
dp = []
for _ in range(n+5):
    dp.append([0,0])

dp[1] = [1,0]
dp[2] = [2,3]

for i in range(3,n+5):
    dp[i][1] = ((3)*dp[i-1][0])%MOD
    dp[i][0] = ((2)*dp[i-1][0]+dp[i-1][1])%MOD

print(dp[n][1])

*/