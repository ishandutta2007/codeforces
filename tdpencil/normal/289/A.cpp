#include <bits/stdc++.h>

using namespace std;
typedef long long ll; 
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
 
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
 
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#define ar array

ar<ll, 2> A[200000];
void solve() {
	int N, K;
	cin >> N >> K;
	ll ans = 0;
	for(int i = 0; i < N; i++)
		cin >> A[i][0] >> A[i][1];


	sort(A, A + N);
	for(int i = 0; i < N; i++)
		ans += A[i][1]-A[i][0]+1;

	ans %= K;
	ll res = (K - ans);
	cout << (ans == 0 ? 0 : res) << "\n";


}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int T = 1; //cin >> T;
   
    while(T--)
        solve();
}