#include <iostream>
//#include <cmath>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <map>
typedef long long ll;
using namespace std;
ll n,k,l,r,a[500000],i,j,rez;
char c;
int main()
{
    cin >> n;
    rez = 0;
    for (i = 0; i < n; i++)
        cin >> a[i];
    sort(a,a+n);
    for (i = 0; i < n - 1; i++)
        rez += a[i]*(i+2);
    rez += a[n-1]*n;
    cout << rez << endl;
    return 0;
}