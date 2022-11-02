#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    int x1, y1, x2, y2;
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    vector<pair<int, int> > p;
    if (x1 > x2) {
        swap(x1, x2);
    }
    if (y1 > y2) {
        swap(y1, y2);
    }
    for (int x = x1; x <= x2; ++x) {
        p.push_back(make_pair(x, y1));
        p.push_back(make_pair(x, y2));
    }
    for (int y = y1 + 1; y < y2; ++y) {
        p.push_back(make_pair(x1, y));
        p.push_back(make_pair(x2, y));
    }
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int x, y, r;
        scanf("%d%d%d", &x, &y, &r);
        vector<pair<int, int> > left;
        for (int j = 0; j < (int)p.size(); ++j) {
            if (r * r >= (p[j].first - x) * (p[j].first - x) + (p[j].second - y) * (p[j].second - y)) {
            } else {
                left.push_back(p[j]);
            }
        }
        p = left;
    }
    printf("%d\n", (int)p.size());
    return 0;
}