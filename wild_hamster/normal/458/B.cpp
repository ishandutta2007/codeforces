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
ll n,m,j,p,l,r,x,y,k1,k2,k3,k4,k,i,w,rez,rez1,rez2,a[100500],b[100500];
string s1,s2;
int main()
{
    ll suma = 0,sumb = 0;
    cin >> n >> m;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
        suma += a[i];
    }
    for (j = 0; j < m; j++)
    {
        cin >> b[j];
        sumb += b[j];
    }
    sort(b,b+m);    
    rez1 = suma*m;   
   // cout << rez1 << endl;
    for (i = 0; i < m-1; i++)
        if (b[i] > suma) break;
    else
        rez1 += b[i] - suma;
        
    sort(a,a+n);    
    rez2 = sumb*n;
    //cout << rez2 << endl;
    for (i = 0; i < n-1; i++)
        if (a[i] > sumb) break;
    else
        rez2 += a[i] - sumb;
    cout << min(rez1, rez2) << endl;
   return 0;
}