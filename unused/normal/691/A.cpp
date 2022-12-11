#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t; cin >> t;
    int s = 0;
    for (int i = 0; i < t; i++)
    {
        int x;
        cin >> x;
        s += x;
    }

    if (s == max(1, t - 1)) printf("YES\n");
    else printf("NO\n");
}