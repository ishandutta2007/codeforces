/*input
5 3
3 2 1
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

int n,k,p[200005];
bitset<2000005> done;

void solve(){
	cin >> n >> k;
	int mx = 0,mn = n+1;
	REP(i,k) cin >> p[i];
	stack<int> s;
	int cur = 1;
	int idx = 0;
	int last = n;
	while(idx < n){
		if(idx >= k){
			if(s.empty()) last = n;
			else last = s.top()-1;
			// cout << last << " ";
			while(last and done[last]) last--;
			if(!last){
				cout << -1;
				return;
			}
			p[idx] = last;
			last --;
		}
		s.push(p[idx++]);
		while(s.empty() == false and s.top() == cur){
			s.pop();
			cur ++;
		}
		done[p[idx]] = 1;
		// cout << p[idx-1] << " ";
	}
	// cout << "\n";
	if(s.empty()){
		REP(i,n) cout << p[i] << " ";
	}
	else cout << -1;
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	// cin >> t;
	WL(t) solve();
}