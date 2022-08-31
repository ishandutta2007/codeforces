/*input
10 4
agtFrgF4aF
2 5 g
4 9 F
1 5 4
1 7 a
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

int seg[400005];

int n,m;
string s;

set<int> st[80];

int quer(int l,int r){
	l += n;
	r += n+1;
	int res = 0;
	while(l < r){
		if(l%2) res += seg[l++];
		if(r%2) res += seg[--r];
		l /= 2;
		r /= 2; 
	}
	return res;
}

void upd(int pos){
	pos += n;
	seg[pos] = 0;
	pos /= 2;
	while(pos){
		seg[pos] = seg[pos*2]+seg[pos*2+1];
		pos /= 2;
	}
}

void solve(){
	cin >> n >> m;
	cin >> s;
	REP(i,n){
		seg[i+n] = 1;
		// cout << s[i]-'0' << endl;
		st[s[i]-'0'].insert(i);
	}
	for(int i = n-1; i >= 1; i--) seg[i] = seg[2*i]+seg[2*i+1];

	REP(i,m){
		int l,r;
		char c;
		cin >> l >> r >> c;

		int low = 0,high = n-1,mid,orl,orr;
		while(low <= high){
			mid = (low+high)/2;
			int x = quer(0,mid);
			// cout << mid << " " << x << endl;
			if(x < l){
				low = mid+1;
			}
			else if(x > l) high = mid-1;
			else{
				orl = mid;
				high = mid-1;
			}
		}
		// cout << l << " - " << r << endl;
		low = 0,high = n-1;
		while(low <= high){
			mid = (low+high)/2;
			int x = quer(0,mid);
			// cout << mid << " " << x << endl;
			if(x < r){
				low = mid+1;
			}
			else if(x > r) high = mid-1;
			else{
				orr = mid;
				high = mid-1;
			}
		}
		l = orl;
		r = orr;
		// cout << l << " --- " << r << endl;
		set<int> :: iterator it2,it = st[c-'0'].lower_bound(l);
		it2 = it;
		while(it2 != st[c-'0'].end() and *it2 <= r){
			upd(*it2);
			// cout << c << " " << *it2 << endl;
			it2 ++;
		}
		st[c-'0'].erase(it,it2);
	}
	char a[n];
	REP(i,n) a[i] = '.';
	REP(i,80){
		for(auto x:st[i]) a[x] = s[x];
	}
	REP(i,n){
		if(a[i] != '.') cout << a[i];
	}
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	// cin >> t;
	WL(t) solve();
}