#include <iostream>
//#include <cmath>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <deque>
#include <time.h>
#include <stack>
#define mp make_pair
#define pb push_back
#define tA 555
#define tB 666
#define AorB 777
#define N 100499
#define PI 3.14159265358979323846
#define tr 1000000007
typedef long long ll;
using namespace std;
double x1,y1,x2,y2,x,y,n,m,q,i,j,k,k1,k2,l,a,b,c,d,e,f,g;
ll rez;
ll gcd(ll a, ll b)
{
          if (a%b == 0) return b;
          return gcd(b,a%b);
}
bool inlal(double n1, double n2, double n)
{
 if (n1 > n2) swap(n1,n2);
 if (n1 <= n && n <= n2) return true;
 return false;
}
int main()
{
    cin >> x1 >> y1;
    cin >> x2 >> y2;
    cin >> n;
    d = (y2-y1)/(x2-x1);
    e = y1-x1*(y2-y1)/(x2-x1);
    if (x2 == x1)
    {
       d = x1;
        for (i = 0; i < n; i++)
    {
        cin >> a >> b >> c;
        if (b == 0)
        {
              continue;
        } else
        {
        f = -a/b;
        g = -c/b;        
        x = x1;
        y = f*x+g;
        }
        if (inlal(x1,x2,x)&&inlal(y1,y2,y)) rez++;
    }      
    } else
    for (i = 0; i < n; i++)
    {
        cin >> a >> b >> c;
        if (b == 0)
        {
              x = -c/a;
              y = d*x+e;
        } else
        {
        f = -a/b;
        g = -c/b;        
        if (d-f == 0) continue;
        x = (g-e)/(d-f);
        y = d*x+e;
        }
        if (inlal(x1,x2,x)&&inlal(y1,y2,y)) rez++;
    }    
    cout << rez << endl;
    return 0;
}