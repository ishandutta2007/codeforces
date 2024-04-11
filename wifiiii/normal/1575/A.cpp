#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        for(int j = 1; j < a[i].size(); j += 2) {
            a[i][j] = 128 - a[i][j];
        }
    }
    vector<int> ord(n);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](auto &i, auto &j) {return a[i] < a[j];});
    for(int i : ord) cout << i + 1 << " "; cout << '\n';
}