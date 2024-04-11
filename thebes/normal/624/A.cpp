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
	int d, l, v1, v2; sc(d, l, v1, v2);
	int v = v1 + v2, s = max(0, l - d);
	pr(fixed, setprecision(10), s / (1. * v), nl);
}