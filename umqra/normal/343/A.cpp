#include <iostream>
#include <cstdio>
#include <algorithm>    
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <cmath>
#include <ctime>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define X first
#define Y second
#define mp make_pair

int main()
{
#ifndef ONLINE_JUDGE
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
#endif

    ll a, b;
    scanf("%lld%lld", &a, &b);
    ll cnt = 0;
    while (a > 0)
    {
        if (a >= b)
        {
            cnt += (a / b);
            a = a % b;
        }
        else
        {
            cnt += (b / a);
            ll nA = a;
            ll nB = b % a;
            if (nB == 0)
            {
                nB = a;
                cnt--;
            }
            a = nA;
            b = nB;
        }                                              
    }
    cout << cnt;

    return 0;
}