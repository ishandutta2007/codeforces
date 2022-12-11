#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.sync_with_stdio(false);
    int k; string n;
    cin >> k >> n;

    int total = 0;
    for (char c : n) total += c - '0';

    int ans = 0;

        for (int z = '0'; z <= '9' && k > total; z++)
        {
            for (char &ch : n)
            {
                if (ch == z)
                {
                    ++ans;
                    total += '9' - z;
                    if (k <= total) break;
                }
            }
        }
    printf("%d\n", ans);
}