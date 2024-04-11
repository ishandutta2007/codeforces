#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
int n, m, q;
string a[21], b[21];
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    a[0] = a[n];
    for (int i = 1; i <= m; i++)
    {
        cin >> b[i];
    }
    b[0] = b[m];
    cin >> q;
    while (q--)
    {
        int x;
        cin >> x;
        cout << a[x % n] << b[x % m] << endl;
    }
    return 0;
}