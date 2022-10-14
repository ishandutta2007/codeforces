#include <algorithm>
#include <unordered_set>
#include <array>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstring>
#include <unordered_map>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>
using namespace std;
#define sz(s) (int(s.size()))
#define all(x) x.begin(),x.end()
#define sum(x) accumulate(x.begin(), x.end(), 0LL)
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
 
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
void run_case() {
    int n;
    cin >> n;

    vector<int64_t> A(n);
    for(auto &num: A)
        cin >> num;

    unordered_map<int64_t, int, custom_hash> freq;

    for(auto &num: A)
        freq[num]++;

    unordered_set<int> s;
    for(auto it = freq.begin(); it != freq.end(); it++) {
        int v = it->second;
        while(s.count(v) && v > 0) {
            v--;
        }

        s.insert(v);
    }

    int64_t sm = 0;

    for(auto &a: s) sm+= a;

    cout << sm << '\n';

    
}

int main() {
	ios_base::sync_with_stdio(false);
	ios::sync_with_stdio(false);

	cin.tie(0);
	cout.tie(0);

	int t = 1;
	cin >> t;
	while(t--)
		run_case();
}