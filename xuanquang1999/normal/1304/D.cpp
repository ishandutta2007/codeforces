#include <bits/stdc++.h>

using namespace std;

vector<int> solveMaxLIS(string s) {
    int n = s.length() + 1;
    vector<int> res(n);

    int last = 0;
    for(int i = 0; i < n; ++i) {
        if (i == n-1 || s[i] == '<') {
            for(int j = last; j <= i; ++j)
                res[j] = i+1 - j + last;
            last = i + 1;
        }
    }

    return res;
}

int main() {
    int nTest;
    scanf("%d", &nTest);

    while (nTest--) {
        int n;
        string s;
        cin >> n >> s;

        vector<int> ansMax = solveMaxLIS(s);

        reverse(s.begin(), s.end());
        for(int i = 0; i < n-1; ++i)
            s[i] = '>' + '<' - s[i];
        vector<int> ansMin = solveMaxLIS(s);
        reverse(ansMin.begin(), ansMin.end());

        for(int x: ansMin)
            printf("%d ", x);
        puts("");
        for(int x: ansMax)
            printf("%d ", x);
        puts("");
    }

    return 0;
}