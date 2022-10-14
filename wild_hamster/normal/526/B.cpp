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
typedef long long ll;
using namespace std;
ll x1,x2,y1,y2,x,y,z,w,l,r,i,j,n,a[100500],b[100500],k,k1,k2,d,m,q;
string s;
ll Abs(ll x)
{
 if (x < 0)
    return -x;
 return x;
}
int main()
{
    cin >> n;
    k = (1 <<(n+1)) - 1;
    for (i = 2; i <= k; i++)
        cin >> b[i];
    ll rez = 0;
    for (i = k; i >= 3; i -= 2)
    {
        a[i/2] = max(a[i]+b[i],a[i-1]+b[i-1]);
        rez += Abs(a[i]+b[i]-a[i-1]-b[i-1]); 
    }
    cout << rez << endl;
    return 0;
}