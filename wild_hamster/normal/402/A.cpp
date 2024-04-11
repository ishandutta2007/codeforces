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
ll n,m,j,p,l,r,x,y,k1,k2,k3,k4,k,i,a,b,w,rez;

int main()
{
    cin >> k >> a >> b >> w;
    rez = 0;
    i = 0;
    while (rez < a)
    {
     if (b != 0)
     {
        rez += min(b,k-1)*w;
        b -= min(b,k-1);
     }  
     rez += w;
     i++;
    }
    cout << i << endl;
   return 0;
}