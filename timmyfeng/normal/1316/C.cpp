#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, p;
    cin >> n >> m >> p;
    vector<int> a(n), b(m);
    for (auto& i : a) {
        cin >> i;
    }
    for (auto& i : b) {
        cin >> i;
    }
    auto f = [&](int x){ return x % p; };
    cout << find_if(a.begin(), a.end(), f) - a.begin() +
            find_if(b.begin(), b.end(), f) - b.begin();
}