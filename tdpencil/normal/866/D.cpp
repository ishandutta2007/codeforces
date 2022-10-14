#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9+7;
#define pb push_back
#define ll long long
const int MAXN = 2e3 + 1;
const int M = 1e9+7;


void go()
{
    int N; cin >> N;
    priority_queue<int, vector<int>, greater<int>> pq;
    ll ans = 0;
    for(int i = 0, j; i < N; i++) {
        cin >> j;
        pq.push(j);
        pq.push(j);
        ans -= j;
        pq.pop();
    }
    // maintain differences in dp

    for(int i = 0; i < N; i++) {
        ans += pq.top();
        pq.pop();
    }

    cout << ans << "\n";
}



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; // cin >> t;
    while(t--)
        go();
}