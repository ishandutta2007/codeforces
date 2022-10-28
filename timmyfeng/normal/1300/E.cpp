#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<long double, int>> seq;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        long double avg = a, avg1;
        int ct = 1, ct1;
        while (!seq.empty() && seq.back().first >= avg) {
            tie(avg1, ct1) = seq.back();
            seq.pop_back();
            avg = (avg * ct + avg1 * ct1) / (ct + ct1);
            ct += ct1;
        }
        seq.emplace_back(avg, ct);
    }
    cout << fixed << setprecision(10);
    for (auto i : seq) {
        for (int j = 0; j < i.second; j++) {
            cout << i.first << '\n';
        }
    }
}