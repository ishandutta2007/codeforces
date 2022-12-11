#include <iostream>
#include <map>

using namespace std;

int main() {
    int n, m;
    cin >> n;
    int a, x;
    map <int, int> dict;
    for (int i = 0; i < n; i++) {
        scanf("%d %d\n", &a, &x);
        dict[a] = max(dict[a], x);
    }
    cin >> m;
    int b, y;
    for (int i = 0; i < m; i++) {
        scanf("%d %d\n", &b, &y);
        dict[b] = max(dict[b], y);
    }
    long long ans = 0;
    for (pair <int, int> elem : dict) {
        ans += elem.second;
        //cout << ans << ' ' << elem.second << endl;
    }
    cout << ans << endl;
    return 0;
}