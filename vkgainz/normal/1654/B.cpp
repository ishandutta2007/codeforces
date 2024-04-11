#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <iomanip>
#include <queue>
#include <map>
#include <numeric>
#include <math.h>
#include <array>
 
using namespace std;
 
int main() {
    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        vector<int> occ(26);
        for (char c : s) {
            ++occ[c - 'a'];
        }
        reverse(s.begin(), s.end());
        while (!s.empty()) {
            if (occ[s.back() - 'a'] >= 2) {
                --occ[s.back() - 'a'];
                s.pop_back();
            } else {
                break;
            }
        }
        reverse(s.begin(), s.end());
        cout << s << "\n";
    }
}