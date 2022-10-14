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
#define N 100499
typedef long long ll;
using namespace std;
ll n,i,j,d,m,x,y,p,k,max1,a,b,rez;
string s;
int main()
{
    cin >> a >> b;
    rez = -(ll)1e+15;
    if (a == 0)
    {
          cout << -b*b << endl;
          for (i = 0; i < b; i++)
              cout << "x";
          cout << endl;
          return 0;
    }
    for (i = 1; i <= a; i++)
    {
        x = b%(i+1);
        n = b/(i+1);
        ll tmp = 0;
        if (x == 0)
           tmp = (a-i+1)*(a-i+1)+i-1-n*n*(i+1);
        else
            tmp = (a-i+1)*(a-i+1)+i-1-(n+1)*(n+1)*x-(n)*(n)*(i+1-x);
        if (tmp > rez)
        {
                rez = tmp;
                j = i;
        }
    }    
    cout << rez << endl;
    //cout << j << endl;
    x = b%(j+1);
    n = b/(j+1);
    for (i = 0; i <= j; i++)
    {
        if (i < x)
        for (k = 0; k < n+1; k++)
            cout << "x";
        else
        for (k = 0; k < n; k++)
            cout << "x";
        if (i == 0)
           for (k = 0; k < a-j+1; k++)
               cout << "o";
        else
        if (i < j)
           cout << "o";
    }
    cout << endl;
    return 0;
}