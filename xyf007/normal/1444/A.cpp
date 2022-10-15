#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
int t;
long long p, q;
void checkmin(long long &x, long long y)
{
    if (x > y)
    {
        x = y;
    }
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> t;
    while (t--)
    {
        cin >> p >> q;
        if (p % q)
        {
            cout << p << '\n';
            continue;
        }
        long long pp = p, ans = 1e18;
        for (long long i = 2; i * i <= q; i++)
        {
            if (!(q % i))
            {
                long long sum = 1;
                while (!(p % i))
                {
                    p /= i;
                    sum *= i;
                }
                while (!(q % i))
                {
                    q /= i;
                    sum /= i;
                }
                sum *= i;
                checkmin(ans, sum);
            }
        }
        if (q > 1)
        {
            long long ss = 1;
            while (!(p % q))
            {
                p /= q;
                ss *= q;
            }
            checkmin(ans, ss);
        }
        cout << pp / ans << '\n';
    }
    return 0;
}