#include <iostream>
//#include <cmath>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <map>
#define tr 1000000007
#define mp make_pair
typedef long long ll;
using namespace std;
ll x1,y1,x2,y2,x3,y3,x4,y4;
ll Abs(ll x)
{
 if (x < 0) return - x; else return x;
}
int main()
{
    cin >> x1 >> y1 >> x2 >> y2;
    if (x1 == x2)
       cout << x1+Abs(y1-y2) << " " << y1 << " " << x2+Abs(y1-y2) << " " << y2 << endl;
    else
    if (y1 == y2)
       cout << x1 << " " << y1+Abs(x1-x2) << " " << x2 << " " << y2+Abs(x1-x2) << endl;
    else
    {
        if (Abs(x1-x2)==Abs(y1-y2))
        cout << x2 << " " << y1 << " " << x1 << " " << y2 << endl;
             else
        cout << -1 << endl;
    }
    return 0;
}