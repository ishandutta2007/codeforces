/*input
6 6
......
......
..SE..
......
......
......
01232123212302123021

*/		
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define int ll
#define pb push_back
#define INF 1000000000
#define MOD 1000000007
#define mp make_pair
const double PI=3.141592653589793238462643383279502884197169399375105820974944;
#define REP(i,n) for (int i = 0; i < n; i++)
#define FOR(i,a,b) for (int i = a; i < b; i++)
#define REPD(i,n) for (int i = n-1; i >= 0; i--)
#define FORD(i,a,b) for (int i = a; i >= b; i--)
#define remax(a,b) a = max(a,b)
#define remin(a,b) a = min(a,b)
#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define F first
#define S second
#define mii map<int,int>
#define vi vector<int>
#define vvi vector<vi>
#define itr :: iterator it
#define WL(t) while(t --)
#define gcd(a,b) __gcd((a),(b))
#define lcm(a,b) ((a)*(b))/gcd((a),(b))
#define print(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout << *it << " "; cout << endl;
#define debug(x) cout << x << endl;
#define debug2(x,y) cout << x << " " << y << endl;
#define debug3(x,y,z) cout << x << " " << y << " " << z << endl;

int power(int a,int b,int m = MOD){
	if(b == 0) return 1;
	if(b == 1) return a;
	int x = power(a,b/2,m)%m;
	x = (x*x)%m;
	if(b%2) return (x*a)%m;
	return x;
}

int n,m;
char a[55][55];
string s;
int p[4];

bool valid(int x,int y){
	return x >= 0 and y >= 0 and x < n and y < m;
}

void solve(){
	REP(i,4) p[i] = i;
	cin >> n >> m;
	pii start,fin;
	REP(i,n) REP(j,m){
		cin >> a[i][j];
		if(a[i][j] == 'S') start = {i,j};
		if(a[i][j] == 'E') fin = {i,j};
	}
	cin >> s;
	int ans = 0;
	REP(i,24){
		pii cur = start;
		bool lol = true;
		for(char c:s){
			char d = p[c-'0'];
			if(d == 0) cur.F ++;
			if(d == 1) cur.F --;
			if(d == 2) cur.S ++;
			if(d == 3) cur.S --;
			if((!valid(cur.F,cur.S)) or a[cur.F][cur.S] == '#'){
				lol = false;
				break;
			}
			if(cur == fin){
				break;
			}
		}
		if(cur == fin and lol) ans ++;
		next_permutation(p,p+4);
	}
	cout << ans;
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	// cin >> t;
	WL(t) solve();
}