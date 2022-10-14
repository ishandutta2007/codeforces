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
ll n,m,i,j,rez,a,b,c,x;
vector <ll> f;
bool iseq(ll x, ll sx)
{
     if (x > 999999999 || x < 1)
        return false;
     ll rez = 0;
     while (x)
     {
      rez += x%10;
      x/=10;
     }
     if (rez == sx)
        return true;
     return false;
}
int main()
{
    cin >> a >> b >> c;
    for (i = 1; i <= 81; i++)
    {
        ll tmp = 1;
        for (j = 1; j<= a; j++)
            tmp *= i;
        x = b*tmp + c;
        if (iseq(x,i))
           f.push_back(x);
    }
    cout << f.size() << endl;
    for (i = 0; i < f.size(); i++)
        cout << f[i] << " ";
    return 0;
}