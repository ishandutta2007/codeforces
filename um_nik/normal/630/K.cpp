#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

typedef long long ll;

const int N = 2520;
int a[N + 20];

int main()
{
    a[0] = 0;
    for (int i = 1; i <= N; i++)
    {
        a[i] = a[i - 1] + 1;
        for (int j = 2; j <= 10; j++)
             if (i % j == 0)
             {
                 a[i]--;
                 break;
             }
    }
    ll n;
    cin >> n;
    cout << (n / N) * a[N] + a[n % N];
    
    return 0;
}