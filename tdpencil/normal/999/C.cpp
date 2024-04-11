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
#define ar array
// vector<int> toRemove[200001];
void solve() {
	int N, K; cin >> N >> K;
	string S;
	cin >> S;

	vector<int> freq(26);
	for(int i = 0; i < N; i++) {
		freq[S[i]-'a']++;
	}
	int l = 0;
	string ans;
	for(int i = 0; i < K; i++) {
		while(l < 26 && freq[l] == 0) l++;
		if(l >= 26) break;
		freq[l]--; 
	}

	vector<int> cnt(26);
	for(int i = 0; i < N; i++) {
		cnt[S[i] - 'a']++;
	}

	for(int i = 0; i < N; i++) {
		if(cnt[S[i]-'a'] == freq[S[i]-'a']) {
			ans += S[i];
		} else {
			cnt[S[i]-'a']--;
		}
	}

	cout << ans << "\n";




}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int T = 1; //cin >> T;
   
    while(T--)
        solve();
}