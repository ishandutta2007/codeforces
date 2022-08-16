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

int n,m;
string s;
set<string> a,b;

bool contains(string x,char y){
	for(char c:x){
		if(c == y) return true;
	}
	return false;
}

signed main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> s >> m;
	REP(i,m) {
		string s1; cin >> s1;
		string s2;
		bool flag = true;
		REP(i,n){
			if(s[i] == '*') s2 += s1[i];
			else if(s1[i] != s[i]) flag = false; 
		}
		if(!flag) continue;
		a.insert(s2);
		// a.insert(s1);
	}
	set<char> pos;
	for(char c:"abcdefghijklmnopqrstuvwxyz") pos.insert(c); 
	for(char c:s){
		if(c != '*' and pos.find(c) != pos.end()) pos.erase(c);
	}
	for(auto s1: a){
		bool flag = true;
		for(char c:s1){
			if(pos.find(c) == pos.end()) flag = false;
		}
		if(flag)b.insert(s1);
	}
	int ans = 0;
	if(b.size() == 0){
		cout << 0 << endl;
		return 0;
	}
	for(char c:pos){
		bool flag = true;
		for(string s1:b){
			if(!contains(s1,c)){
				flag = false;
				break;
			}
		}
		if(flag) ans++;
	}
	cout << ans << endl;
}