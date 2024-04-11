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
ll n,i,j,d,x,k,y,m,l,r,sum,a[1005][1005],rez;
string s;
int main()
{
    cin >> s;
    ll tmp = 0;
    for (i = 0; i < s.size(); i++)
        if ((s[i]-'0')%2 == 0)
           tmp = 1;
    if (tmp == 0)
    {
     cout << -1 << endl;
     return 0;
    }
    for (i = 0; i < s.size(); i++)
    {
        if ((s[i]-'0')%2 == 0&&s[i] < s[s.size()-1])
        {
         swap(s[i],s[s.size()-1]);
         cout << s << endl;
         return 0;
        }
    }
    for (i = s.size()-2; i >= 0; i--)
        if ((s[i]-'0')%2 == 0)
        {
         swap(s[i],s[s.size()-1]);
         cout << s << endl;
         return 0;
        }
    return 0;
}