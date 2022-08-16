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

int power(int a,int b,int m = MOD){
	if(b == 0) return 1;
	if(b == 1) return a;
	int x = power(a,b/2,m)%m;
	x = (x*x)%m;
	if(b%2) return (x*a)%m;
	return x;
}

int n,l,r;

signed main(){
	cin >> n >> l >> r;
	int a = (r/3)-((l-1)/3), b = ((r+1)/3)-((l)/3), c = ((r+2)/3)-((l+1)/3);
	// cout << a << " " << b << " " << c << endl;
	int gg[3] = {a,b,c};
	int ans[3] = {1,0,0};
	FOR(i,1,n+1){
		int lol[3] = {0,0,0};
		REP(j,3){
			REP(k,3){
				lol[(j+k)%3] += gg[k]*ans[j];
				lol[(j+k)%3] %= MOD;
			}
		}
		REP(j,3) ans[j] = lol[j];
	}
	cout << ans[0] << endl;
}