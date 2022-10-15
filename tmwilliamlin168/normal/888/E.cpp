#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

vector<i64> number = { 0 };
i64 ans = 0;
i64 v[40], s;

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i(1); i <= n; i++)
        cin >> v[i];

    int st = (n + 1) / 2, dr = n / 2;

    for (int mask = 0; mask < (1 << dr); mask++) {
        s = 0;
        for (int i(0); i < st; i++) {
            if (mask & (1 << i)) {
                s = (s + v[st + i + 1]) % m;
            }
        }
        number.push_back(s);
    }

    sort(number.begin(), number.end());

    for (int mask(0); mask < (1 << st); mask++) {
        s = 0;
        for (int i = 0;  i < st; i++) {
            if (mask & (1 << i))
                s = (s + v[i + 1]) % m;
        }
        vector <i64> :: iterator it = lower_bound(number.begin(), number.end(), m - s);
        it--;

        ans = max(ans, s + (*it));
    }


    cout << ans;
}