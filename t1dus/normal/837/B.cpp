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
	
	int n,m;
	cin >> n >> m;
	char a[n][m];
	REP(i,n){
	    REP(j,m){
	        cin >> a[i][j];
	    }
	}
	bool ans = false;
	char b[n][m];
	if (n%3 == 0){
	    REP(i,n) REP(j,m) b[i][j] = 'x';
	    REP(i,n/3) REP(j,m) b[i][j] = a[0][0];
	    FOR(i,n/3,2*(n/3)) REP(j,m) b[i][j] = a[n/3][0];
	    FOR(i,2*(n/3),n) REP(j,m) b[i][j] = a[2*(n/3)][0];
	    bool cur = true;
	    REP(i,n) REP(j,m) if (b[i][j] != a[i][j]) cur = false;
	    if (a[0][0] == a[n/3][0] or a[n/3][0] == a[2*(n/3)][0] or a[2*(n/3)][0] == a[0][0]) cur = false;
	    if (cur) ans = true;
	}
	if (m%3 == 0){
	    REP(i,n) REP(j,m) b[i][j] = 'x';
	    REP(i,n) REP(j,m/3) b[i][j] = a[0][0];
	    REP(i,n) REP(j,m/3) b[i][j+(m/3)] = a[0][m/3];
	    REP(i,n) REP(j,m/3) b[i][j+(2*(m/3))] = a[0][2*(m/3)];
	    bool cur = true;
	    REP(i,n) REP(j,m) if (b[i][j] != a[i][j]) cur = false;
	    if (a[0][0] == a[0][m/3] or a[0][m/3] == a[0][2*(m/3)] or a[0][2*(m/3)] == a[0][0]) cur = false;
	    if (cur) ans = true;
	}
	if (ans) cout << "YES\n";
	else cout << "NO\n";
	
}