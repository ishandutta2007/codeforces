#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

const int MAX_N = 3e5 + 7;
int arr[MAX_N];
int lft[MAX_N], rght[MAX_N];
int nxt[MAX_N];

void init(int n) {
    for (int i = 1; i <= n; i++) {
        lft[i] = -1;
        rght[i] = n + 1;
    }
}

void solve_all() {
    int n;
    cin >> n;
    init(n);
    set <int> have;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        have.insert(arr[i]);
        rght[arr[i]] = i;
        if (lft[arr[i]] == -1) lft[arr[i]] = i;
    }
    vector <int> all;
    for (int elem : have) all.push_back(elem);
    n = all.size();
    int ans = n;
    for (int i = 0; i < n;) {
        int j = i + 1;
        int cur_r = rght[all[i]];
        while (j < n && lft[all[j]] > cur_r) {
            cur_r = rght[all[j]];
            j++;
        }
        ans = min(ans, n - (j - i));
        i = j;
    }
    cout << ans << "\n";
    /*reverse(arr + 1, arr + n + 1);
    for (int i = 1; i <= n; i++) arr[i] = n + 1 - arr[i];
    init(n);
    cout << min(res, solve(n)) << "\n";
    return;*/
}

int main() {
    //freopen("Desktop/input.txt", "r", stdin);
    ios_base :: sync_with_stdio(0);
    //cin.tie(0);
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) solve_all();
    return 0;
}