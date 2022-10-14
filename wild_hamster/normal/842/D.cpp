#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <list>
#include <cstdlib>
#include <iomanip>
#include <numeric>
#include <utility>
#include <set>
#include <map>
#include <iterator>
#include <cassert>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <cmath>
#include <cstring>
#include <sstream>
#include <stack>
#include <random>

using namespace std;

#define vi vector<int> 
#define vvi vector<vi>
#define pi pair<int,int>
#define ll long long
#define pll pair<ll, ll>
#define vll vector<ll>
#define io ios::sync_with_stdio(false)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define all(c) (c).begin(), (c).end()
#define sz(a) int((a).size()) 
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define loop(i,b) for (int i = 0; i < b; ++i)
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end()) 
#define INF numeric_limits<int>::max()
#define LLINF numeric_limits<ll>::max()
#define max3(a,b,c) max(max(a,b),c)
#define min3(a,b,c) min(min(a,b),c)
#define F first
#define S second
#define MOD 1000000007
#define cflout(x) cout << fixed << setprecision(8) << x << endl
#define setzero(x) memset(x, 0, sizeof(x))

#ifndef M_PI
    #define M_PI 3.14159265358979323846
#endif

random_device _random_device;
default_random_engine _generator(_random_device());
uniform_int_distribution<long long unsigned> _distribution(0, 0xFFFFFFFFFFFFFFFF);

inline long long unsigned get_random_number() {
    return _distribution(_generator);
}

template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

inline ll nxt() {
	ll x;
	cin >> x;
	return x;
}

namespace aux {	
vector<string> split(const string& s, char c) {
	vector<string> v;
	stringstream ss(s);
	string x;
	while (getline(ss, x, c)) {
		v.emplace_back(x);
    }
    return v;
}
}

struct node {
	int lt, rt;

	node() {
		lt = rt = -1;
	}
};

const int M = 21;
const int N = (1<<20);

int used[600500];

node trie[N*M];
int n, m;
int len = 1;

void insert(int idx, int num, int pos) {
	if (pos < 0) return;
	int bit = ((num >> pos) & 1);

	if (bit == 0) {
		if (trie[idx].lt == -1) trie[idx].lt = len++;
		insert(trie[idx].lt, num, pos-1);
	} else {
		if (trie[idx].rt == -1) trie[idx].rt = len++;
		insert(trie[idx].rt, num, pos-1);
	}
}

int query(int idx, int num, int pos) {
	if (pos < 0 || idx == -1) return 0;
	int bit = (num & (1 << pos));

	if (bit == 0) {
		if (trie[idx].lt == -1) return (1 << pos) | query(trie[idx].rt, num, pos-1);
		else return query(trie[idx].lt, num, pos-1);
	} else {
		if (trie[idx].rt == -1) return (1 << pos) | query(trie[idx].lt, num, pos-1);
		else return query(trie[idx].rt, num, pos-1);
	}
}


int main() {
	io;
	n = nxt(), m = nxt();
	loop(i, n) {
		int x = nxt();
		used[x] = 1;
	}

	loop(i, 600500) {
		if (!used[i]) insert(0, i, M-1);
	}

	int q = 0;
	loop(i, m) {
		int x = nxt();
		q ^= x;
		cout << query(0, q, M-1) << endl;
	}
	
	return 0;
}