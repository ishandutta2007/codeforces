#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long m, n;
    cin >> m >> n;
    long long step = 0;
    if (m < n) swap(m, n);
    while (m > 1 && n > 0)
    {
        step+=m/n;
        m%=n;
        if (m < n) swap(m, n);
    }
    cout << step << "\n";
}