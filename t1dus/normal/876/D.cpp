/*input
8
6 8 3 4 7 2 1 5
*/		
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define int ll
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
const double PI=3.141592653589793238462643383279502884197169399375105820974944;
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

int seg[1000005];
int n,a[300005];

void upd(int x){
	x += n;
	while(x){
		seg[x] ++;
		x /= 2;
	}
}

int quer(int l,int r){
	l += n;
	r += n+1;
	int cur = 0;
	while(l < r){
		if(l%2) cur += seg[l++];
		if(r%2) cur += seg[--r];
		l /= 2;
		r /= 2;
	}
	return cur;
}

signed main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n;
	REP(i,n) cin >> a[i];
	cout << "1 ";
	REP(i,n){
		a[i] --;
		upd(a[i]);
		int low = 0;
		int high = n-1;
		int ans = 0;
		while(low <= high){
			int mid = (low+high)/2;
			if(quer(mid,n-1) == (n-mid)){
				high = mid-1;
				ans = (n-mid);
			}
			else{
				low = mid+1;
			}
		}
		cout << i+2-ans << " "; 
	}
}