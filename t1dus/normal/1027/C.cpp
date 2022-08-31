/*input
3
4
7 2 2 7
8
2 8 1 4 8 2 1 5
5
5 5 5 5 5
*/		
#include<bits/stdc++.h>
using namespace std;

#define ll long long
// #define int ll
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

int n;
set<int> st;
vi v;

signed main(){
	int t; scanf("%d",&t);
	WL(t){
		scanf("%d",&n);
		v.clear();
		REP(i,n){
			int x; scanf("%d",&x);
			if(st.find(x) != st.end()){
				v.pb(x);
				st.erase(x);
			}
			else st.insert(x);
		}
		st.clear();
		sort(all(v));
		ll num = v[0]*v[0]+v[1]*v[1],den = v[0]*v[1],ind = 0;
		FOR(i,1,v.size()-1){
			ll n2 = v[i]*v[i]+v[i+1]*v[i+1],d2 = v[i]*v[i+1];
			if(den*n2 < num*d2){
				ind = i;
				num = n2;
				den = d2;
			}
		}
		// cout << v[ind] << " " << v[ind] << " " << v[ind+1] << " " << v[ind+1] << endl;
		printf("%d %d %d %d\n",v[ind],v[ind],v[ind+1],v[ind+1]);
	}
}