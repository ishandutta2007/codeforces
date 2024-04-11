#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <map>
#include <math.h>
#include <array>
 
using namespace std;
 
int main() {
    int n; cin >> n;
    vector<int> a(n);
    vector<pair<int, int>> in;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] < 0) a[i] = -a[i] - 1;
    }
    for (int i = 0; i < n; i++) {
        in.push_back({a[i], i});
    }
    sort(in.begin(), in.end());
    if (in[n - 1].first == 0) {
        if (n % 2 == 0) {
            //ch
            for (int i = 0; i < n; i++) {
                cout << -1 << " ";
            }
        } else {
            for (int i = 0; i < n; i++) {
                cout << a[i] << " ";
            }
        }
    } else {
        int numNeg = 0;
        for (int i = 0; i < n; i++) {
            if (in[i].first == 0) {
                in[i].first = -in[i].first - 1;
                ++numNeg;
            } else if (in[i].first != 0) {
                int j = i;
                if (numNeg % 2) {
                    in[j].first = -in[j].first - 1;
                    ++j;
                }
                for (; j < n - 1; j += 2) {
                    in[j].first = -in[j].first - 1;
                    in[j + 1].first = -in[j + 1].first - 1;
                }
                break;
            }
        }
        vector<int> restore(n);
        for (int i = 0; i < n; i++) {
            restore[in[i].second] = in[i].first;
        }
        for (int i = 0; i < n; i++) {
            cout << restore[i] << " ";
        }
        cout << "\n";
    }
}