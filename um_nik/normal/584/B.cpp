#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

typedef long long ll;

const ll MOD = (ll)1e9 + 7;

int main()
{
    int x = 27;
    int y = 0;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            for (int k = 0; k < 3; k++)
                if (i + j + k == 3)
                    y++;
    ll a = 1;
    ll b = 1;
    int n;
    cin >> n;
    while(n--)
    {
        a = (a * x) % MOD;
        b = (b * y) % MOD;
    }
    a -= b;
    if (a < 0) a += MOD;
    cout << a << endl;

    return 0;
}