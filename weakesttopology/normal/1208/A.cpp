#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    int T; cin >> T;
    for (int i = 0; i < T; ++i)
    {
        long long a, b, n; cin >> a >> b >> n;

        if (n % 3 == 0)
            cout << a << endl;
        else if (n % 3 == 1)
            cout << b << endl;
        else
            cout << (a ^ b) << endl;
    }
    return 0;
}