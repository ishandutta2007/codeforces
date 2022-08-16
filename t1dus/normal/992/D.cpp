/*input
65 58
1 1 29 1 1 1 1 2 1 58 1 1 2 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 2 1 1 1 29 1 1 1 1 1 58 1 29 1 1 1 1 1 1 1 1 1 1 1 1 58 1 1 1 1 1 2 1 1 1
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

int n,k,a[200005],one[200005];

void solve(){
	cin >> n >> k;
	REP(i,n) cin >> a[i];
	int ans = 0;
	if(a[n-1] == 1) one[n-1] = n-1;
	else one[n-1] = -1;
	for(int i = n-2; i >= 0; i --){
		if(a[i] != 1) one[i] = -1;
		else{
			if(one[i+1] == -1) one[i] = i;
			else one[i] = one[i+1];
		}
	}
	REP(i,n){
		int p = a[i],s = a[i];
		if(k == 1) ans++;
		int j = i+1;
		while(j < n){
			if(a[j] > ((ll)3e18)/p) break;
			if(a[j] == 1){
				s ++;
				int sn = (p/k)-s;
				// cout << i << " " << j << " " << p << " " << s << endl;
				if((p%k == 0) and one[j]-j >= sn and sn >= 0){
					ans++;
					// cout << i << " " << j << " " << sn << endl;

				}
				s += one[j]-j;
				j = one[j]+1;
			}
			else{
				p*=a[j];
				s+=a[j];
				// cout << i << " " << j << " " << p << " " << s << endl;
				if(p == s*k){
					ans++;
					// cout << " ---------------" << i << " " << j << " " << p << " " << s << endl;
				}
				j ++;
			}
		}
	}
	cout << ans << endl;
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	// cin >> t;
	WL(t) solve();
}