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
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> in[200001];
    vector<pair<int, int>> sum(200001);
    for (int i = 1; i <= 200000; i++) {
        sum[i].second = i;
    }
    for (int i = 0; i < n; i++) {
        int m, k; cin >> m >> k;
        in[m].push_back(k);
        sum[m].first += k;
    }
    double ans = 0.0; //change to pair?? of long long, int and comp
    int bst = -1;
    for (int t = 1; t <= 20; t++) {
        //find best
        vector<double> get(200001);
        for (int i = 0; i <= 200000; i++) {
            for (int j : in[i]) {
                if (j <= t) {
                    get[i] += j * 1.0 / t;
                } else {
                    get[i] += 1.0;
                }
            }
        }
        sort(get.begin(), get.end());
        double cmp = 0.0;
        //sort, take largest t values
        for (int i = 0; i < t; i++) {
            cmp += get[200000 - i];
        }
        if (cmp > ans) {
            ans = cmp;
            bst = t;
        }
    }
    sort(sum.begin(), sum.end());
    int largest = 0;
    for (int i = 0; i < 20; i++) {
        largest += sum[200000 - i].first;
    }
    for (int t = 21; t <= 200000; t++) {
        largest += sum[200000 - (t - 1)].first;
        if (largest * 1.0 / t > ans) {
            ans = largest * 1.0 / t;
            bst = t;
        }
    }
    cout << bst << "\n";
    if (bst <= 20) {
        vector<pair<double, int>> get(200001);
        for (int i = 0; i <= 200000; i++) {
            get[i].second = i;
            for (int j : in[i]) {
                if (j <= bst) {
                    get[i].first += j * 1.0 / bst;
                } else {
                    get[i].first += 1.0;
                }
            }
        }
        sort(get.begin(), get.end());
        for (int i = 0; i < bst; i++) {
            cout << get[200000 - i].second << " ";
        }
    } else {
        for (int i = 0; i < bst; i++) {
            cout << sum[200000 - i].second << " ";
        }
    }
}