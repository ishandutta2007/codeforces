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
#include <time.h>
#include <stack>
#define mp make_pair
#define pb push_back
#define tA 555
#define tB 666
#define AorB 777
#define N 100499
#define PI 3.14159265358979323846
typedef long long ll;
using namespace std;
ll n,l,r,j,k,m,y,x,v,a[3005],rez,h,i,cnt;
bool lalka(int x)
{
     if (x < 0) x = -x;
     while (x)
     {
           if (x%10 == 8) return true;
           x/=10;
     }
     return false;
}
int main()
{
    int n, m;
    cin >> n;
    for (i = 1; i < 30; i++)
    if (lalka(n+i))
    {
     cout << i << endl;
     return 0;
    }
    return 0;
}