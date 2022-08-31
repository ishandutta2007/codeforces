/*input
5
6 3 4 1 5
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

int n,a[200005];
set<pii> lens,segs;

void solve(){
	cin >> n;
	REP(i,n) cin >> a[i];
	int cnt = 1,start = 0;
	FOR(i,1,n){
		if(a[i] == a[i-1]) cnt++;
		else{
			lens.insert({cnt*-1,start});
			segs.insert({start,cnt});
			start = i;
			cnt = 1;
		}
	}
	lens.insert({cnt*-1,start});
	segs.insert({start,cnt});
	int ans = 0;
	while(lens.size()){
		ans ++;
		pii lol = *lens.begin();
		lens.erase(lens.begin());
		set<pii> :: iterator it2,it = segs.lower_bound({lol.S,-lol.F});
		it2 = it;
		it2 ++;
		if(it == segs.begin() or it2 == segs.end()){
			segs.erase(it);
			continue;
		}
		it --;
		if(a[(*it).F] == a[(*it2).F]){
			int tots = (*it).F;
			int totc = (*it).S+(*it2).S;
			lens.erase({-((*it).S),(*it).F});
			lens.erase({-((*it2).S),(*it2).F});
			lens.insert({-totc,tots});
			it2++;
			segs.erase(it,it2);
			segs.insert({tots,totc}); 
		}
		else{
			it ++;
			segs.erase(it);
		}
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