#include <bits/stdc++.h>

using namespace std;

int n;
map<int, int> a, nMap;
int main() {
    cin >> n;

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        int val;
        cin >> val;
        if (a.find(val) != a.end()) {
            nMap[a[val]]--;
            if (nMap[a[val]] == 0) nMap.erase(a[val]);
        }
        a[val]++; nMap[a[val]]++;
        if (a.size() == 1) ans = i;
        else {
            if (nMap.size() == 1 && nMap.begin()->first == 1) ans = i;
            if (nMap.size() == 2) {
                if (nMap.begin()->first == 1 && 
                    nMap.begin()->second == 1) ans = i;
                if (nMap.rbegin()->first == nMap.begin()->first + 1 
                    && nMap.rbegin()->second == 1) ans = i;
            }
        }
    }
    cout << ans;
}