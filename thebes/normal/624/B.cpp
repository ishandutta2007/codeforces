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
	vector<int> a(n);
	for(int i = 0; i < n; i++) sc(a[i]);
	sort(al(a), greater<>());
	ll ans = a[0];
	for(int i = 1; i < n; i++) {
		a[i] = min(a[i], a[i - 1] - 1);
		if(a[i] < 0) break;
		else ans += a[i];
	}
	pr(ans, nl);
}