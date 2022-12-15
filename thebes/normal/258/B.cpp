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

const int MOD = 1e9 + 7;

int madd(int a, int b) {
	a += b; if(a >= MOD) a -= MOD;
	return a;
}
int mmul(int a, int b) {
	return 1ll * a * b % MOD;
}

string s;
//number of values with rem lucky digits, <= s
int ct(int rem, int d = 0, bool we = false) {
	if(d >= sz(s)) {
		if(rem == 0) return 1;
		else return 0;
	}
	int ret = 0;
	if(we) {
		ret += 8 * ct(rem, d + 1, true); //not lucky
		if(rem) ret += 2 * ct(rem - 1, d + 1, true); //lucky
	} else {
		int a = 0, b = 0;
		for(int i = 0; i <= 9; i++) {
			if(i >= s[d] - '0') break;
			if(i == 4 || i == 7) a++; else b++;
		}
		if(rem && a) ret += a * ct(rem - 1, d + 1, true);
		if(b) ret += b * ct(rem, d + 1, true);
		if(s[d] == '4' || s[d] == '7') {if(rem) ret += ct(rem - 1, d + 1, false);}
		else ret += ct(rem, d + 1, false);
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	sc(s);
	vector<int> a(10);
	for(int i = 0; i < 10; i++) a[i] = ct(i); a[0]--; //exclude 0
	int ans = 0;
	for(int i = 0; i < 10; i++) {
		for(int j = 0; j < 10; j++) {
			if(j >= i) break;
			for(int k = 0; k < 10; k++) {
				if(j + k >= i) break;
				for(int l = 0; l < 10; l++) {
					if(j + k + l >= i) break;
					for(int m = 0; m < 10; m++) {
						if(j + k + l + m >= i) break;
						for(int n = 0; n < 10; n++) {
							if(j + k + l + m + n >= i) break;
							for(int o = 0; o < 10; o++) {
								if(j + k + l + m + n + o >= i) break;
								//assert i > j + k + l + m + n + o
								int cur = 1;
								cur = mmul(cur, a[i]); a[i]--;
								cur = mmul(cur, a[j]); a[j]--;
								cur = mmul(cur, a[k]); a[k]--;
								cur = mmul(cur, a[l]); a[l]--;
								cur = mmul(cur, a[m]); a[m]--;
								cur = mmul(cur, a[n]); a[n]--;
								cur = mmul(cur, a[o]); a[o]--;
								bool ok = true;
								for(int p = 0; p < 10; p++) if(a[p] < 0) ok = false;
								a[i]++; a[j]++; a[k]++; a[l]++; 
								a[m]++; a[n]++; a[o]++;
								if(ok) ans = madd(cur, ans);
							}
						}
					}
				}
			}
		}
	}
	pr(ans, nl);
}