#include <iostream>
#include <vector>
#include <map>

using namespace std;

int eq(int n) {
    if (n == 0) return 0;
    int i = 2;
    vector <pair <int, int> > fact;
    if (n < 0) fact.push_back(make_pair(-1, 1));
    n = abs(n);
    while (i * i <= n) {
        if (n % i == 0) {
            n /= i;
            fact.push_back(make_pair(i, 1));
            while (n % i == 0) {
                n /= i;
                fact.back().second++;
            }
        }
        i++;
    }
    if (n != 1) fact.push_back(make_pair(n, 1));
    int ans = 1;
    for (pair <int, int> elem : fact) if (elem.second % 2 == 1) ans *= elem.first;
    return ans;
}

int main() {
    int n;
    cin >> n;
    int arr[n], arr2[n], new_arr[n], ans[n + 1], cnt[n], now;
    map <int, int> dict;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        new_arr[i] = eq(arr[i]);
        if (dict.find(new_arr[i]) == dict.end()) {
            dict[new_arr[i]] = dict.size() - 1;
        }
        arr2[i] = dict[new_arr[i]];
        ans[i + 1] = 0;
    }
    int diff;
    bool only_zeroes;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cnt[j] = 0;
        }
        diff = 0;
        only_zeroes = 1;
        for (int j = i; j < n; j++) {
            if (cnt[arr2[j]] == 0 && new_arr[j] != 0) {
                cnt[arr2[j]]++;
                diff++;
                only_zeroes = 0;
            }
            if (only_zeroes) ans[1]++;
            else ans[diff]++;
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << ' ';
    }
    cout << endl;
    return 0;
}