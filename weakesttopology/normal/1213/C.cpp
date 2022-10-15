#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    int q; cin >> q;

    for (int i = 0; i < q; ++i)
    {
        unsigned long long n, m; cin >> n >> m;
        unsigned long long sum = 0;
        unsigned long long dsum = 0;

        for (unsigned long long w = m; w <= 10 * m; w += m)
            dsum += w % 10;

        sum += dsum * (n / (10 * m));

        for (unsigned long long w = m; w <= n % (10 * m); w += m)
            sum += w % 10;

        cout << sum << endl;
    }

    return 0;
}