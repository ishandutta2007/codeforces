/*input

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

int n;
string T,t1,t2,t3;
string s,s1,s2,s3;
string res[3];
vi v[26];
int conv[10001];

signed main() {
	cin >> T;
	n = T.length();
	int cur = 0;
	REP(i,26){
		REP(j,26){
			REP(k,26){
				s1 += ('a'+i);
				s2 += ('a'+j);
				s3 += ('a'+k);
				cur ++;
				if(cur == n) break;
			}
			if(cur == n) break;
		}
		if(cur == n) break;
	}
	cout << "? " << s1 << endl;
	cin >> t1;
	cout << "? " << s2 << endl;
	cin >> t2;
	cout << "? " << s3 << endl;
	cin >> t3;
	REP(i,n){
		v[t1[i]-'a'].pb(i);
	}
	REP(i,n){
		int ind = -1;
		for(auto x:v[s1[i]-'a']){
			if(s1[i] == t1[x] and s2[i] == t2[x] and s3[i] == t3[x]){
				ind = x;
				break;
			}
		}
		conv[i] = ind;
	}
	s = T;
	REP(i,n){
		s[i] = T[conv[i]];
	}
	cout << "! " << s << endl;
}