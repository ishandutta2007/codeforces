#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;
int a[maxn];

int main() {
    int n; scanf("%d", &n);
    vector<int> pos, zer, neg;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        if (a[i] > 0) pos.push_back(i);
        if (a[i] == 0) zer.push_back(i);
        if (a[i] < 0) neg.push_back(i);
    }
    while (zer.size() > 1) {
        int x = zer.back(); zer.pop_back();
        printf("1 %d %d\n", x, zer.back());
    }
    if (zer.size() > 0) {
        assert(zer.size() == 1);
        if (neg.size() % 2 == 1) {
            int p = -1;
            for (int i = 0; i < neg.size(); ++i) {
                int x = a[neg[i]];
                if (p == -1 || abs(x) < abs(a[p])) p = neg[i];
            }
            printf("1 %d %d\n", p, zer[0]);
            vector<int> all;
            for (int i = 0; i < neg.size(); ++i) {
                int x = neg[i];
                if (x == p) continue;
                all.push_back(x);
            }
            for (int i : pos) all.push_back(i);
            if (all.size() > 0) {
                printf("2 %d\n", zer[0]);
                zer.pop_back();
            }
            for (int i = 0; i + 1 < all.size(); ++i) {
                printf("1 %d %d\n", all[i], all[i + 1]);
            }
        } else {
            if (pos.size() + neg.size() > 0) {
                printf("2 %d\n", zer.back()); 
            }
            zer.pop_back();
            vector<int> all;
            for (int i : neg) all.push_back(i);
            for (int i : pos) all.push_back(i);
            for (int i : zer) all.push_back(i);
            for (int i = 0; i + 1 < all.size(); ++i) {
                printf("1 %d %d\n", all[i], all[i + 1]);
            }
        }
    } else {
        if (neg.size() % 2 == 1) {
            int p = -1;
            for (int i = 0; i < neg.size(); ++i) {
                int x = a[neg[i]];
                if (p == -1 || abs(x) < abs(a[p])) p = neg[i];
            }
            if (pos.size() + zer.size() + neg.size() - 1 > 0) {
                printf("2 %d\n", p);
            }
            vector<int> all;
            for (int i = 0; i < neg.size(); ++i) {
                if (neg[i] == p) continue;
                all.push_back(neg[i]);
            }
            for (int i : pos) all.push_back(i);
            for (int i : zer) all.push_back(i);
            for (int i = 0; i + 1 < all.size(); ++i) {
                printf("1 %d %d\n", all[i], all[i + 1]);
            }
        } else {
            vector<int> all;
            for (int i : neg) all.push_back(i);
            for (int i : pos) all.push_back(i);
            for (int i : zer) all.push_back(i);
            for (int i = 0; i + 1 < all.size(); ++i) {
                printf("1 %d %d\n", all[i], all[i + 1]);
            }
        }
    }
    return 0; 
}