#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

typedef long long ll;

ll l, r, m;

int main()
{
    cin >> m >> l >> r;

    if (l == 0)
    {
        cout << r / m + 1 << endl;
        return 0;
    }
    if (l > 0)
    {
        l--;
        cout << r / m - l / m << endl;
        return 0;
    }
    if (r <= 0)
    {
        swap(l, r);
        l *= -1;
        r *= -1;
        if (l == 0)
        {
            cout << r / m + 1 << endl;
            return 0;
        }
        if (l > 0)
        {
            l--;
            cout << r / m - l / m << endl;
            return 0;
        }   
    }
    cout << abs(l) / m + abs(r) / m + 1 << endl;

    return 0;
}