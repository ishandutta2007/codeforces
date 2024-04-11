#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define all(x) x.begin(), x.end()
#define trav(i, x) for(auto &i : x)
#define lb lower_bound
#define ub upper_bound
#define pb push_back
#define eb emplace_back
#define FOR(i, N) for(int i = 0; i < (N); i++)
const ll mod = 1e9 + 7;


void solve() {
    int n, k; scanf("%d%d", &n, &k);

    vector<int> lectures(n);
    vector<int> freq(n);
    trav(lecture, lectures) {
        scanf("%d", &lecture);
    }
    trav(f, freq) {
        scanf("%d", &f);
    }

    vector<int> P(n);
    vector<int> Z(n);
    for(int i = 0; i < n; i++) {
        P[i] = lectures[i];
    }
    for(int i = 0; i < n; i++) {
        if(i > 0) Z[i] = Z[i-1];
        if(freq[i]==0) {
            if(i > 0) Z[i] = Z[i-1] + lectures[i];
            else Z[i] = lectures[i];
        }
    }
    partial_sum(all(P), P.begin());
    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(freq[i]) {
            ans += lectures[i];
        }
    }
    int mx = INT_MIN;
    for(int i = 0; i < n - k + 1; i++) {
        int res = ans + (Z[i+k-1] - (i == 0 ? 0 : Z[i-1]));
        mx = max(res, mx);
    }

    printf("%d", mx);


}
int main() {

	int t = 1, i = 1;
	//scanf("%d", &t);
	while(t--) {
		// printf("Case #%d: ", i)
		solve();
		i++;
	}
}