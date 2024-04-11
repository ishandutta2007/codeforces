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
typedef long long ll; 
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
 
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
 
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)


int A[105];
int D[105];
int N;


void rec(int l, int r, int curDepth=0) {
	if(l > r) return;
	int mx = *max_element(A+l, A+r+1);

	int p = find(A, A+N, mx) - A;

	D[p]=curDepth;


	rec(l, p-1, curDepth+1);
	rec(p+1, r, curDepth+1);




}
void solve() {
	cin >> N;

	for(int i = 0; i < N; i++)
		cin >> A[i];

	rec(0, N-1);


	for(int i = 0; i < N; i++)
		cout << D[i] << " ";

	cout << "\n";

	memset(D, 0, sizeof(D));
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
   
    while(T--)
        solve();
}