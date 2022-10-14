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
string s;
ll n,i,j,k1,k2,k3,x,k,y,m,l,r,c,t,sum,xors[100500];
ll Abs(ll x)
{
 if (x < 0)
    return -x;
 return x;
}
int main()
{
    cin >> n >> m;
    for (i = 1; i <= 6; i++)
    {
        if (Abs(n-i) > Abs(m - i))
           k1++;
        else
        if (Abs(n-i) == Abs(m - i))
           k2++;
        else
            k3++;
    }
    cout << k3 << " " << k2 << " " << k1 << endl;
    return 0;
}