#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cstring>
#define int long long

using namespace std;

signed main() {
    int n;
    cin >> n;
    pair <long long, long long> a[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first;
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i].second;
    }
    map <int, int> cnt, summ;
    for (int i = 1; i <= n; i++) {
        cnt[a[i].first]++;
        summ[a[i].first] += a[i].second;
    }
    int ans = 0;
    vector <int> used;
    vector <int> dontknow;
    for (pair <int, int> elem : cnt) {
        if (elem.second > 1) {
            used.push_back(elem.first);
            ans += summ[elem.first];
        } else {
            dontknow.push_back(elem.first);
        }
    }
    for (int elem : dontknow) {
        for (int elem2 : used) {
            if ((elem & elem2) == elem) {
                ans += summ[elem];
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}