#include <iostream>
#include <vector>
#include <map>
#include <cassert>

using namespace std;

vector <int> fact(int n) {
    int i = 2;
    vector <int> res;
    while (i * i <= n) {
        if (n % i == 0) {
            res.push_back(i);
            while (n % i == 0) n /= i;
        }
        i++;
    }
    if (n != 1) res.push_back(n);
    return res;
}

void solve() {
    int n;
    cin >> n;
    vector <int> kek(n), res(n);
    for (int i = 0; i < n; i++) cin >> kek[i];
    map <int, int> cl;
    for (int i = 0; i < n; i++) {
        auto mem = fact(kek[i]);
        int sz = cl.size();
        res[i] = -1;
        for (int elem : mem) {
            if (cl.find(elem) != cl.end()) {
                res[i] = cl[elem];
                break;
            }
        }
        if (res[i] == -1) {
            res[i] = sz + 1;
            cl[mem[0]] = sz + 1;
        }
    }
    assert((int) cl.size() <= 11);
    cout << cl.size() << "\n";
    for (int i = 0; i < n; i++) cout << res[i] << ' ';
    cout << "\n";
}

int main() {
    //freopen("Desktop/input.txt", "r", stdin);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}