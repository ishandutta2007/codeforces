#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef complex<double> point;
#define xx real()
#define yy imag()

#define REP(i, a, b) for((i) = (a); (i) < (int)(b); (i)++)
#define FA(it, x) for(__typeof((x).begin()) it = (x).begin(); it != (x).end(); it++)
#define SZ(x) (int)(x).size()
#define BE(x) (x).begin(), (x).end()
#define SORT(x) sort(BE(x))

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

#define file "cycle"

const double EPS = 1e-9;
const double PI = acos(-1.);
const ll INF = 1e18;
const int MAXN = 2e5 + 5;
const ll MOD = 1e9 + 7;

map<string, set<string> > tt1;
map<set<string>, set<string> > tt2;

char c[100];

void solve(){
	int n, i, j, k;
	scanf("%d", &n);
	REP(i, 0, n){
		scanf("%s", &c[0]);
		string s1 = "", s2 = "";
		for(j = 7; c[j] && c[j] != '/'; j++){
			s1 += c[j];
		}
		for(; c[j]; j++){
			s2 += c[j];
		}
		tt1[s1].insert(s2);
	}
	FA(it, tt1){
		tt2[it->second].insert(it->first);
	}
	int ans = 0;
	FA(it, tt2){
		if (SZ(it->second) > 1){
			ans++;
		}
	}
	printf("%d\n", ans);
	FA(it, tt2){
		if (SZ(it->second) > 1){
			FA(it1, it->second){
				printf("http://");
				REP(i, 0, it1->length()){
					putchar((*it1)[i]);
				}
				putchar(' ');
			}
			putchar('\n');
		}
	}
}	

int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	//freopen(file".in", "r", stdin); freopen(file".out", "w", stdout);
	int t = 1;
	//cin >> t;
	while(t--){
		solve();	
	}
}