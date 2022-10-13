#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define f first
#define s second
typedef long long ll;
typedef long double ld;
using namespace std;
using namespace __gnu_pbds;
const int MX = 1e5+5;

ll dp[MX];
ll a[MX], b[MX], p[MX];
deque<int> q;
double slope(int j, int k) {
    return (double) (dp[j]-dp[k]) / (b[k]-b[j]);
}
int main() {
    int n; cin >> n;
    for(int i=1;i<=n;i++)
        cin >> a[i];
    for(int i=1;i<=n;i++)
        cin >> b[i];
    dp[1] = 0;
    q.push_back(1);
    for(int i=2;i<=n;i++) {
        while(q.size() > 1 && slope(q[1], q[0]) <= a[i])
            q.pop_front();
        int j = q.front();
        dp[i] = dp[j]+b[j]*a[i];
        while(q.size() > 1 && slope(q[q.size()-1], q[q.size()-2]) >= slope(i, q[q.size()-1]))
            q.pop_back();
        q.push_back(i);
    }
    cout << dp[n];
}