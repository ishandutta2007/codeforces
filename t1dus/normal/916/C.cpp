/*input
4 4
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
vi primes;

void solve(){
	cin >> n >> m;
	if(n == 2){
		cout << "2 2\n1 2 2\n";
		return;
	}
	primes.pb(2);
	FOR(i,3,500005){	
		for(auto x:primes){
			if(x*x > i){
				primes.pb(i);
				break;
			}
			if(i%x == 0) break;
		}
	}
	vvi edges;
	set<pii> done;
	done.insert({1,n});
	done.insert({2,n});
	edges.pb({1,n,2});
	edges.pb({2,n,1});
	int tot = 3;
	FOR(i,2,n-2){
		edges.pb({i,i+1,1});
		done.insert({i,i+1});
		tot ++;
	}
	int ind = lower_bound(all(primes),tot+1)-primes.begin();
	if(n > 3){
		edges.pb({n-2,n-1,primes[ind]-tot});
		done.insert({n-2,n-1});
		cout << "2 " << primes[ind] << endl;
	}
	else cout << "2 3\n";
	m -= n-1;
	int u = 1,v = 2;
	while(m){
		if(done.find({u,v}) != done.end()){
			v ++;
			if(v == n+1){
				u ++;
				v = u+1;
			}
			continue;
		}
		done.insert({u,v});
		edges.pb({u,v,INF});
		m --;
	}
	for(auto x:edges){
		cout << x[0] << " " << x[1] << " " << x[2] << endl;
	}
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	srand(time(0));

	int t = 1;
	// cin >> t;
	WL(t) solve();
}