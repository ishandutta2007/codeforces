#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
int a[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<int> v;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] == 0) v.push_back(i);
    }
    for (int i = 0; i < n; ++i) {
        auto it = lower_bound(v.begin(), v.end(), i);
        int dis = (it == v.end() ? n + 1 : abs(*it - i));
        --it;
        if (it >= v.begin()) dis = min(dis, abs(*it - i));
        cout << dis << ' ';
    }
    cout << endl;
    return 0;
}