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
#define mp make_pair
#define pb push_back
#define tA 555
#define tB 666
#define AorB 777
#define N 100499
#define PI 3.14159265358979323846
typedef long long ll;
using namespace std;
ll n,l,r,i,j,k,x1,x2,y1,y2,m,y,v,a[10],flag,rez;
string s;
ll Abs(ll x)
{
 if (x < 0) return -x;
 return x;
}
int main()
{
    cin >> n >> m;
    cin >> s;
    if (m > n/2)
    {
          m = n-m+1;
    }
    m--;
    ll flag = 1;
    r=l=m;
    for (i = 0; i < n/2; i++)
    {
        if (flag&&s[i]!=s[n-i-1])
        {
           l = i;
           flag = 0;
        }        
    }
    flag = 1;
    for (i = n/2-1; i >= 0; i--)
    if (flag&&s[i]!=s[n-i-1])
        {
           r = i;
           flag = 0;
        }   
    rez = 0;
    for (i = 0; i < n/2; i++)
    {
        rez += min((s[i]-s[n-i-1]+26)%26,(-s[i]+s[n-i-1]+26)%26);
    } 
    cout << rez+r-l+min(Abs(m-r),Abs(m-l)) << endl;
    return 0;
}