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
#define mp make_pair
#define pb push_back
#define PI 3.14159265358979323846
#define MOD 1000000007
typedef long long ll;
using namespace std;
ll n,i,j,d,x,k,y,m,t,l,r,sum,a[1005],b[1005],rez;
string s;
int main()
{
    cin >> m >> t >> r;
    for (i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    sort(b,b+m);
    rez = 0;
    if (t < r)
    {
          cout << -1 << endl;
          return 0;
    }
    for (i = 0; i < m; i++)
    {
        ll tmp = 0;
        for (j = b[i]+400-t+1; j <= b[i]+400; j++)
            tmp += a[j];
        rez += r-tmp;
        for (j = b[i]+400; j > b[i]+400 - (r-tmp); j--)
            a[j] = 1;
    }
    cout << rez << endl;
    return 0;
}