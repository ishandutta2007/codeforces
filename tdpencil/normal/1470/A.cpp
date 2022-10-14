#include <bits/stdc++.h>

using namespace std;
typedef long long ll; 
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
 
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
 
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

int A[300005];
int B[300005];
bool C[300005];
void solve() {
	int N, M;
	cin >> N >> M;
	for(int i = 0; i < N; i++)
		cin >> A[i];
	sort(A, A + N, greater<int>());
	for(int i = 0; i < M; i++)
		cin >> B[i];

	

	ll cost = 0;
	// cout << "COSTS ADDED: \n";
	for(int i = 0; i < N; i++) {
		int l = 0, r = A[i] - 1;

		ll choice1 = B[r];
		ll ans = 19999LL*9999999LL;
		while(l <= r) {
			int mid = (l + r) / 2;
			if(C[mid]) {
				l = mid + 1;

			} else {
				ans=mid;
				r = mid - 1;
			}
		}
		if(ans > (ll)1e9) {
			cost += choice1;
			// cout << choice1 << " ";
		} else {
			ll choice2 = B[ans];

			if(choice2 < choice1) {
				cost += choice2;
				// cout << choice2 << " ";
				C[ans]=1;
			} else {
				cost += choice1;
				// cout << choice1 << " ";
			}
		}
	}
	// cout << "\n";

	cout << cost << "\n";

	memset(C, 0, sizeof(C));





}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
   
    while(T--)
        solve();
}