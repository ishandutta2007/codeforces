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
#define x1 flkdgl
#define x2 fdgdfgh
#define y1 lfdkgl
#define y2 lhkgflhkf
typedef int ll;
using namespace std;
ll hr,hb,wr,wb,x1,x2,y1,y2,x,y,w,l,r,i,j,n,a[3000500],b[3000500],k,k1,k2,d,m,q;
char s[1005000];
vector <ll> z;
vector<ll> z_function (string s) {
    ll n = (ll) s.length();
    vector<ll> z (n);
    for (ll i=1, l=0, r=0; i<n; ++i) {
        if (i <= r)
            z[i] = min (r-i+1, z[i-l]);
        while (i+z[i] < n && s[z[i]] == s[i+z[i]])
            ++z[i];
        if (i+z[i]-1 > r)
            l = i,  r = i+z[i]-1;
    }
    return z;
}
int main()
{
    cin >> n >> k;
    ll ans = 0;
    scanf("%s",s);
    z = z_function(s);
    //for (i = 0; i < n; i++)
    //    cout << z[i];
    //cout << endl;
    for (i = 0; i < 1000500; i++)
        z.push_back(-1);
    for (i = n-1; i >= 1; i--)
    {
        ll tmp = 1;
        ll flag = 1;
        for (j = i; j < n; j+=i)
        {
            if (tmp == k)
               break;
            if (z[j] < i)
            {
             flag = 0;
             break;
            }
            tmp++;
        }
        if (!flag || tmp != k) continue;
        if (i*k < n)
        for (j = 0; j <= min(z[i*k],i); j++)
        {
        if (j+i*k > n)
           break;
        j += max(b[j+i*k]-1,0);
        a[j+i*k] = 1;
        b[j+i*k] = min(z[i*k],i) - j + 1;
        ans++;
        }
        if (i*k == n)
            a[n] = 1;
    }
    if (k == 1)
    for (i = 1; i <= n; i++)
        a[i] = 1;
    for (i = 1; i <= n; i++)
        printf("%d",a[i]);
    cout << endl;
    return 0;
}