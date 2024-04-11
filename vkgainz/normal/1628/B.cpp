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
 
int get(string s) {
    int ans = 0;
    int mult = 1;
    for (int i = 0; i < s.length(); i++) {
        ans += (s[i] - 'a') * mult;
        mult *= 26;
    }
    return ans;
}

int getRev(string s) {
    reverse(s.begin(), s.end());
    return get(s);
}

bool has(vector<string> &s) {
    int n = s.size();
    set<int> inThree;
    set<int> inTwo;
    set<int> inPref;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i].length() == 3) {
            inThree.insert(get(s[i]));
            //3 3
            if (inThree.count(getRev(s[i]))) {
                return true;
            }
            //3 2
            if (inTwo.count(getRev(s[i].substr(0, 2)))) {
                return true;
            }
            inPref.insert(get(s[i].substr(1, 2)));
        } else if (s[i].length() == 2) {
            inTwo.insert(get(s[i]));
            //2 2
            if (inTwo.count(getRev(s[i]))) {
                return true;
            }
            //2 3
            if (inPref.count(getRev(s[i]))) {
                return true;
            }

        }
    }
    return false;
}

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<string> s(n);
        bool work = false;
        for (int i = 0; i < n; i++) {
            cin >> s[i];
            if (s[i].length() == 1) {
                work = true;
            }
        }
        if (work) {
            cout << "YES" << "\n";
            continue;
        }
        work |= (has(s));
        if (work) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
}