#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <map>
#include <set>
#define tr 1000000007
#define mp make_pair
typedef long long ll;
using namespace std;
ll i,n,j,a[1000005],fv[1000005],t[1000005],straight[1000005],rev[1000005],rez;
int sum (int r)
{
    int result = 0;
    for (; r >= 0; r = (r & (r+1)) - 1)
        result += t[r];
    return result;
}

void inc (int i, int delta)
{
    for (; i < n; i = (i | (i+1)))
        t[i] += delta;
}

int sum (int l, int r)
{
    return sum (r) - sum (l-1);
}

map <ll,ll> num;
int main()
{
    cin >> n;
    rez = 0;
    for (i = 0; i < n; i++)
        scanf("%I64d",&a[i]);
    for (i = 0; i < n; i++)
    {
       straight[i] = num[a[i]]+1;
        num[a[i]]++;
    }
    num.clear();
    for (i = 0; i < n; i++)
    {
       rev[n-i-1] = num[a[n-i-1]] + 1;
       num[a[n-i-1]]++;
    }
    for (i = n - 1; i > 0; i --)
    {
       fv[rev[i]]++;
       inc(rev[i],1);
       rez += sum(0,straight[i-1]-1);
    }
    cout << rez << endl;
    return 0;
}