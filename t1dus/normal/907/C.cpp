/*input
8
! hello
! codeforces
? c
. o
? d
? h
. l
? e
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

bool pos[26];

void solve(){
	REP(i,26) pos[i] = 1;
	int n;
	cin >> n;
	int cnt = 0;
	char ans = ';';
	REP(i,n){
		char type; cin >> type;
		if(type == '!'){
			string s; cin >> s;
			if(ans != ';') cnt ++;
			else{
				bitset<26> lol;
				for(char c:s) lol[c-'a'] = 1;
				int tot = 0;
				char ind = ';';
				// cout << lol << endl;
				REP(j,26){
					if(pos[j] == 1 and lol[j] == 0) pos[j] = 0;
					if(pos[j]){
						ind = 'a'+j;
						tot ++;
					}
				}	
				// REP(i,26) cout << pos[i]; cout << "\n";
				if(tot == 1) ans = ind;
			}
		}
		else if(type == '.'){
			string s; cin >> s;
			if(ans != ';') continue;
			else{
				for(char c:s) pos[c-'a'] = 0;
				int tot = 0;
				char ind = ';';
				REP(j,26){
					if(pos[j]){
						ind = 'a'+j;
						tot ++;
					}
				}	
				if(tot == 1) ans = ind;
			}
		}
		else{
			char c; cin >> c;
			if(c != ans and ans != ';'){
				cnt ++;
				// cout << c << "-\n";
			}
			else{
				pos[c-'a'] = 0;
				int tot = 0;
				char ind = ';';
				REP(j,26){
					if(pos[j]){
						ind = 'a'+j;
						tot ++;
					}
				}	
				if(tot == 1) ans = ind;
			}
		}
	}
	// cout << ans << endl;
	cout << cnt;
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	// cin >> t;
	WL(t) solve();
}