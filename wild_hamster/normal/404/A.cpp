#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <map>
#include <set>
#include <string>
#include <cstring>
#define tr 1000000007
#define mp make_pair
#define pb push_back
#define tA 555
#define tB 666
#define AorB 777
typedef long long ll;
using namespace std;
ll a[100500],s,n,m,j,p,l,r,x,y,k1,k2,k3,k4,k,i,cur,rez,kokoko;
 char c;
int main()
{
    cin >> n;
    char diag = '1', ndiag = '1';
    ll z = 1;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
        {
        cin >> c;
        if (i == j||i+j == n-1)
           {
                 if (diag != '1'&& c != diag)
                    z = 0;
                 diag = c;
           } else
           {
                 if (ndiag != '1'&& c != ndiag)
                    z = 0;
                 ndiag = c;
           }
        }
        
    if (z&&diag!=ndiag) cout << "YES" << endl;
       else cout << "NO" << endl;
   return 0;
}