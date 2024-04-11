#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

typedef long long ll;

ll a, b;
int ans;
const int N = 62;

int main()
{
    cin >> a >> b;
    ans = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < i - 1; j++)
        {
            ll x = (1LL << i) - (1LL << j) - 1;
            if (a <= x && x <= b)
                ans++;
        }
    cout << ans << endl;

    return 0;
}