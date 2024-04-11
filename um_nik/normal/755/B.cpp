#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <set>
using namespace std;

int n, m, k;
set<string> setik;
string s;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    k = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        setik.insert(s);
    }
    for (int i = 0; i < m; i++)
    {
        cin >> s;
        if (setik.count(s) > 0)
            k++;
    }
    n -= k;
    m -= k;
    k %= 2;
    n += k;
    if (n > m)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}