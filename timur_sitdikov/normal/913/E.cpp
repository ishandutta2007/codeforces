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

#define x1 gray_cat_x1
#define y1 gray_cat_y1

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

#define file "I1"

const double EPS = 1e-9;
const double PI = acos(-1.);
const int INF = 1e9;
const ll MOD = 1e9 + 7;

const int MAXN = 1e5 + 5;

map<pii, string> expr;
set<pii> masks[200];
map<int, string> ans;

void update(int op, int mask1, int type1, int mask2, int type2){
	string expr1 = expr[mp(mask1, type1)];
	int len1 = expr1.length();
	int mask3, len3;
	string expr3, expr4;
	if (op == 0){
		op = 1;
		mask3 = mask1;
		expr3 = "(" + expr1 + ")";
	} else if (op == 1){
		mask3 = (255 ^ mask1);
		expr3 = (type1 <= 1 ? "!" + expr1: "!(" + expr1 + ")");				
	} else {
		string expr2 = expr[mp(mask2, type2)];
		int len2 = expr2.length();
		if (op == 2){
			mask3 = (mask1 & mask2);
			string s1 = (type1 == 3 ? "(" + expr1 + ")" : expr1);
			string s2 = (type2 == 3 ? "(" + expr2 + ")" : expr2);			
			expr3 = s1 + "&" + s2;
			expr4 = s2 + "&" + s1;
			expr3 = min(expr3, expr4);
		} else if (op ==3){
			mask3 = (mask1 | mask2);
			expr3 = expr1 + "|" + expr2;
			expr4 = expr2 + "|" + expr1;
			expr3 = min(expr3, expr4);
		}
	}
	len3 = expr3.length();
	
	
	
	if (expr.find(mp(mask3, op)) == expr.end() || expr[mp(mask3, op)].length() > len3 || expr[mp(mask3, op)].length() == len3 && expr[mp(mask3, op)] > expr3){
		if (expr.find(mp(mask3, op)) != expr.end()){
			masks[expr[mp(mask3, op)].length()].erase(mp(mask3, op));
		}
		expr[mp(mask3, op)] = expr3;
		masks[len3].insert(mp(mask3, op));
	}
}

void solve(){
	//expr[mp(0, 0)] = expr[mp(255, 0)] = "";
	expr[mp(128 + 64 + 32 + 16, 1)] = "x";
	expr[mp(128 + 64 + 8 + 4, 1)] = "y";
	expr[mp(128 + 32 + 8 + 2, 1)] = "z";
	FA(it, expr){
		masks[it->_2.length()].insert(it->_1);
	}
	int lim = 30;
	for(int i = 1; i <= lim; i++){
		FA(it, masks[i]){
			int mask1 = it->_1;
			int type1 = it->_2;
			// !
			update(1, mask1, type1, 0, 0);
			update(0, mask1, type1, 0, 0);
			// &, |
			REPN(j, 1, i){
				FA(it1, masks[j]){
					int mask2 = it1->_1;
					int type2 = it1->_2;
					update(2, mask1, type1, mask2, type2);
					update(3, mask1, type1, mask2, type2);
				}
			}
		}
	}
	
	FA(it, expr){
		int mask = it->_1._1;
		if (ans.find(mask) == ans.end() || ans[mask].length() > it->_2.length() || ans[mask].length() == it->_2.length() && ans[mask] > it->_2){
			ans[mask] = it->_2;
		}
	}
	//ans[0] = "!x&x";
	//ans[255] = "!x|x";
	/*int sum = 0;
	FA(it, ans){
		cout << it->_1 << " " << it->_2 << endl;
		sum += it->_2.length();
	}
	cout << sum << endl;
	return;*/
	int n;
	scanf("%d", &n);
	string s;
	REP(i, 0, n){
		cin >> s;
		int mask = 0;
		REP(j, 0, 8){
			if (s[j] == '1'){
				mask |= (1 << j);
			}
		}
		string s = ans[mask];
		for(int j = 0; j < (int)s.length(); j++){
			putchar(s[j]);
		}
		putchar('\n');
		//cout << ans[mask] << endl;
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