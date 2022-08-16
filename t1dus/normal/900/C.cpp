/*input
5
4 3 5 1 2
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

#define SZ 100005

int n,a[SZ];
int seg[200005];

void solve(){
	cin >> n;
	set<int> st;
	int small[SZ];
	REP(i,n){ 
		cin >> a[i];
		st.insert(a[i]);
		auto it = st.find(a[i]);
		int cnt = -1;
		while(it != st.end()){
			it ++;
			cnt ++;
			if(cnt == 2) break;
		}
		small[a[i]] = cnt;
		// cout << a[i] << " " << small[a[i]] << endl;
	}
	st.clear();
	int ans = -2,el = -2;
	for(int i = n-1; i >= 0; i--){
		int cnt = 0;
		int l = n+1,r = a[i]+n+1;
		while(l < r){
			if(l%2) cnt += seg[l++];
			if(r%2) cnt += seg[--r];
			l /= 2; r /= 2; 
		} 
		// cout << "\n";
		if(small[a[i]] == 0) cnt --;
		if(cnt > ans) ans = cnt,el = a[i];
		else if(cnt == ans and a[i] < el) el = a[i]; 
		if(small[a[i]] == 1){
			int p = a[i]+n+1;
			while(p) seg[p] ++,p /= 2;
		}
		// cout << a[i] << " " << cnt << " " << small[a[i]] << endl;
	}
	cout << el << endl;
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	// cin >> t;
	WL(t) solve();
}