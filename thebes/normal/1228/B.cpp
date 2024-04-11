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

const int MOD = 1000000007;

int mmul(int a, int b) {
	return 1ll * a * b % MOD;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int h, w; sc(h, w);
	vector<int> r(h), c(w);
	for(int i = 0; i < h; i++) sc(r[i]);
	for(int i = 0; i < w; i++) sc(c[i]);
	//0 white 1 black 2 grey
	vector<vector<int>> a(h, vector<int>(w, 2));
	int ans = 1;
	//make rows
	for(int i = 0; i < h && ans != 0; i++) {
		for(int j = 0; j < r[i] && ans != 0; j++) {
			if(a[i][j] == 0) ans = 0;
			else a[i][j] = 1;
		}
		if(r[i] < w) {
			if(a[i][r[i]] == 1) ans = 0;
			else a[i][r[i]] = 0;
		}
	}
	//make cols
	for(int i = 0; i < w && ans != 0; i++) {
		for(int j = 0; j < c[i] && ans != 0; j++) {
			if(a[j][i] == 0) ans = 0;
			else a[j][i] = 1;
		}
		if(c[i] < h) {
			if(a[c[i]][i] == 1) ans = 0;
			else a[c[i]][i] = 0;
		}
	}
	if(ans != -1) {
		for(int i = 0; i < h; i++) {
			for(int j = 0; j < w; j++) {
				if(a[i][j] == 2) ans = mmul(ans, 2);
			}
		}
	}
	pr(ans, nl);
}