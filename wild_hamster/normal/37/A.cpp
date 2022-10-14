#include <iostream>
//#include <cmath>
/*#include <algorithm>
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
#define PI 3.14159265358979323846*/
#define MOD 1000000007
typedef long long ll;
using namespace std;
string s;
ll n,i,j,k1,k2,x,y,m,l,r,c,t,a[200005];

int main()
{
    cin >> n;
    k1 = 0; k2 = 0;
    for (i = 0; i < n; i++)
    {
        cin >> x;
        if (a[x] == 0)
           k1++;
        a[x]++;
        k2 = max(k2,a[x]);
    }
    cout << k2 << " " << k1 << endl;
    return 0;
}