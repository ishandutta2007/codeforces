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

#define REP(i, a, b) for(int i = (a); i < (int)(b); i++)
#define REPN(i, a, b) for(int i = (a); i <= (int)(b); i++)
#define FA(it, x) for(__typeof((x).begin()) it = (x).begin(); it != (x).end(); it++)
#define SZ(x) (int)(x).size()
#define BE(x) (x).begin(), (x).end()
#define SORT(x) sort(BE(x))
#define _1 first
#define _2 second

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

#define file "I1"

const double EPS = 1e-9;
const double PI = acos(-1.);
const int INF = 1e9;
const int MAXN = 2e5 + 5;
const ll MOD = 1e9 + 7;

char s[MAXN], s1[MAXN];

void solve(){
	int n, t, i;
	scanf("%d%d%s", &n, &t, &s[0]);
	for(i = 0; s[i] != '.'; i++);
	for(i++; i < n && s[i] <= '4'; i++);
	if (i == n){
		printf("%s\n", s);
		return;
	}
	s[i] = 0;
	i--;
	t--;
	while(s[i] == '4' && t > 0){
		s[i] = 0;
		i--;
		t--;
	}
	if (s[i] == '.'){
		s[i] = 0;
		i--;
		for(; i >= 0 && s[i] == '9'; i--){
			s[i] = '0';
		}
		if (i < 0){
			putchar('1');
		} else {
			s[i]++;
		}
		printf("%s\n", s);
		return;
	}
	s[i]++;
	printf("%s\n", s);
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