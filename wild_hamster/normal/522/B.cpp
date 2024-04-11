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
#define MOD 1000000009
typedef long long ll;
using namespace std;
map <string, ll> used;
ll x,y,w,l,r,i,j,n,k,k1,k2,d,m,q,max1,a[205000],b[205000];
string s,s1,s2,s3;

int main()
{
    cin >> n;
    ll max1 = 0, max2 = 0;
    for (i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i];
        k1 += a[i];
        if (b[i] > max1)
        {
         max2 = max1;
         max1 = b[i];
        } else
        if (b[i] > max2)
        {
         max2 = b[i];
        }
    }
    
    for (i = 0; i < n; i++)
    if (b[i] == max1)
        cout << (k1-a[i])*max2 << " ";
    else
        cout << (k1-a[i])*max1 << " ";
    cout << endl;
    return 0;
}