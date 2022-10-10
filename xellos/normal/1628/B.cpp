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
#define OVER9000 1234567890123456789LL
#define tisic 47
#define soclose 1e-8
#define patkan 9
#define ff first
#define ss second
using uint = unsigned int;
using cat = long long;
using dbl = double;
constexpr dbl pi = 3.14159265358979323846;
using namespace std;

#ifdef DONLINE_JUDGE
	// palindromic tree is better than splay tree!
	#define lld I64d
#endif

template <typename T>
T abs(T x) { return (x < 0) ? (-x) : x; }

cat gcd(cat a, cat b) {
	if(a > b) swap(a, b);
	while(a) {
		cat c = b%a;
		b = a;
		a = c;
	}
	return b;
}

cat pw(cat a, cat e, cat mod) {
	if(e <= 0) return 1;
	cat x = pw(a, e/2, mod);
	x = x * x % mod;
	return (e&1) ? x * a % mod : x;
}

template <typename T>
class fin {
	vector<T> node_val;

	int lastone(int x) { return x & (x ^ (x-1)); }

public:
	fin(int N, T init_val) {
		node_val.resize(N+10, init_val);
	}

	void put(int pos, T val) {
		for(int i = pos+1; i < (int)node_val.size(); i += lastone(i))
			node_val[i] += val;
	}

	T get(int pos) {
		T ret = 0;
		for(int i = pos+1; i > 0; i -= lastone(i))
			ret += node_val[i];
		return ret;
	}
};

constexpr cat MOD = 1000000007;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(12);
	int T;
	cin >> T;
	while(T--) {
		int N;
		cin >> N;
		int cnt2[26][26];
		int cnt3[26][26][26];
		memset(cnt2, 0, sizeof(cnt2));
		memset(cnt3, 0, sizeof(cnt3));
		bool ans = false;
		for(int i = 0; i < N; i++) {
			string s;
			cin >> s;
			if((int)s.length() == 1) ans = true;
			else if((int)s.length() == 2) {
				int c = cnt2[s[0]-'a'][s[1]-'a']++;
				if(!c) for(int j = 0; j < 26; j++) ans |= cnt3[s[1]-'a'][s[0]-'a'][j];
			}
			else {
				cnt3[s[0]-'a'][s[1]-'a'][s[2]-'a']++;
				ans |= cnt2[s[2]-'a'][s[1]-'a'];
			}
		}
		for(int i = 0; i < 26; i++) for(int j = 0; j < 26; j++)
			ans |= (cnt2[i][j] && cnt2[j][i]);
		for(int i = 0; i < 26; i++) for(int j = 0; j < 26; j++) for(int k = 0; k < 26; k++)
			ans |= (cnt3[i][j][k] && cnt3[k][j][i]);
		if(ans) cout << "YES\n";
		else cout << "NO\n";
	}
}

// look at my code
// my code is amazing