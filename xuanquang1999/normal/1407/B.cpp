#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1005;

int gcd(int a, int b) {return (b == 0) ? a : gcd(b, a%b);}

int nTest, n, a[MAXN];
bool avail[MAXN];

int main() {
    scanf("%d", &nTest);
    while (nTest--) {
        scanf("%d", &n);
        for(int i = 0; i < n; ++i)
            scanf("%d", &a[i]);

        for(int i = 0; i < n; ++i)
            avail[i] = true;

        vector<int> ans;

        int curGCD = 0;
        for(int i = 0; i < n; ++i) {
            int bestGCD = 0, bestInd = 0;
            for(int j = 0; j < n; ++j) {
                if (avail[j]) {
                    int x = gcd(curGCD, a[j]);
                    if (x > bestGCD) {
                        bestGCD = x;
                        bestInd = j;
                    }
                }
            }

            curGCD = bestGCD;
            ans.push_back(a[bestInd]);
            avail[bestInd] = false;
        }

        for(int x: ans)
            printf("%d ", x);
        puts("");
    }

    return 0;
}