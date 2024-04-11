//
// Created by Danny Mittal on 3/20/22.
//

#define ll long long

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

ll xs[100000];
vector<int> things[200001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int j = 0; j < n; j++) {
        cin >> xs[j];
    }
    for (int d = -320; d <= 320; d++) {
        for (int j = 0; j < n; j++) {
            things[d + 100000].push_back(xs[j] - (((ll) d) * ((ll) j)));
        }
    }
    for (int j = 0; j < n; j++) {
        set<int> ds;
        for (int k = max(0, j - 320); k <= min(n - 1, j + 320); k++) {
            if (k != j && (xs[k] - xs[j]) % (k - j) == 0) {
                int d = (xs[k] - xs[j]) / (k - j);
                if (abs(d) > 320) {
                    ds.insert(d);
                }
            }
        }
        for (int d : ds) {
            things[d + 100000].push_back(xs[j] - (((ll) d) * ((ll) j)));
        }
    }
    int answer = 0;
    for (vector<int> thing : things) {
        ll last = 1LL << 60;
        int amt = 0;
        sort(thing.begin(), thing.end());
        for (ll x : thing) {
            if (x != last) {
                last = x;
                amt = 0;
            }
            amt++;
            answer = max(answer, amt);
        }
    }
    cout << n - answer << endl;
}