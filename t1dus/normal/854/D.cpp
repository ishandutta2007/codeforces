/*input

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
#define INF 10000000000005
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

int pref[1000505];
vvi a;
vi xyz(4);
int n,m,k;
int mn[1000505];

signed main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m >> k;
	REP(i,m){
		cin >> xyz[0] >> xyz[1] >> xyz[2] >> xyz[3];
		a.pb(xyz);
	}
	sort(all(a));
	fill(mn,mn+1000005,INF);
	fill(pref,pref+1000005,INF*n);
	int cur = 0;
	FOR(i,1,1000005){
		pref[i] = pref[i-1];
		if(cur < m and a[cur][0] == i){
			while(a[cur][0] == i){
				if(a[cur][1] == 0) cur ++;
				else{
					if(a[cur][3] < mn[a[cur][1]]){
						pref[i] -= mn[a[cur][1]];
						pref[i] += a[cur][3];
						mn[a[cur][1]] = a[cur][3];
					}
					cur++;
				}
				if(cur == m) break;
			}
		}
		// assert(pref[i] >= 0);
	}
	fill(mn,mn+n+5,INF);
	cur = INF*n;
	int ans = INF*n;
	
	// for(int i = 0; i < 10; i ++) cout << pref[i] << " "; cout << "\n";

	reverse(all(a));

	for(vi i:a){
		if(i[1] == 0){
			if(i[3] < mn[i[2]]){
				cur -= mn[i[2]];
				cur += i[3];
				mn[i[2]] = i[3];
			}
			// assert(cur >= 0);
			if(i[0]-k-1 >= 1) remin(ans,cur+pref[i[0]-k-1]);
		}
	} 
	if(ans > 2*n*1000000){
		cout << -1;
		return 0;
	}
	cout << ans << endl;
}