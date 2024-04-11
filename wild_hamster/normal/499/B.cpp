#include <iostream>
//#include <cmath>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <deque>
#include <time.h>
#include <stack>
#define mp make_pair
#define pb push_back
#define tA 555
#define tB 666
#define AorB 777
#define N 100499
#define PI 3.14159265358979323846
#define tr 1000000007
typedef long long ll;
using namespace std;
ll x1,y1,x2,y2,x,y,n,m,q,i,j,k,k1,k2,l,a[100500],mt[50000],used[50000];
string s1,s2;
map <string,string> f;
ll gcd(ll a, ll b)
{
          if (a%b == 0) return b;
          return gcd(b,a%b);
}
int main()
{
    cin >> n >> m;
    for (i = 0; i < m; i++)
    {
        cin >> s1 >> s2;
        if (s1.size() <= s2.size())
        {
         f[s1] = s1;
         f[s2] = s1;
        } else
        {
            f[s1] = s2;
            f[s2] = s2;  
        }
    }
    for (i = 0; i < n; i++)
    {
        cin >> s1;
        cout << f[s1] << " ";
    }
    return 0;
}