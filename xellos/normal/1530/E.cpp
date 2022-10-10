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

cat mod = 998244353;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(12);
	int T;
	cin >> T;
	while(T--) {
		string S;
		cin >> S;
		vector<int> cnt(26, 0);
		for(int i = 0; i < (int)S.length(); i++) cnt[S[i]-'a']++;
		int cnt_nz = 0;
		for(int i = 0; i < 26; i++) if(cnt[i]) cnt_nz++;
		if(cnt_nz == 1) {
			cout << S << '\n';
			continue;
		}
		int cnt_1 = 0;
		for(int i = 0; i < 26; i++) if(cnt[i] == 1) cnt_1++;
		if(cnt_1) {
			for(int i = 0; i < 26; i++) if(cnt[i] == 1) {
				cout << char('a'+i);
				cnt[i]--;
				break;
			}
			for(int i = 0; i < 26; i++) while(cnt[i]) {
				cout << char('a'+i);
				cnt[i]--;
			}
			cout << '\n';
			continue;
		}
		// f = 1, first 2 letters never repeat
		// aa: only if aababaca..zazz
		string try_ans;
		int id_f = 0;
		while(!cnt[id_f]) id_f++;
		try_ans += char('a'+id_f);
		try_ans += char('a'+id_f);
		int rm_f = cnt[id_f]-2;
		for(int i = id_f+1; i < 26; i++) for(int j = 0; j < cnt[i]; j++) {
			try_ans += char('a'+i);
			if(rm_f) {
				try_ans += char('a'+id_f);
				rm_f--;
			}
		}
		if(!rm_f) {
			cout << try_ans << '\n';
			continue;
		}
		// ab: abbbcc..zzaaa always possible
		// 3 letters: abaaacbbcc..zz
		if(cnt_nz > 2) {
			string ans;
			int id_s = id_f+1;
			while(!cnt[id_s]) id_s++;
			int id_u = id_s+1;
			while(!cnt[id_u]) id_u++;
			ans += char('a'+id_f);
			ans += char('a'+id_s);
			for(int j = 1; j < cnt[id_f]; j++) ans += char('a'+id_f);
			ans += char('a'+id_u);
			for(int j = 1; j < cnt[id_s]; j++) ans += char('a'+id_s);
			for(int j = 1; j < cnt[id_u]; j++) ans += char('a'+id_u);
			for(int i = id_u+1; i < 26; i++) for(int j = 0; j < cnt[i]; j++)
				ans += char('a'+i);
			cout << ans << '\n';
			continue;
		}
		// 2 letters: abbbaaa
		string ans;
		ans += char('a'+id_f);
		for(int i = id_f+1; i < 26; i++) for(int j = 0; j < cnt[i]; j++)
			ans += char('a'+i);
		for(int j = 1; j < cnt[id_f]; j++) ans += char('a'+id_f);
		cout << ans << '\n';
	}
}

// look at my code
// my code is amazing