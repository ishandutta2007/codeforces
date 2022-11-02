#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    int a[N + 1][2];
    for (int i = 1; i <= N; ++i) {
        cin >> a[i][0] >> a[i][1];
    }

    bool used[N + 1];
    fill(used + 1, used + N + 1, false);

    vector<int> ans = {1};
    int v = 1;
    while (ans.size() < N) {
        used[v] = true;

        int next = a[v][0];
        bool judge = false;

        for (int i = 0; i < 2; ++i) {
            if (a[next][i] == a[v][1]) {
                judge = true;
                break;
            }
        }

        if (!judge || used[next]) next = a[v][1];

        ans.push_back(next);
        v = next;
    }

    for (int c : ans) {
        cout << c << " ";
    }
    cout << endl;
    return 0;
}