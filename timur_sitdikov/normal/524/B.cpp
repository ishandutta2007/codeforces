
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <utility>
using namespace std;

int main () {

    int n;
    cin >> n;
    vector<pair<int, int> > v(n);
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        v[i] = make_pair(a, b);
    }
    int best = (int)1e9;
    for (int h = 1000; h > 0; --h) {
        int w = 0;
        for (int i = 0; i < n; ++i) {
            if (min(v[i].first, v[i].second) > h) {
                w = 0;
                break;
            }
            if (max(v[i].first, v[i].second) <= h) {
                w += min(v[i].first, v[i].second);
            } else {
                w += max(v[i].first, v[i].second);
            }
        }
        if (w != 0) {
            best = min(best, w * h);
        }
    }   
    cout << best;
    return 0;
}