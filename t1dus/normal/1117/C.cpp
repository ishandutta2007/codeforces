/*input

*/
#include <iostream>
#include <cstdio>
// #include <pair>
using namespace std;

typedef long long ll;
#define int ll
// typedef vector <int> vi;
// typedef vector<vi> vvi;
// typedef map<int,int> mii;
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

int x1,y1,x2,y2,X,Y;
int n;
pii a[100005];

bool check(int x){
	int orig = x;
	pii pos = {0,0};
	pos.F += (a[n].F)*(x/n);
	pos.S += (a[n].S)*(x/n);
	x %= n;
	pos.F += a[x].F;
	pos.S += a[x].S;
	if(abs(pos.F-X)+abs(pos.S-Y) <= orig) return true;
	return false;
}

signed main() {
	cin >> x1 >> y1;
	cin >> x2 >> y2;
	X = x2-x1;
	Y = y2-y1;
	cin >> n;
	a[0] = {0,0};
	FOR(i,1,n+1){
		a[i] = a[i-1];
		char c; cin >> c;
		if(c == 'U'){
			a[i].S++;
		}
		else if(c == 'D') a[i].S--;
		else if(c == 'L') a[i].F --;
		else a[i].F++;
	}
	int low = 0,high = 1000000000000000,mid,ans = -1;
	while(low <= high){
		mid = (low+high)/2;
		if(check(mid)){
			ans = mid;
			high = mid-1;
		}
		else low = mid+1;
	}
	cout << ans << endl;
}