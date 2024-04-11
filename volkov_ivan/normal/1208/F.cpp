#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int K = 21, MAX_N = 1 << K;
int a[MAX_N], dp1[MAX_N], dp2[MAX_N];
vector <int> poses[MAX_N];

void relax(int mask, int val) {
    if (val < dp1[mask]) dp2[mask] = max(dp2[mask], val);
}

int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        poses[a[i]].push_back(i);
    }
    for (int i = 0; i < MAX_N; i++) {
        reverse(poses[i].begin(), poses[i].end()); 
        dp1[i] = dp2[i] = -1;
        if (!poses[i].empty()) dp1[i] = poses[i].front();
    }
    for (int mask = MAX_N - 1; mask >= 0; mask--) {
        for (int bit = 0; bit < K; bit++) {
            if (!(mask & (1 << bit))) dp1[mask] = max(dp1[mask], dp1[mask | (1 << bit)]);
        }
    }
    for (int mask = MAX_N - 1; mask >= 0; mask--) {
        if (!poses[mask].empty()) relax(mask, poses[mask].front());
        if ((int) poses[mask].size() > 1) relax(mask, poses[mask][1]);
        for (int bit = 0; bit < K; bit++) {
            if (!(mask & (1 << bit))) {
                relax(mask, dp1[mask | (1 << bit)]);
                relax(mask, dp2[mask | (1 << bit)]);
            }
        }
    }
    int maxi = 0;
    for (int i = 0; i < n - 2; i++) {
        int mask = 0;
        for (int bit = K - 1; bit >= 0; bit--) if (!(a[i] & (1 << bit)) && dp2[mask | (1 << bit)] > i) mask |= 1 << bit;
        maxi = max(maxi, mask | a[i]);
    }
    cout << maxi << endl;
    return 0;
}