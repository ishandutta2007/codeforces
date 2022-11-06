#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct Task {
    int t, k, d;
    vector<int> id;
    bool operator>(const Task& rhs) const {
        return t + d > rhs.t + rhs.d;
    }
};

priority_queue<int, vector<int>, greater<int>> pq;
priority_queue<Task, vector<Task>, greater<Task>> T;
int n, q, t, k, d;

int main() {
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) pq.push(i);
    while (q--) {
        cin >> t >> k >> d;
        while (T.size() && T.top().t + T.top().d <= t) {
            Task tmp = T.top(); T.pop();
            for (int i : tmp.id) pq.push(i);
        }
        if (pq.size() < k) { cout << "-1\n"; continue; }
        int sum = 0;
        Task tsk;
        tsk.t = t; tsk.d = d; tsk.k = k;
        for (int i = 0; i < k; ++i) {
            sum += pq.top();
            tsk.id.push_back(pq.top());
            pq.pop();
        }
        T.push(tsk);
        cout << sum << '\n';
    }
    return 0;
}