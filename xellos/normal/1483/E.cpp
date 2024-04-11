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

cat next_guess(cat B, cat Ml, cat Mr, int Q) {
	int binsearch_Q = 0;
	while(Mr-Ml+1 > (1LL<<binsearch_Q)) binsearch_Q++;
	cat binsearch_guess = (Ml+Mr+1)/2;
	if(B + Ml * (Q - binsearch_Q) >= Mr * binsearch_Q) return binsearch_guess;
	cat min_guess = max(1LL,(Mr-Ml)*3/10)+Ml;
	return 1.*B/(Mr*binsearch_Q-Ml*(Q-binsearch_Q)) * (binsearch_guess-min_guess) + min_guess;
}

bool query(cat & B, cat & Ml, cat & Mr, int & Q, int MAXQ, cat guess) {
	while(B < guess && Q < MAXQ) {
		cout << "? " << Ml << endl;
		B += Ml;
		Q++;
		string resp;
		cin >> resp;
	}
	if(Q >= MAXQ) {
		cout << "FAIL, bank: " << B << ", M: [" << Ml << "," << Mr << "], trying " << guess << endl;
		exit(0);
	}
	cout << "? " << guess << endl;
	Q++;
	string resp;
	cin >> resp;
	if(resp[0] == 'L') {
		B += guess;
		Ml = guess;
		return true;
	}
	else {
		B -= guess;
		Mr = guess-1;
		return false;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(12);
	int T;
	cin >> T;
	while(T--) {
		int Q = 0, MAXQ = 105;
		cat Ml = 1, Mr = 0, B = 1;
		cat MAX_M = 100000000000000LL;
		while(Ml <= MAX_M && query(B, Ml, Mr, Q, MAXQ, Ml)) Ml *= 2;
		if(Ml > MAX_M) Mr = Ml-1;
		Ml = (Mr+1)/2;
		Mr = min(Mr, MAX_M);
		while(Ml != Mr) {
			cat guess = next_guess(B, Ml, Mr, MAXQ-Q);
			query(B, Ml, Mr, Q, MAXQ, guess);
		}
		cout << "! " << Ml << endl;
	}
}

// look at my code
// my code is amazing