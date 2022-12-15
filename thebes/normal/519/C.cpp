#include <bits/stdc++.h>
#define gl(x) getline(cin,x)
#define gc(x) cin.get(x)
#define sz(x) (int)(x.size())
#define al(x) (x).begin(), (x).end()
#define ms(a, b) memset(a,b,sizeof(a))
#define sp ' '
#define nl '\n'
#define fi first
#define se second
#define lsb(x) ((x)&(-x))
using namespace std;
void sc(){}template<class T,class...A>void sc(T&t,A&...a){cin>>t,sc(a...);}
void pr(){}template<class T,class...A>void pr(T t, A...a){cout<<t,pr(a...);}
typedef long long ll;
typedef pair<int, int> pi;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m; sc(n, m);
	int ct = 0;
	bool ok = true;
	while(ok) {
		if(n >= m && n >= 2 && m >= 1) n -= 2, m--, ct++;
		else if(m >= n && m >= 2 && n >= 1) m -= 2, n--, ct++;
		else ok = false;
	}
	pr(ct, nl);
}