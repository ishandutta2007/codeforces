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
ll n,l,r,j,k,m,y,x,v,a[100505],b[1000],rez,h,i,cnt,last;
vector <ll> f1,f2;
int main()
{
    cin >> n;
    ll sum1 = 0, sum2 = 0;
    for (i = 0; i < n; i++)
    {
        cin >> x;
        if (x < 0)
        {
           f2.push_back(-x);
           sum2 += -x;
        }
        else
        {
            f1.push_back(x);
            sum1 += x;
        }
        if (x < 0) last = 2; else last = 1;
    }
    cnt = 0;
    for (i = 0; i < min(f1.size(),f2.size()); i++)
    {        
        if (f1[i] > f2[i]) 
        {
         cnt = 1;
         break;
        }
        else
        if (f2[i] > f1[i])
        {
         cnt = 2;
         break;
        }
    }
    if (sum1 > sum2) cout << "first" << endl; else
    if (sum1 < sum2) cout << "second" << endl; else
    if (cnt == 1) cout << "first" << endl; else
    if (cnt == 2) cout << "second" << endl; else
    if (last == 1) cout << "first" << endl; else
    cout << "second" << endl;
    return 0;
}