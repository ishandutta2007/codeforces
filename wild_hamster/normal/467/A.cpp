#include <iostream>
//#include <cmath>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <map>
#include <set>
#define tr 1000000007
#define mp make_pair
typedef long long ll;
using namespace std;
ll sum,x1,x2,a1,b1,k,j,x,y,n,m,rez1,rez2,rez,cnt,d,i,b,dp[2005][2005],a[600000];
vector <ll> f,g;
string s;

int main()
{
    cin >> n;
    rez = 0;
    for (i = 0; i < n; i++)
    {
        cin >> x >> y;
        if (x+2 <= y)
           rez++;
    }
    cout << rez << endl;
    return 0;
}