#include <map>
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int n;

const int N = 100005;

int a[N];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
    }
    map<int, long long> ans;
    vector<pair<int, int> > good;
    for (int i = n - 1; i >= 0; --i) {
        vector<pair<int, int> > better;
        better.push_back(make_pair(a[i], i));
        for (int j = 0; j < (int)good.size(); ++j) {
            good[j].first = __gcd(good[j].first, a[i]);
            if (good[j].first == better.back().first) {
                better.back().second = good[j].second;
            } else {
                better.push_back(good[j]);
            }
        }
        int last = i - 1;
        for (int j = 0; j < (int)better.size(); ++j) {
            ans[better[j].first] += better[j].second - last;
            last = better[j].second;
        } 
        good = better;
    }
    int q;
    scanf("%d", &q);
    while (q--) {
        int x;
        scanf("%d", &x);
        printf("%I64d\n", ans[x]);
    }
    return 0;
}