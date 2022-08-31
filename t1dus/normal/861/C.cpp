/*input
sssddhi
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

bool isc(char c){
	if(c=='a')return false;
	if(c=='e')return false;
	if(c=='i')return false;
	if(c=='o')return false;
	if(c=='u')return false;
	return true;
}

bool iscs(char c1,char c2,char c3){
	return (c1==c2 and c2==c3)or(!(isc(c1)and isc(c2) and isc(c3)));
}

signed main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	string s;
	cin >> s;
	int n = s.length();
	if(s.length() <= 2){
		cout << s;
		return 0;
	}
	cout << s[0] << s[1];
	int cur = 2;
	bool taken[n+5];
	fill(taken,taken+n+5,true);
	while(cur < n){
		if((!taken[cur-1]) or iscs(s[cur],s[cur-1],s[cur-2])){
			cout << s[cur];
			cur ++;
		}
		else{
			cout << " " << s[cur];
			taken[cur] = false;
			cur ++;
		}
	}
}