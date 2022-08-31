/*input
6
1 2 3 10 20 30
6 5 4 3 2 0

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

int n,a[100005],b[100005],dp[100005];

struct line{
	int m,b,l,r;
};

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	FOR(i,1,n+1) cin >> a[i];
	FOR(i,1,n+1) cin >> b[i];
	dp[1] = 0;
	deque<line> q;
	q.push_back({b[1],0,1,(int)1e9});
	FOR(i,2,n+1){
		while(q.size()){
			if(q.front().r >= a[i]){
				dp[i] = q.front().m*a[i]+q.front().b;
				break;
			}
			else q.pop_front();
		}
		line lol = {b[i],dp[i],-1,-1},lol2;
		while(q.size()){
			// x = (q.back().b-dp[i])/(b[i]-q.back().m);
			int num = q.back().b-dp[i],den = b[i]-q.back().m;
			int x = (num+den-1)/den;
			if(x <= q.back().l) q.pop_back();
			else{
				lol.l = x;
				lol.r = (int)1e9;
				lol2 = q.back();
				q.pop_back();
				lol2.r = x-1;
				q.push_back(lol2);
				q.push_back(lol);
				break;
			}
		}
		if(q.empty()) q.push_back({b[i],dp[i],1,(int)1e9});
	}
	cout << dp[n] << endl;
}