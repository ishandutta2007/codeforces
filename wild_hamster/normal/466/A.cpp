#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <map>
#include <set>
#define tr 1000000007
#define mp make_pair
typedef long long ll;
using namespace std;
ll k,j,x,y,n,m,cnt,d,i,b,a,inva[100600],bd[100500];
string s;
int main()
{
    cin >> n >> m >> a >> b;
    if (n <= m)
       cout << min(n*a,b) << endl; else
    if (a*m >= b)
       cout << (n/m)*b + min((n%m)*a,b) << endl;
    else
        cout << n*a << endl;
    return 0;
}