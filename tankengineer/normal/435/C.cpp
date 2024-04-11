#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector<pair<pair<int, int>, char> > p;
    int x = -1, y = 0;
    for (int i = 0; i < n; ++i) {
        int m;
        scanf("%d", &m);
        for (int j = 0; j < m; ++j) {
            char ch = i % 2 == 0 ? '/' : '\\';
            ++x;
            if (j) {
                if (i % 2 == 0) {
                    ++y;
                } else {
                    --y;
                }
            }
            p.push_back(make_pair(make_pair(-y, x), ch));
        }
    }
    sort(p.begin(), p.end());
    char tmp[1005];
    for (int i = 0; i < (int)p.size(); ++i) {
        int j = i;
        while (j < (int)p.size() && p[j].first.first == p[i].first.first) {
            ++j;
        }
        --j;
        int w = p.size();
        for (int k = 0; k < w; ++k) {
            tmp[k] = ' ';
        }
        tmp[w] = '\0';
        for (int k = i; k <= j; ++k) {
            tmp[p[k].first.second] = p[k].second;
        }
        printf("%s\n", tmp);
        i = j;
    }
    return 0;
}