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
ll x,y,w,l,r,i,j,n,k,k1,k2,d,m,q,dr,a[200005];
string s;
int main()
{
    cin >> n;
    cin >> s;
    for (i = 0; i < n; i++)
    {
        if (s[i] == 'C') a[0]++;
        if (s[i] == 'T') a[1]++;
        if (s[i] == 'A') a[2]++;
        if (s[i] == 'G') a[3]++;
    }
    ll max1 = 0;
    ll rez = 1;
    for (i = 0; i < 4; i++)
        max1 = max(max1,a[i]);
        
    for (i = 0; i < 4; i++)
        if (max1 == a[i])
           k++;
           
    for (i = 0; i < n; i++)
        rez = ((ll)rez*k)%MOD;
        
    cout << rez << endl;
    return 0;
}