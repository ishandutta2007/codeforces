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
#define INF ((ll)1e+18)
typedef long long ll;
using namespace std;
ll v1,v2,x1,x2,x3,y1,y2,z,w,l,r,i,j,n,x,y,d,m,q,A,B,sz;
ll a[1400500],b[400500];
vector <int> zz;
string s,t;
vector<int> z_function (string s) {
    int n = (int) s.length();
    vector<int> z (n);
    for (int i=1, l=0, r=0; i<n; ++i) {
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
    cin >> n >> m;
    cin >> t;
    sz = t.size();
    for (i = 0; i < n; i++)
        s.push_back('*');
    for (i = 0; i < m; i++)
    {
        scanf("%d",&a[i]);
        a[i]--;
    }
    sort(a,a+m);
    for (i = 0; i < m; i++)
    {
        x = a[i];
        for (j = x + sz - 1; j >= x; j--)
            if (s[j] == '*')
               s[j] = t[j-x];
            else
                break;
    }
    t.push_back('+');
    t.append(s);
    ll flag = 1;
    zz = z_function(t);
    for (i = 0; i < m; i++)
        if (zz[sz+1+a[i]] != sz)
           flag = 0;
    ll ans = 1;
    for (i = 0; i < s.size(); i++)
        if (s[i] == '*')
           ans = (ans*26)%MOD;
    if (!flag)
       cout << 0 << endl;
    else
        cout << ans << endl;    
    return 0;
}