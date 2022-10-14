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
ll n,l,r,j,k,m,y,x,v,a[200505],b[200500],rez,h,i,cnt,last;
vector <ll> f1,f2;
int main()
{
    cin >> n;
    for (i = 0; i < n; i++)
        cin >> a[i];
    cin >> m;
    for (i = 0; i < m; i++)
        cin >> b[i];
    sort(a,a+n);
    sort(b,b+m);
    reverse(a,a+n);
    reverse(b,b+m);
    rez = n*2 - m*2;
    x = n*2;
    y = m*2;
    j = 0;
    for (i = 0; i < n; i++)
    {        
        while (b[j] >= a[i] && j < m)
              j++;
        if (i+1-j+n*2-m*2 >= rez)
        {
         rez = i+1-j+n*2-m*2;
         x = i+1+n*2;
         y = j+m*2;
        } 
    }
    cout << x << ":" << y << endl;
    return 0;
}