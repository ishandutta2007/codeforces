#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
const int MX = 1e6+5;
typedef long long ll;
struct rect {
    ll x, y, a;
    bool operator<(rect o) { return x < o.x; }
};
ll dp[MX];
rect a[MX];
double slope(int i, int j) {
    return (double)(dp[i]-dp[j]) / (a[i].x-a[j].x); //if greater than y[i] then i is a better choice than j (i>j)
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    for(int i=1;i<=n;i++) {
        cin >> a[i].x >> a[i].y >> a[i].a;
    }
    sort(a+1, a+n+1);
    deque<ll> q;
    q.push_back(0);
    for(int i=1;i<=n;i++) {
        while(q.size()>1 && slope(q[0], q[1])>=a[i].y) {
            q.pop_front();
        }
        int j = q.front();
        dp[i] = max(dp[i-1], -a[i].a+a[i].x*a[i].y+dp[j]-a[j].x*a[i].y);
        while(q.size()>1 && slope(q[q.size()-2], q[q.size()-1]) <= slope(q[q.size()-1], i)) q.pop_back();
        q.push_back(i);
    }
    cout << dp[n];
}