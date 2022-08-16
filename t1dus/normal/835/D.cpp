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
	
	string s;cin >> s;
	int n = s.length();
	int dp[n+5][n+5],cnt[n+5];
	REP(i,n+5){
	    cnt[i] = 0;
	    REP(j,n+5){
	        dp[i][j] = 0;
	    }
	}
	REPD(i,n-1){
	    FOR(j,i,n){
	        if (i == j) dp[i][j] = 1;
	        else if (i == j-1){
	            if (s[i] == s[j]) dp[i][j] = 2;
	        }
	        else{
	            if (!(s[i] != s[j] or dp[i+1][j-1] == 0))dp[i][j] = dp[i][(i+j-1)/2]+1;
	        }
	    }
	}
	REP(i,n){
	    REP(j,n){
	        cnt[dp[i][j]] ++;
	    }
	}
	FORD(i,n-1,1) cnt[i] += cnt[i+1];
	FOR(i,1,n+1) cout << cnt[i]  << " ";
}