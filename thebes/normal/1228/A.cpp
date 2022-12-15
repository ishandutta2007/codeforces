#include <bits/stdc++.h>
#define gl(x) getline(cin,x)
#define gc(x) cin.get(x)
#define sz(x) (int)(x.size())
#define al(x) (x).begin(),(x).end()
#define ms(a, b) memset(a,b,sizeof(a))
#define sp ' '
#define nl '\n'
#define fi first
#define se second
#define lsb(x) ((x)&(-x))
using namespace std;
void sc(){}template<class T,class...A>void sc(T&t,A&...a){cin>>t,sc(a...);}
void pr(){}template<class T,class...A>void pr(T t,A...a){cout<<t,pr(a...);}
typedef long long ll;
typedef pair<int, int> pi;
typedef double db;
typedef long double ld;

bool ok(int x) {
	string s = to_string(x);
	vector<int> ct(256);
	for(char c : s) ct[c]++;
	for(char c = '0'; c <= '9'; c++) if(ct[c] > 1) return false;
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int l, r; sc(l, r);
	int ans = -1;
	for(int i = l; i <= r && ans == -1; i++) {
		if(ok(i)) ans = i;
	}
	pr(ans, nl);
}