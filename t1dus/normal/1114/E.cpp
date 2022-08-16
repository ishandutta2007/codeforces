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

int n;
vi v;
bitset<1000005> done;

signed main() {
	cin >> n;
	mt19937 gen(time(NULL));
  uniform_int_distribution<int> range(1, n);
  auto RAND = bind(range, gen);
	int low = 0,high = 1000000000,mid,hgh = 1000000000;
	while(low <= high){
		mid = (low+high)/2;
		cout << "> " << mid << endl;
		fflush(stdout);
		int inp; cin >> inp;
		assert(inp != -1);
		if(inp == 0){
			high = mid-1;
			hgh = mid;
		}
		else low = mid+1;
	}
	done.reset();
	REP(i,30){
		int x = RAND();
		int mkc = 0;
		while(done[x]){
			x = RAND();
			mkc ++;
			if(mkc > 100) break;
		}
		if(mkc > 100) break;
		done[x] = 1;
		cout << "? " << x << endl;
		fflush(stdout);
		int inp; cin >> inp;
		assert(inp != -1);
		v.pb(inp);
	}
	int g = -1;
	REP(i,v.size()){
		REP(j,v.size()){
			if(v[i] != v[j]){
				if(g == -1) g = abs(v[i]-v[j]);
				else g = gcd(abs(v[i]-v[j]),g);
			}
		}
	}
	assert(g != -1);
	assert(hgh-(n-1)*g >= 0);
	cout << "! " << hgh-(n-1)*g << " " << g << endl;
	fflush(stdout);
}