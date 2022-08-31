/*input
4
6
1 2 1
3 4 1
2 3 2
1 3 2
2 4 1
1 4 2
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

int n,q;
set<pii> s;

void solve(){
	scanf("%d%d",&n,&q);
	int cur = n;
	WL(q){
		int l,r,k;
		// cin >> l >> r >> k;
		scanf("%d%d%d",&l,&r,&k);
		if(k == 1){
			if(s.size() == 0){
				cur -= (r-l+1);
				s.insert({l,r});
			}
			else{
				auto ind = s.upper_bound({r+1,0});
				if(ind == s.begin()){
					s.insert({l,r});
					cur -= (r-l+1);
				}
				else{
					vector<pii> v;
					ind --;
					while(ind != s.begin()){
						pii ind2 = *ind;
						if(ind2.S >= l) v.pb(*ind);
						else break;
						ind --;
					}
					pii ind2 = *ind;
					if(ind2.S >= l) v.pb(*ind);
					int hehe1 = l,hehe2 = r;
					for(auto x:v){
						s.erase(x);
						remin(hehe1,x.F);
						remax(hehe2,x.S);
						cur += x.S-x.F+1;
					}
					cur -= hehe2-hehe1+1;
					s.insert({hehe1,hehe2});
				}
			}
		} 
		else{
			if(s.size() != 0){
				auto ind = s.upper_bound({r+1,0});
				if(ind != s.begin()){
					vector<pii> v;
					ind --;
					while(ind != s.begin()){
						pii ind2 = *ind;
						if(ind2.S >= l) v.pb(*ind);
						else break;
						ind --;
					}
					pii ind2 = *ind;
					if(ind2.S >= l) v.pb(*ind);
					int hehe1 = l,hehe2 = r;
					for(auto x:v){
						s.erase(x);
						remin(hehe1,x.F);
						remax(hehe2,x.S);
						cur += x.S-x.F+1;
					}
					cur -= hehe2-r;
					cur -= l-hehe1;
					if(hehe1 < l) s.insert({hehe1,l-1});
					if(hehe2 > r) s.insert({r+1,hehe2});
				}
			}
		}
		printf("%d\n",cur);
	}
}

signed main(){
	// ios_base::sync_with_stdio(false);
	// cin.tie(0);
	// cout.tie(0);

	int t = 1;
	// cin >> t;
	WL(t) solve();
}