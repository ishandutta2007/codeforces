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

int n;
pair<pii,int> a[200005];
int seg[5000000];
int MX = 2000000;

void solve(){
	cin >> n;
	set<int> st;
	REP(i,n){
		cin >> a[i].F.F >> a[i].F.S;
		st.insert(a[i].F.F);
		st.insert(a[i].F.S);
		a[i].S = i;
	}
	mii dc;
	int cur = 1;
	for(auto x:st){
		dc[x] = cur;
		cur ++;
	}
	sort(a,a+n);
	REP(i,n){
		a[i].F.F = dc[a[i].F.F];
		a[i].F.S = dc[a[i].F.S];
	}
	vi v(n);
	for(int i = n-1; i >= 0; i --){
		int ans = 0;
		int l = a[i].F.F+1+MX;
		int r = a[i].F.S+MX;
		while(l < r){
			if(l%2) ans += seg[l++];
			if(r%2) ans += seg[--r];
			l /= 2;
			r /= 2;
		}
		int p = a[i].F.S+MX;
		while(p){
			seg[p] ++;
			p /= 2;
		}
		v[a[i].S] = ans;
	}
	for (auto x:v) cout << x << endl;
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	// cin >> t;
	WL(t) solve();
}