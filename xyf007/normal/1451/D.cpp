#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using std::cerr;
using std::cin;
using std::cout;
int t, k, d;
int main(int argc, char const *argv[])
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> t;
    while (t--)
    {
        cin >> k >> d;
        long long z = k / (sqrt(2) * d);
        if ((2 * z * z + 2 * z + 1) * d * d <= k * static_cast<long long>(k))
        {
            cout << "Ashish\n";
        }
        else
        {
            cout << "Utkarsh\n";
        }
    }
    return 0;
}