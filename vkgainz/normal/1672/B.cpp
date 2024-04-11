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
        string s2; cin >> s2;
        int curr = 0;
        bool work = true;
        for (char c : s2) {
            if (c == 'B') --curr;
            else ++curr;
            if (curr < 0) work = false;
        }
        if (work && s2.back() == 'B') cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
}