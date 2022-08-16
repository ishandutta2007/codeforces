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

string s;
int n;
int hsh[5005][5005];

bool palin(string lol){
	REP(i,lol.size()) if(lol[i] != lol[lol.size()-i-1]) return false;
	return true;
}

signed main() {
	cin >> s;
	n = s.length();
	set<char> C;
	REP(i,n){
		if(2*i+1 != n)
		C.insert(s[i]);
	}
	if(C.size() <= 1){
			cout << "Impossible\n";
			return 0;
	}
	FOR(i,1,n){
		string t = s.substr(i,n-i)+s.substr(0,i);
		// cout << t << endl;
		if(t != s and palin(t)){
			cout << "1\n";
			return 0;
		}
	}
	if(1 or s.substr(0,n/2) != s.substr((n+1)/2,n/2)){
		cout << "2\n";
		return 0;
	}
}