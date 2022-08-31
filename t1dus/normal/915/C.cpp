/*input
11
11
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

int n;
string s1,s2;

bool pos(int ind,multiset<char> s){
	if(ind == n) return true;
	vector<char> v;
	for(char c:s) v.pb(c);
	sort(all(v));
	if(v[0] > s2[ind]) return false;
	if(v[0] == s2[ind]){
		s.erase(s.find(v[0]));
		return pos(ind+1,s);
	}
	return true;
}

void solve(){
	cin >> s1 >> s2;
	n = s1.length();
	multiset<char> tot;
	for(auto c:s1) tot.insert(c);
	bool lol = true;
	if(s2.length() > s1.length()) lol = false;	
	int hehe = 0;
	if(s2.length() < s1.length()){
		REP(i,s1.length()-s2.length()){
			cout << 0;
			tot.erase(tot.find('0'));
			n--;
		}
	}
	FOR(i,hehe,n){
		if(lol){
			if(tot.find(s2[i]) != tot.end()){
				tot.erase(tot.find(s2[i]));
				if(pos(i+1,tot)){
					cout << s2[i];
					continue;
				}
				tot.insert(s2[i]);
			}
			lol = false;
			for(int j = (s2[i]-'0')-1; j >= 0; j--){
				if(tot.find(j+'0') != tot.end()){
					cout << j;
					tot.erase(tot.find(j+'0'));
					break;
				}
			}
		}
		else{
			vector<char> v;
			for(auto c:tot) v.pb(c);
			sort(all(v));
			for(int j = v.size()-1; j >= 0; j--) cout << v[j];
			break;	
		}
	}	
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	// cin >> t;
	WL(t) solve();
}