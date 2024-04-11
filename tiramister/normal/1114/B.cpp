#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    int N, M, K;
    cin >> N >> M >> K;

    priority_queue<pair<ll, int>> que;
    for (int i = 1; i <= N; ++i) {
        ll a;
        cin >> a;
        que.push(make_pair(a, i));
    }

    ll sum = 0;
    vector<int> ans;
    for (int i = 0; i < M * K; ++i) {
        sum += que.top().first;
        ans.push_back(que.top().second);
        que.pop();
    }

    cout << sum << endl;

    sort(ans.begin(), ans.end());
    for (int i = 1; i < K; ++i) {
        cout << ans[i * M - 1] << " ";
    }
    cout << endl;
    return 0;
}