#include <bits/stdc++.h>
using namespace std;

vector<int> ty(int a) {
    vector<int> ret;
    while (a) ret.push_back(a % 3), a /= 3;
    return ret;
}

int main() {
    int a, c; cin >> a >> c;
    vector<int> va = ty(a), vc = ty(c);
    while (va.size() < vc.size()) va.push_back(0);
    while (vc.size() < va.size()) vc.push_back(0);
    vector<int> vb;
    for (int i = 0; i < va.size(); ++i) {
        vb.push_back((vc[i] - va[i] + 3) % 3);
    }
    long long ans = 0, t = 1;
    for (int i = 0; i < vb.size(); ++i) ans += t * vb[i], t *= 3;
    cout << ans << endl;
    return 0;
}