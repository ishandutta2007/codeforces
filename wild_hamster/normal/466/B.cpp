#include <iostream>
//#include <cmath>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <map>
#include <set>
#define tr 1000000007
#define mp make_pair
typedef long long ll;
using namespace std;
ll x1,x2,a1,b1,k,j,x,y,n,m,rez1,rez2,rez,cnt,d,i,b,a,inva[100600],bd[100500];
string s;
int main()
{
    cin >> n >> a >> b;
    n = 6LL*n;
    rez = (ll)1e+18 + 15; 
    for (x1 = 0; x1 < 100000; x1++)
    {
        double tmp = n/((double)(a+x1)) - (double)b;
        x2 = (ll)tmp;
        x2 = max(x2-3,(ll)0);
        while ((a+x1)*(b+x2) < n)
              x2++;
        if (rez > (a+x1)*(b+x2) )
        {
        rez = min(rez,(a+x1)*(b+x2));
        rez1 = a+x1; rez2 = b+x2;
        }
    }
    for (x2 = 0; x2 < 100000; x2++)
    {
        double tmp = n/((double)(b+x2)) - (double)a;
        x1 = (ll)tmp;
        x1 = max(x1-3,(ll)0);
        while ((a+x1)*(b+x2) < n)
              x1++;
        if (rez > (a+x1)*(b+x2) )
        {
        rez = min(rez,(a+x1)*(b+x2));
        rez1 = a+x1; rez2 = b+x2;
        }
    }
    cout << rez << endl << rez1 << " " << rez2 << endl;
    return 0;
}