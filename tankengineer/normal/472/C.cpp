#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100005;

int n;

int p[N];

char name[N << 1][51];

bool byName(int i, int j) {
    return strcmp(name[i], name[j]) < 0;
}

int main() {
    scanf("%d", &n);
    vector<int> evt;
    for (int i = 0; i < n; ++i) {
        scanf("%s%s", name[i << 1], name[i << 1 | 1]);
        evt.push_back(i << 1);
        evt.push_back(i << 1 | 1);
    }
    sort(evt.begin(), evt.end(), byName);
    int tag = 0;
    for (int i = 0; i < n; ++i) {
        int p;
        scanf("%d", &p);
        --p;
        while (tag < n * 2 && (evt[tag] >> 1) != p) {
            ++tag;
        }
        if (tag == n * 2) {
            printf("NO\n");
            return 0;
        }
        ++tag;
    }
    printf("YES\n");
    return 0;
}