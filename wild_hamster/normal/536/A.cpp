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
ll v1,v2,x1,x2,x3,y1,t,y2,z,w,l,r,i,j,n,x,y,d,m,q,A,B;
ll a[400500],b[400500];
string s;
int main()
{
    cin >> A >> B >> n;
    for (i = 0; i < n; i++)
    {
        scanf("%d%d%d",&x,&y,&z);
        l = x; r = x+(ll)1e+12;
        if (A + (l-1)*B > y)
           cout << -1 << endl;
        else
        {
            while (l < r)
            {
             ll mid = (l+r+1)/2;
             if (max(A+(mid-1)*B,(((A+(x-1)*B+A+(mid-1)*B)*(mid-x+1))/2 - 1)/z + 1) <= y)
                l = mid;
             else
                 r = mid-1;
            }
            cout << r << endl;
        }
    }
    return 0;
}