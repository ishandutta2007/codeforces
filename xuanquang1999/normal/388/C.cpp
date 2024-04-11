#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);

    vector<int> odd;
    int sumA = 0, sumB = 0;

    for(int i = 0; i < n; ++i) {
        int k;
        scanf("%d", &k);

        vector<int> c(k);
        for(int i = 0; i < k; ++i)
            scanf("%d", &c[i]);

        int p = k/2;
        for(int i = 0; i < p; ++i)
            sumA += c[i];
        for(int i = k - p; i < k; ++i)
            sumB += c[i];
        if (k%2 == 1)
            odd.push_back(c[p]);
    }

    sort(odd.begin(), odd.end());
    reverse(odd.begin(), odd.end());

    for(int i = 0; i < odd.size(); ++i)
        if (i%2 == 0)
            sumA += odd[i];
        else
            sumB += odd[i];

    printf("%d %d", sumA, sumB);

    return 0;
}