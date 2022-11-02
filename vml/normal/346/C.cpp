#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    set <int> box;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        box.insert(x);
    }
    vector <int> x(box.begin(), box.end());
    int a, b;
    scanf("%d %d", &a, &b);
    int ans = 0;
    while (a != b) {
        int pos_next = a - 1;
        for (int i = (int)x.size() - 1; i >= 0 && pos_next > a - x[i]; i--) {
            int next = a - a % x[i];
            if (next >= b && next < pos_next) {
                pos_next = next;
            }
        }
        while (!x.empty() && a - a % x.back() < b) {
            x.pop_back();
        }
        a = pos_next;
        ans++;
    }
    printf("%d", ans);
    return 0;
}