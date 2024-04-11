#include <iostream>
#include <utility>
#include <vector>
using namespace std;

void solve()
{
    int n;
    scanf("%d", &n);
    int arr[2000];
    pair<vector<vector<int> >, vector<vector<int> > > amt(vector<vector<int> >(n, vector<int>(26)), vector<vector<int> >(n, vector<int>(26)));
    for (int i = 0; i < n; ++i) {
        scanf("%d", arr + i);
        --arr[i];
        if (i != 0) amt.first[i] = amt.first[i - 1];
        ++amt.first[i][arr[i]];
    }
    amt.second[n - 1][arr[n - 1]] = 1;
    for (int i = n - 2; i >= 0; --i) {
        amt.second[i] = amt.second[i + 1];
        ++amt.second[i][arr[i]];
    }
    int mx = 0;
    for (int i = 0; i < 26; ++i) mx = max(amt.second[0][i], mx);
    int current_max = mx;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (arr[i] == arr[j]) {
                int current = arr[i] == 0 ? 1 : 0;
                for (int k = 0; k < 26; ++k) {
                    if (k != arr[i] && amt.second[i][current] - amt.second[j][current] < amt.second[i][k] - amt.second[j][k]) current = k;
                }
                current_max = max(current_max, amt.second[i][current] - amt.second[j][current] + 2 * min(amt.first[i][arr[i]], amt.second[j][arr[i]]));
            }
        }
    }
    printf("%d\n", current_max);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        solve();
    }
    return 0;
}