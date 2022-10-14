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
ll n,m,j,p,a[100500],l,r,h,x,y,k1,k2,k3,k4,k5,k,i,w,rez,b[100500];
int main()
{
    cin >> n;
    k = 0;
    for (i = 0; i < n; i++)
    {
        cin >> x;
        if (x > 0) k += x;
           else if (k == 0) rez++;
                else k--;
    }
    cout << rez << endl;
   return 0;
}