/*input
3 4
abac
caab
acba
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

int k,n;
string a[5005];
int ham[5005];
bitset<5005> cn;

bool cm(string s1,string s2){
	int cnt[26];
	REP(i,26) cnt[i] = 0;
	for(char c:s1) cnt[c-'a'] ++;
	for(char c:s2) cnt[c-'a'] --;
	REP(i,26){
		if(cnt[i] != 0) return false;
	}	
	return true;
}

void solve(){
	cin >> k >> n;
	REP(i,k) cin >> a[i];
	REP(i,k){
		int lol[26];
		REP(j,26) lol[j] = 0;
		REP(j,n){
			lol[a[i][j]-'a']++;
			if(lol[a[i][j]-'a'] > 1){
				cn[i] = 1;
				break;
			}
		}
	}
	FOR(i,1,k){
		if(!cm(a[0],a[i])){
			cout << -1;
			return;
		}
	}
	FOR(i,1,k){
		ham[i] = 0;
		REP(j,n){
			if(a[0][j] != a[i][j]){
				ham[i] ++;
			}
		}
	}
	REP(l,n){
		FOR(m,l+1,n){
			string s1 = a[0];
			char c1 = s1[l];
			s1[l] = s1[m];
			s1[m] = c1;
			bool pos = true;
			FOR(i,1,k){
				int hm = ham[i];
				if(a[0][l] != a[i][l]) hm --;
				if(a[0][m] != a[i][m]) hm --;
				if(s1[l] != a[i][l]) hm++;
				if(s1[m] != a[i][m]) hm++;
				
				if(hm > 2){
					pos = false;
					break;
				}
				if(hm == 0){
					if(!cn[i]){
						pos = false;
						break;
					}
				}
			}
			if(pos){
				cout << s1;
				return;
			}
		}
	}
	cout << -1;
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	// cin >> t;
	WL(t) solve();
}