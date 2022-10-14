#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>
#include <deque>
#include <time.h>
#include <stack>
#include <stdio.h>
#include <map>
#include <set>
#include <string>
#define mp make_pair
#define pb push_back
#define PI 3.14159265358979323846
#define MOD 1000000007
typedef long long ll;
using namespace std;
ll a[15][15],b[10],i,j,n,k,m,rez;
bool good(ll n)
{
    ll a[12];
    for (int i = 0; i < 10; i++)
        a[i] = 0;
    while (n)
    {
        ll digit = n%10;
        n /= 10;
        if (digit < 1 || digit > 5)
            return false;
        if (a[digit] > 0) return false;
        a[digit] = 1;
    }
    return true;
}
int main()
{
    for (i = 1; i <= 5; i++)
        for (j = 1; j <= 5; j++)
            cin >> a[i][j];
    for (i = 10000; i < 100000; i++)
        if (good(i))
    {
        //cout << i << endl;
        j = 1;
        n = i;
        while (n)
        {
            b[j++] = n%10;
            n/=10;
        }
        ll tmp = 0;
        for (j = 1; j <= 5; j++)
            for (k = j; k <= 4; k += 2)
                tmp += a[b[k]][b[k+1]] + a[b[k+1]][b[k]];
        //cout << tmp << endl;
        rez = max(rez,tmp);
    }
    cout << rez << endl;
    return 0;
}