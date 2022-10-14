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
ll x,y,w,l,r,i,j,n,k,k1,k2,d,m,q,max1,amnt,a[200500],b[100500];
string s,t;
int main()
{
    cin >> s >> t;
    r = 0; l = 108000;
    k = 0;
    for (i = 0; i < t.size(); i++)
    {
        if (t[i] == s[k])
           k++;
        if (k == s.size()) 
        {
         l = i;
         break;
        }
    }
    
    reverse(s.begin(),s.end());
    k = 0;
    for (i = t.size() - 1; i >= 0; i--)
    {
        if (t[i] == s[k])
           k++;
        if (k == s.size()) 
        {
         r = i;
         break;
        }
    }
    if (r < l)
       cout << 0 << endl;
    else
        cout << r-l << endl;
    return 0;
}