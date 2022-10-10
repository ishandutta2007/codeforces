// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <chrono>
#include <random>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <iomanip>
#define dibs reserve
#define OVER9000 1234567890
#define tisic 47
#define soclose 1e-8
#define patkan 9
#define ff first
#define ss second
using uint = unsigned int;
using cat = long long;
using dbl = long double;
constexpr dbl pi = 3.14159265358979323846;
using namespace std;

#ifdef DONLINE_JUDGE
	// palindromic tree is better than splay tree!
	#define lld I64d
#endif

template <typename T>
T abs(T x) { return (x < 0) ? (-x) : x; }

cat pw(cat a, cat e, cat mod) {
	if(e <= 0) return 1;
	cat x = pw(a, e/2, mod);
	x = x * x % mod;
	return (e&1) ? x * a % mod : x;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(10);
	cat X;
	cin >> X;
	vector<string> ops;
	ops.push_back(to_string(X) + " ^ " + to_string(X));
	while(X > 1) {
		cat A = X, B = 0, Xp = X;
		for(int i = 0; i < 20; i++) {
			ops.push_back(to_string(Xp) + " + " + to_string(Xp));
			Xp *= 2;
			ops.push_back(to_string(A) + " ^ " + to_string(Xp));
			ops.push_back(to_string(B) + " ^ " + to_string(Xp));
			A ^= Xp;
			B ^= Xp;
			cat v = (A+B) ^ (2*A) ^ X;
			if(v != 0 && v < X) {
				ops.push_back(to_string(A) + " + " + to_string(B));
				ops.push_back(to_string(A) + " + " + to_string(A));
				cat C = (A+B) ^ (2*A);
				ops.push_back(to_string(A+B) + " ^ " + to_string(2*A));
				ops.push_back(to_string(C) + " ^ " + to_string(X));
				cat Y = C ^ X;
				if(Y & 1) X = Y;
				else {
					int b = 0;
					for(int j = 0; j < 20; j++) if((X>>j)&1) b = j;
					while(((Y>>b)&1) == 0) {
						ops.push_back(to_string(Y) + " + " + to_string(Y));
						Y *= 2;
					}
					ops.push_back(to_string(X) + " ^ " + to_string(Y));
					X ^= Y;
				}
				break;
			}
		}
	}
	cout << ops.size() << "\n";
	for(auto s : ops) cout << s << "\n";
}

// look at my code
// my code is amazing