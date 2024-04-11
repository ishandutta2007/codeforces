#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <map>
#define tr 1000000007
#define mp make_pair
typedef long long ll;
using namespace std;
ll d,k,n,i,j,a[2000],tmp,step[2005];
int main()
{
    cin >> n >> k >> d;
    tmp = 1;
    for (i = 0; i < d; i++)
    {
        tmp*=k;
        if (tmp > 10000) tmp = 10000;
    }
    if (tmp < n)
    {
            cout << -1 << endl;
            return 0;
    }
    tmp = (ll)exp((1./d)*log(n));
    if (tmp < k) tmp++;
    step[0] = 1;
    for (i = 1; i <= d; i++)
    {
        step[i] = step[i-1]*tmp;
        if (step[i] > 10000) step[i] = 10000;
    }
    for (i = 0; i < d; i++)
    {
        for (j = 0; j < n; j++)
            cout << (j/step[d-i-1])%tmp+1 << " ";
        cout << endl;
    }
    return 0;
}