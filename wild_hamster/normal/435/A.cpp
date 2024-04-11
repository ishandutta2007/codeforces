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
ll m,i,n,k,j,a[300500],b[300500],t,x,y,z,d1,d2,rez,as,bs,odds,evens;
int main()
{
    cin >> n >> m;
    rez = 0;
    for (i = 0; i < n; i++)
        cin >> a[i];
    i = 0;
    while (i < n)
    {
     k = m;
     while (a[i] <= k && i < n)
     {
           k -=a[i];
           i++;
     }
     rez++;
           
    }
    cout << rez << endl;
    return 0;
}