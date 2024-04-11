#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int cnt[1000010];

int main() {
    int N;
    cin >> N;

    int a[N];
    ll sum = 0;
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
        ++cnt[a[i]];
        sum += a[i];
    }

    vector<int> ans;
    for (int i = 0; i < N; ++i) {
        --cnt[a[i]];
        sum -= a[i];

        if (sum / 2 <= 1000000 && sum % 2 == 0 && cnt[sum / 2] > 0) {
            ans.push_back(i);
        }

        sum += a[i];
        ++cnt[a[i]];
    }

    cout << ans.size() << endl;
    for (int i : ans) {
        cout << i + 1 << " ";
    }
    cout << endl;

    return 0;
}