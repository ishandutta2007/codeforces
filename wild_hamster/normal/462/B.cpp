#include <iostream>
//#include <cmath>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <map>
typedef long long ll;
using namespace std;
ll n,k,l,r,a[300],i,j,rez;
char c;
int main()
{
    cin >> n >> k;
    l = (int)'A'; r = (int)'Z';
    for (i = 0; i < n; i++)
    {
        cin >> c;
        a[(int)c]++;
    }
    sort(a,a+300);
    i = 299; rez = 0;
    while (k > 0)
    {
          if (k >= a[i])
          k -= a[i], rez += a[i]*a[i];
          else
          rez+=k*k, k=0;
          i--;
    }
    cout << rez << endl;
    return 0;
}