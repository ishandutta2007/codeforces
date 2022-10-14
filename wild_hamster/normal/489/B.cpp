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
#define mp make_pair
#define pb push_back
#define tA 555
#define tB 666
#define AorB 777
#define N 100499
#define PI 3.14159265358979323846
typedef long long ll;
using namespace std;
ll n,l,r,j,k,m,y,x,v,a[100005],b[100005],flag,rez,h,i,cnt,used[100005];
ll Abs(ll x)
{
          if (x < 0) return -x;
          return x;
}
int main()
{
    cin >> n;
    for (i = 0; i < n; i++)
        cin >> a[i];
    cin >> m;
    for (j = 0; j < m; j++)
        cin >> b[j];
    sort(a,a+n);
    sort(b,b+m);
    for (i = n-1; i >= 0; i--)
        for (j = m-1; j >= 0; j--)
            if (Abs(a[i]-b[j]) < 2)
            {
             rez++;
             b[j] = -15;
             break;
            }
    cout << rez << endl;
    return 0;
}