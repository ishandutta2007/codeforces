/*input
5 1
1 2 3 4 1
1 2 3 4 5
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

int n,k,ans[100005],pref[100005];
pair<pii,int> p[100005];

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k;
	REP(i,n) cin >> p[i].F.F;
	REP(i,n) cin >> p[i].F.S;
	REP(i,n) p[i].S = i;
	sort(p,p+n);
	pref[0] = 0;
	int tot = 0;
	priority_queue<int,vi,greater<int> > pq;
	REP(i,n){
		tot += p[i].F.S;
		pq.push(p[i].F.S);
		if(pq.size() > k){
			tot -= pq.top();
			pq.pop();
		}
		pref[i+1] = tot;
	}
	REP(i,n){
		int low = 0,high = n-1,mid,ind = 0;
		while(low <= high){
			mid = (low+high)/2;
			if(p[mid].F.F < p[i].F.F){
				low = mid+1;
				ind = mid+1;
			}
			else high = mid-1;
		}
		// cout << i << " " << p[i].F.F << " " << p[i].F.S << " " << p[i].S << " " << ind << endl;
		ans[p[i].S] = p[i].F.S+pref[ind];
	}
	REP(i,n) cout << ans[i] << " "; cout << "\n";
}