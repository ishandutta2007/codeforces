#include <algorithm>
#include <array>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstring>
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



void run_case() {
    int a, b;
    cin >> a >> b;

    if(a == b) {
        cout << "0\n";
        return;
    }

    else if(a < b) {
        if(b % 2 == 0) {
            if(a % 2 == 0) {
                cout << "2\n";
                return;
            } else {
                cout << "1\n";
                return;
            }
        } else {
            if(a % 2 == 0) {
                cout << "1\n";
                return;
            } else {
                cout << "2\n";
                return;
            }
        }
    } else {
        if(b % 2 == 0) {
            if(a % 2 == 0) {
                cout << "1\n";
                return;
            } else {
                cout << "2\n"; 
                return;
            }
        } else {
            if(a % 2 == 0) {
                cout << "2\n";
                return;
            } else {
                cout << "1\n";
                return;
            }
        }
    }
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