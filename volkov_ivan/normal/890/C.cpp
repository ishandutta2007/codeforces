#include <iostream>
#include <set>

using namespace std;

int main() {
    int n, ans = 1, a;
    scanf("%d/n", &n);
    bool visited[n + 1];
    for (int i = 0; i <= n; i++) {
        visited[i] = 0;
    }
    set <int> now;
    now.insert(0);
    for (int i = 0; i < n; i++) {
        scanf("%d ", &a);
        if (now.find(a) == now.end()) {
            ans++;
            now.insert(i + 1);
        } else {
            now.erase(a);
            now.insert(i + 1);
        }
    }
    cout << ans << endl;
    return 0;
}