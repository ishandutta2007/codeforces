#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int t, a, b, c, d;
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> t;
    while (t--)
    {
        cin >> a >> b >> c >> d;
        if (a > b * static_cast<long long>(c))
        {
            cout << "-1\n";
            continue;
        }
        long long tmp = (a - 1) / b / d + 1;
        cout << tmp * a - tmp * (tmp - 1) / 2 * b * d << '\n';
    }
    return 0;
}