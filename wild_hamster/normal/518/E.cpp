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
#define MOD 2000000007
typedef long long ll;
using namespace std;
ll x,y,l,r,i,j,n,k,k1,k2,d,m,a[200500],b[200500],q,dr;
ll f(string s)
{
 ll l = 0;
 ll pnt = 1;
 if (s[l] == '-')
 {
    pnt = -1;
    l++;
 }
 ll num = 0;
 for (int i = l; i < s.size(); i++)
     num = num*10 + s[i] - '0';
 num *= pnt;
 return num;
}
string s;
int main()
{
    //freopen("thimble.in","r",stdin);
    //freopen("thimble.out","w",stdout);
    cin >> n >> k;
    for (i = 0; i < n; i++)
    {
        cin >> s;
        if (s == "?")
           a[i] = MOD;
        else
            a[i] = f(s);
        //cout << a[i] << endl;
    }
    for (i = n; i < n+k; i++)
        a[i] = MOD + 1;
    for (i = 0; i < k; i++)
    {
        l = -1;
        ll start = -MOD;
        for (j = i; j < n+k; j+=k)
        if (a[j] != MOD)
        {
            r = (j-i)/k;
            if (a[j] - start < r - l)
            {
             cout << "Incorrect sequence" << endl;
             return 0;
            }
            ll dist = (r-l-1)/2;
            ll frst = min(max(-dist,start+1),a[j]-(r-l-1));
            for (int jj = l+1; jj < r; jj++)
                a[jj*k+i] = frst + jj - l - 1;
            l = r;
            start = a[j];
        }
    }
    for (i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
    return 0;
}