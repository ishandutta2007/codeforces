#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int t, n, m;
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        int x, sum = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> x;
            sum += x;
        }
        if (sum == m)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    return 0;
}