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
ll n,l,r,j,k,m,y,x,v,a[100505],b[1000],rez,h,i,cnt;
string s1,s2,s3,s4;
int main()
{
    cin >> s1 >> s2;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> x >> s3 >> y >> s4;
        if (s3 == "a")
        {
        if (a[y] == 2) continue;
        if (a[y] == 1||(a[y] == 0&& s4 == "r"))
        {
         a[y] = 2;
         cout << s2;
         cout << " " << y << " " << x << endl;
        }
        if (a[y] == 0 && s4 == "y")
          a[y] = 1;
        } else
        {
        if (b[y] == 2) continue;
        if (b[y] == 1||(b[y] == 0&& s4 == "r"))
        {
         b[y] = 2;
         cout << s1;
         cout << " " << y << " " << x << endl;
        }
        if (b[y] == 0 && s4 == "y")
          b[y] = 1;
        }
    }
    return 0;
}