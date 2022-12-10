#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <queue>
#include <vector>
#include <map>
#include <cmath>
#include <string>
#include <stack>
#include <set>
#include <algorithm>
#include <list>
#pragma comment(linker, "/STACK:167772160")
using namespace std;
//8739
const double PI = 3.14159265358979323846;
const long long MODUL = 1000000007;
const long long MAXINT = 2e9 + 2;
const long long MAXLL = 2e18 + 2;
const double eps = 1e-11;
const int MAXN = 1e5 + 10;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, beg(1);
    long long k, fibo[52];
    cin >> n >> k;
    fibo[0] = fibo[1] = 1;
    for(int i(2); i < 52; ++i)
        fibo[i] = fibo[i - 1] + fibo[i - 2];
    while(n)
    {
        if(k > fibo[n - 1])
        {
            cout << beg + 1 << ' ' << beg << ' ';
            k -= fibo[n - 1];
            ----n;
            ++++beg;
        }
        else
        {
            cout << beg << ' ';
            ++beg;
            --n;
        }
    }
    return 0;
}