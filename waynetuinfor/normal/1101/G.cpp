#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; scanf("%d", &n);
    vector<int> b;
    int all = 0;
    for (int i = 0; i < n; ++i) {
        int a; scanf("%d", &a);
        all ^= a;
        for (int j = 0; j < (int)b.size(); ++j)
            a = min(a, b[j] ^ a);
        if (a) b.push_back(a);
    }
    if (all == 0) printf("-1\n");
    else printf("%d\n", (int)b.size());
}