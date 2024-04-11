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
ll n,l,r,j,k,m,y,x,v,a[3005],b[10],rez,h,i,cnt;
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
vector <ll> f[5];
int main()
{
    cin >> n >> m;
    for (i = 0; i <= n; i++)
    {
        cout << i+m+1 << " ";
    }
    for (i = 0; i < m; i++)
        cout << m-i << " ";
    cout << endl;
    return 0;
}