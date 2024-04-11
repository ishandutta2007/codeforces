#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

typedef long long ll;

int main()
{
    int n;
    cin >> n;
    ll x = 2;
    while(n--)
        x *= 2LL;
    x -= 2;
    cout << x << endl;
    
    return 0;
}