#include <bits/stdc++.h>
using namespace std;

template <typename T> using MinHeap = priority_queue<T, vector<T>, greater<T>>;
template <typename T> using MaxHeap = priority_queue<T, vector<T>, less<T>>;

const int maxn = 2e5 + 10;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    MinHeap<long long> pq;
    while (n--) {
        int a; cin >> a;
        pq.push(a);
    }
    long long ans = 0;
    if (pq.size() % 2 == 0) {
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();
        pq.push(a + b); ans += a + b;
    }
    while (pq.size() > 1) {
        long long t = 0;
        for (int i = 0; i < 3; ++i) t += pq.top(), pq.pop();
        ans += t;
        pq.push(t);
    }
    cout << ans << endl;
    return 0;
}