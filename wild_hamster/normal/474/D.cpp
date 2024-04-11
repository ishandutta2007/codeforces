#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <map>
#include <set>
#include <string>
#include <cstring>
#define tr 1000000007
#define mp make_pair
#define pb push_back
#define tA 555
#define tB 666
#define AorB 777
typedef long long ll;
using namespace std;
ll a[100500],dp[200500],used[1000],n,m,j,p,l,r,k1,k2,k3,k,i,cur;
string s,s1,s2;
char c;
int main()
{
    cin >> n >> k;
    dp[0] = 1;
    for (i = 0; i < 100005; i++)
    {
        dp[i+1] += dp[i];
        dp[i+1]%=tr;
        dp[i+k] += dp[i];
        dp[i+k]%=tr;
    }
    a[0] = 0;
    for (i = 1; i < 100005; i++)
        a[i] = (a[i-1] + dp[i])%tr;
    for (i = 0; i < n; i++)
    {
        cin >> l >> r;
        cout << (a[r] - a[l-1] + tr)%tr << endl;
    }
   return 0;
}