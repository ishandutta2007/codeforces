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
ll x,y,l,r,i,j,n,k,k1,k2,d,m,a[100500],b[100500],q,dr;
string s,t;
int main()
{
    //freopen("thimble.in","r",stdin);
    //freopen("thimble.out","w",stdout);
    cin >> n >> k >> y;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
        b[a[i]] = i;
    }
    ll rez = 0;
    for (i = 0; i < k; i++)
    {
        cin >> x;
        rez += b[x]/y + 1;
        if (b[x] > 0)
        {
         l = b[x] - 1;
         swap(a[l],a[l+1]);
         b[a[l]] = l;
         b[a[l+1]] = l+1;
        }
    }
    cout << rez << endl;
    return 0;
}