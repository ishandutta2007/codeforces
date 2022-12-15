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
	int n; sc(n);
	string s; sc(s);
	int l = 0, r = 0;
	for(char c : s) {
		if(c == '(') l++; else r++;
	}
	if(l != r) pr("No\n");
	else {
		vector<int> b(n);
		for(int i = 0; i < n; i++) {
			if(i == 0) b[i] = 0; else b[i] = b[i - 1];
			if(s[i] == '(') b[i]++; else b[i]--;
		}
		int mn = *min_element(al(b));
		if(mn < -1) pr("No\n");
		else pr("Yes\n");
	}
}