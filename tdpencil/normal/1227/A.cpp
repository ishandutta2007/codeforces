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
    int n; scanf("%d", &n);
    vector<pair<int, int>> p(n);
    trav(i, p) {
        scanf("%d%d", &i.first, &i.second);
    }
    int l = 0, r = 0;

    priority_queue<int> pq1;
    priority_queue<int, vector<int>, greater<int>> pq2;
    trav(i, p) {
        pq1.push(i.first);
        pq2.push(i.second);
    }

    printf("%d\n", max(0, pq1.top() - pq2.top()));
}
int main() {

    int t = 1, i = 1;
    scanf("%d", &t);

    while(t--) {
        // printf("Case #%d: ", i)
        solve();
        i++;
    }
}