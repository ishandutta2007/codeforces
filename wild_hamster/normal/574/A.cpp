#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>
#include <deque>
#include <time.h>
#include <stack>
#include <stdio.h>
#include <map>
#include <set>
#include <string>
#include <fstream>
#include <queue>
#define mp make_pair
#define pb push_back
#define PI 3.14159265358979323846
#define MOD 1000000007
#define INF ((ll)1e+15)
#define x1 fldgjdflgjhrthrl
#define x2 fldgjdflgrtyrtyjl
#define y1 fldggfhfghjdflgjl
#define y2 ffgfldgjdflgjl
#define bull 500400
typedef long long ll;
using namespace std;
ll i,j,n,k,k1,k2,k3,m,x1,x,y,y1,x2,y2,x3,y3,h,z,l1,l2,l3;
string s1,s2,s3,s,t;
ll a[300500],mx[300500];
vector <ll> tree[100500];

int main()
{

   cin >> n;
   for (i = 0; i < n; i++)
       cin >> a[i];
   ll flag = 1;
   for (i = 1; i < n; i++)
       if (a[i] >= a[0])
          flag = 0;
   while (!flag)
   {
    k++;
    j = 1;
    ll max1 = a[0];
    for (i = 1; i < n; i++)
        if (a[i] >= max1)
        {
            max1 = a[i];
            j = i;
        }
    a[j]--;
    a[0]++;
    flag = 1;
    for (i = 1; i < n; i++)
       if (a[i] >= a[0])
          flag = 0;
   }
   cout << k << endl;
    return 0;
}