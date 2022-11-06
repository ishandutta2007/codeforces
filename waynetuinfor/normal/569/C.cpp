#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e6 + 10;
bool v[maxn];
int pi[maxn], rub[maxn];

bool check(int k) {
    string s;
    stringstream ss; ss << k; ss >> s;
    string t = s; reverse(t.begin(), t.end());
    return s == t;
}

int main() {
    vector<int> pr;
    v[1] = true;
    for (int i = 2; i < maxn; ++i) {
        if (!v[i]) pr.push_back(i);
        for (int j = 0; i * pr[j] < maxn; ++j) {
            v[i * pr[j]] = true;
            if (i % pr[j] == 0) break;
        }
    }
    for (int i = 1; i < maxn; ++i) {
        pi[i] = pi[i - 1];
        if (!v[i]) ++pi[i];
    }
    for (int i = 1; i < maxn; ++i) {
        rub[i] = rub[i - 1];
        if (check(i)) ++rub[i];
    }
    int p, q; cin >> p >> q;
    for (int i = maxn - 1; i >= 0; --i) {
        if (q * pi[i] <= p * rub[i]) return cout << i << endl, 0;
    }
    cout << "Palindromic tree is better than splay tree" << endl;
    return 0;
}