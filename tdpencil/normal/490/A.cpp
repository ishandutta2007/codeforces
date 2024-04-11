#include <algorithm>
#include <stack>
#include <istream>
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
#include <ostream>

typedef long long ll;

using namespace std;
 
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
 
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
 
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

vector<int> F[3];

void run_case()
{
	int N; cin >> N;
	vector<int> A(N);
	for(auto& a: A)
		cin >> a;

	for(int i = 0; i < N; i++)
		F[A[i]%3].push_back(i+1);

	int ans = min(F[0].size(), min(F[1].size(), F[2].size()));
	cout << ans << '\n';

	for(int i = 0; i < ans; i++) {
		cout << F[0][i] << " " << F[1][i] << " " << F[2][i] << "\n";
	}

}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    // TENCIL ORZ?
    int T=1;
    // cin >> T;
    while(T--)
        run_case();
}