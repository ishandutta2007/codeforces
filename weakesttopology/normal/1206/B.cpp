#include <iostream>

using namespace std;

inline long long signplus(long long x)
{
    return x >= 0 ? 1 : -1;
}


int main(int argc, char *argv[])
{
    long long n; cin >> n;

    bool zero = false;
    long long count = 0;
    long long sign = 1;

    for (long long i = 0; i < n; ++i)
    {
        long long a; cin >> a;
        sign *= signplus(a);
        count += abs(abs(a) - 1);
        if (a == 0) zero = true;
    }

    cout << count + ((sign == 1) || zero ? 0 : 2) << endl;

    return 0;
}