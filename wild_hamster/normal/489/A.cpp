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

int main()
{
    cin >> n;
    for (i = 0; i < n; i++)
        cin >> a[i];
    cout << n << endl;
    for (i = 0; i < n; i++)
    {
        ll max1 = -(ll)1e+18;
        ll tmp = 0;
        for (j = 0; j < n-i; j++)
        {
            if (a[j] > max1)
            {
                     max1 = a[j];
                     tmp = j;
            }
        }
        swap(a[tmp],a[n-i-1]);
        cout << tmp << " " << n-i-1 << endl;
    }
    return 0;
}