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
ll x,y,w,l,r,i,j,n,t,k,k1,k2,d,m,q,dr,a[100005],b[100005],c[100050];
string s;
vector <ll> f;
int main()
{
    cin >> n >> m >> t;
    if (n < m)
    {
          cout << "No solution" << endl;
          return 0;
    }
    for (i = 0; i < n; i++)
    {
        cin >> s;
        a[i] = (s[0]-'0')*36000 + (s[1]-'0')*3600 + (s[3]-'0')*600+
        (s[4]-'0')*60 + (s[6]-'0')*10 + s[7] - '0';
        c[a[i]]++;
    }
    ll sum = 0;
    ll flag = 0;
    for (i = 0; i < t; i++)
        sum += c[i];
    if (sum == m)
       flag = 1;
    for (i = t; i < 86400; i++)
    {
        sum += c[i] - c[i-t];
        if (sum >= m)
           flag = 1;
    }
    for (i = 86400 - t; i < 86400; i++)
    {
        sum -= c[i];
        if (sum >= m)
           flag = 1;
    }
    if (!flag)
    {
     cout << "No solution" << endl;
     return 0;
    }
    for (i = 0; i < m; i++)
    {
        b[i] = i+1;
    }
    for (i = m; i < n; i++)
    {
        ll tim = a[i] - t + 1;
        l = 0;
        for (j = 0; j < i; j++)
            if (a[j] >= tim)
            {
               l = b[j];
               break;
            }
        if (l == 0&&tim > a[i-1])
           l = b[i-1];
       if (b[i-1] - l < m-1)
          b[i] = b[i-1] + 1;
       else
           b[i] = b[i-1];
    }
    cout << b[n-1] << endl;
    for (i = 0; i < n; i++)
        cout << b[i] << endl;
    return 0;
}