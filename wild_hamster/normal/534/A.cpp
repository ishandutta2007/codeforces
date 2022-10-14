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
ll a[200500],x1,x2,y1,t,y2,z,w,l,r,i,j,n,x,y,d,m,q;
string s;

int main()
{
    cin >> n;
    if (n == 1)
       cout << 1 << endl << 1 << endl;
    else
    if (n == 2)
       cout << 1 << endl << 1 << endl;
    else
    if (n == 3)
       cout << 2 << endl << 1 << " " << 3 << endl;
    else
    if (n == 4)
       cout << 4 << endl << 2 << " " << 4 << " " << 1 << " " << 3 << endl;
    else
    {
        cout << n << endl;
        for (i = 1; i <= n; i += 2)
            cout << i << " ";
        for (i = 2; i <= n; i+=2)
            cout << i << " ";
        cout << endl;
        
    }
    return 0;
}