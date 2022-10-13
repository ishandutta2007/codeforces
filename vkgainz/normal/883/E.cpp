#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <array>
#include <math.h>
#include <array>
#include <numeric>
#include <unordered_set>
using namespace std;
 
int main() {
    int n; cin >> n;
    string s; cin >> s;
    int m; cin >> m;
    vector<string> good;
    vector<int> in;
    for (int i = 0; i < m; i++) {
        string tmp; cin >> tmp;
        int msk = 0;
        int onmsk = 0;
        bool work = true;
        for (int j = 0; j < n; j++) {
            work &= (s[j] == '*' || s[j] == tmp[j]);
            if (s[j] == '*') {
                msk |= (1 << (tmp[j] - 'a'));
            } else {
                onmsk |= (1 << (tmp[j] - 'a'));
            }
        }
        if ((onmsk & msk) || !work) {
            continue;
        }
        in.push_back(msk);
    }
    int ans = 0;
    for (int i = 0; i < 26; i++) {
        int num = 0;
        for (int ask : in) {
            if (ask & (1 << i)) {
                ++num;
            }
        }
        if (num == in.size()) {
            ++ans;
        }
    }
    cout << ans << "\n";
}