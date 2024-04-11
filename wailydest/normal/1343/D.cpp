#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool comp(pair<int, bool> a, pair<int, bool> b)
{
    if (a.first != b.first) return a.first < b.first;
    return a.second > b.second;
}

int main()
{
    int t;
    scanf("%d", &t);
    
    while (t--) {
        int n, k;
        scanf("%d%d", &n, &k);
        vector<int> a(n);
        for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
        vector<int> amount(k * 2 + 1);
        vector<pair<int, bool> > seg;
        for (int i = 0; i < n / 2; ++i) {
            seg.push_back(make_pair(1 + min(a[i], a[n - i - 1]), 1));
            seg.push_back(make_pair(k + max(a[i], a[n - i - 1]), 0));
            ++amount[a[i] + a[n - i - 1]];
        }
        sort(seg.begin(), seg.end(), comp);
        int current = 0;
        vector<int> op(k * 2 + 1, INT_MAX);
        for (int i = 1, j = 0; i < k * 2 + 1; ++i) {
            while (j < n && seg[j].first == i && seg[j].second) {
                ++current;
                ++j;
            }
            op[i] = min(op[i], current - amount[i] + (n / 2 - current) * 2);
            while (j < n && seg[j].first == i && !seg[j].second) {
                --current;
                ++j;
            }
        }
        int mn = INT_MAX;
        for (int i = 0; i < k * 2 + 1; ++i) mn = min(mn, op[i]);
        printf("%d\n", mn);
    }
    return 0;
}