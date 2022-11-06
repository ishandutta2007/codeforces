#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000 + 5;
pair<int, int> p[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> p[i].first >> p[i].second;
        if (p[i].first != p[i].second) return cout << "rated\n", 0;
    } 
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) if (p[i].first < p[j].second) return cout << "unrated\n", 0;
    } 
    return cout << "maybe\n", 0;
}