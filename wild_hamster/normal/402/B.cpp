#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <deque>
#define tr 1000000007
#define mp make_pair
#define pb push_back
#define tA 555
#define tB 666
#define AorB 777
typedef long long ll;
using namespace std;
ll n,m,j,p,l,r,x,y,k1,k2,k3,k4,k,i,a[100500],b[100500],w;
vector <string> rez;
int main()
{
    cin >> n >> k;
    for (i = 0; i < n; i++)
        cin >> a[i];
    ll max1 = 0, curi = 0;
    for (j = 0; j < n; j++)
    if (a[j] > j*k)
    {
    ll tmp = 0;

    for (i = j; i < n; i++)
    {
        if (a[i] == a[j] + k*(i-j))
          tmp++;
        if (tmp > max1)
           max1 = tmp, curi = j;
    }
}
    b[0] = a[curi] - curi*k;
    for (i = 1; i < n; i++)
        b[i] = b[i-1] + k;
    cout << n - max1 << endl;
    for (i = 0; i < n; i++)
    {
       if (a[i] < b[i])
          cout << "+ " << i+1 << " " << b[i] - a[i] << endl;
        else 
       if (a[i] > b[i])
          cout << "- " << i+1 << " " << -b[i] + a[i] << endl;
    }
   return 0;
}