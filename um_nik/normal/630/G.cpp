#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

typedef long long ll;

ll getC(ll n, int k)
{
    if (k > n) return 0;
    ll res = 1;
    for (int i = 0; i < k; i++)
    {
        res *= n - i;
        res /= i + 1;
    }
    return res;
}

int main()
{
    ll n;
    cin >> n;
    n--;
    cout << getC(n + 3, 3) * getC(n + 5, 5) << endl;
    
    return 0;
}