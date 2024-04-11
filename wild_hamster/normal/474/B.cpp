#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <map>
#include <set>
#include <string>
#include <cstring>
#define tr 1000000007
#define mp make_pair
#define pb push_back
#define tA 555
#define tB 666
#define AorB 777
typedef long long ll;
using namespace std;
ll a[100500],used[1000],n,m,j,p,k1,k2,k3,k,i,cur;
string s,s1,s2;
char c;
int main()
{
    cin >> n;
    a[0] = 1;
    for (i = 0; i < n; i++)
    {
        cin >> k;
        a[i+1] = a[i] + k;
    }
    cin >> m;
    for (i = 0; i < m; i++)
    {
        cin >> k;
        ll tmp = upper_bound(a,a+n,k) - a;
        cout << tmp << endl;
    }
   return 0;
}