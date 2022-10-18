#include "bits/stdc++.h"

using namespace std;

long long step(int h, long long n, char c)
{
    if (h == 0) return 0;
    long long k = pow(2, h-1);
    if (c == L'l')
    {
        if (n <= k) return 1 + step(h-1, n, L'r');
        else return k*2 + step(h-1, n-k, L'l');
    }
    else
    {
        if (n > k) return 1 + step(h-1, n-k, L'l');
        else return k*2 + step(h-1, n, L'r');
    }

}

int main()
{
    int h; long long n;
    cin >> h >> n;

    cout << step(h, n, L'l');
}