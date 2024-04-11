#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> path[100010];
priority_queue<int, vector<int>, greater<int>> que;

int dfs(int v) {
    int ret = (path[v].empty());
    for (int sv : path[v]) {
        ret += dfs(sv);
    }

    que.push(ret);
    return ret;
}

int main() {
    int N;
    cin >> N;

    for (int i = 1; i < N; ++i) {
        int p;
        cin >> p;
        path[p - 1].push_back(i);
    }

    dfs(0);

    while (!que.empty()) {
        cout << que.top() << " ";
        que.pop();
    }
    cout << endl;
    return 0;
}