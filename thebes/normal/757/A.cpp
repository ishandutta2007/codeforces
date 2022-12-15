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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> ct(256);
	string s; sc(s);
	for(char c : s) ct[c]++;
	int ans = 0;
	//Bulbasaur aa B b l r s uu
	while(ct['a'] >= 2 && ct['B'] >= 1 && ct['b'] >= 1 && ct['l'] >= 1 && ct['r'] >= 1 && ct['s'] >= 1 && ct['u'] >= 2) {
		ans++;
		ct['a'] -= 2;
		ct['B']--;
		ct['b']--;
		ct['l']--;
		ct['r']--;
		ct['s']--;
		ct['u'] -= 2;
	}
	pr(ans, nl);
}