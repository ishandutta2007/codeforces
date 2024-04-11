#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cstring>
using std::cerr;
using std::cin;
using std::cout;
int t, n;
int main(int argc, char const *argv[])
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> t;
    while (t--)
    {
        cin >> n;
        if (n == 1)
        {
            cout << "0\n";
        }
        else if (n == 2)
        {
            cout << "1\n";
        }
        else if (n == 3)
        {
            cout << "2\n";
        }
        else if (!(n % 2))
        {
            cout << "2\n";
        }
        else
        {
            cout << "3\n";
        }
    }
    return 0;
}