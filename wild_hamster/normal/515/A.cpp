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
ll x,y,w,l,r,i,j,n,k,k1,k2,d,m;
string s,s1;
ll Abs(ll x)
{
 if (x < 0)
    return -x;
 return x;
}
int main()
{
    cin >> n >> m >> k;
    n = Abs(n);
    m = Abs(m);
    if (n+m > k||(n+m)%2!=k%2)
       cout << "No" << endl;
    else
        cout << "Yes" << endl;
    return 0;
}