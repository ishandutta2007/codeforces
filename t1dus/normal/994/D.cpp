/*input
2 3
1 2 4 5
1 2 1 3 2 3

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
pii a[30],b[30];
set<int> cnt[30][2];

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	REP(i,n) cin >> a[i].F >> a[i].S;
	REP(i,m) cin >> b[i].F >> b[i].S;
	REP(i,n){
		if(a[i].F > a[i].S) swap(a[i].F,a[i].S);
	}
	REP(j,m){
		if(a[j].F > a[j].S) swap(a[j].F,a[j].S);
	}
	int lol = 0;
	set<int> lol2;
	REP(i,n) REP(j,m){
		if(a[i].F == b[j].F and a[i].S == b[j].S) continue;
		if(a[i].F == b[j].F or a[i].S == b[j].S or a[i].F == b[j].S or a[i].S == b[j].F){
			// cout << i << " " << j << endl;
			int num;
			if(a[i].F == b[j].F or a[i].F == b[j].S) num = a[i].F;
			else num = a[i].S;
			cnt[i][0].insert(num);
			cnt[j][1].insert(num);
			lol2.insert(num);
			lol = max(lol,(ll)max(cnt[i][0].size(),cnt[j][1].size()));
		}
	}
	if(lol >= 2) cout << "-1\n";
	else if(lol2.size() >= 2) cout << "0\n";
	else cout << *lol2.begin() << endl;
}