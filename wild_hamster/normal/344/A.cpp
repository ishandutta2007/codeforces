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
ll a[100500],c[300],dp[100500][305],z,cnt,tmp,e,l,r,n,m,x,y,k,j,p,k1,k2,i,cur,rez;
vector <ll> f[100500];
string s[200000];
ll Abs(ll x)
{
 if (x < 0) return -x;
 return x;
}

int main()
{
    cin >> n;
    for (i = 0; i < n; i++)
        cin >> s[i];
    rez = 1;
    for (i = 0; i < n-1; i++)
        if (s[i][1] == s[i+1][0]) rez++;
    cout << rez << endl;
   return 0;
}