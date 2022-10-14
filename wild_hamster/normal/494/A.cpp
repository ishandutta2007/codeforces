#include <iostream>
#include <cmath>
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
typedef long long ll;
using namespace std;
ll t,x,y,n,m,q,i,j,k,rez,a[1000100],last;
string s,s2;
vector <ll> f;
int main()
{
    cin >> s;
    n = s.size();
    ll flag = 1;
    for (i = 0; i < s.size(); i++)
    {
        if (s[i] == '(') x++;
        else if (s[i] == ')') y++;
        else 
        {
             k++;
             last = i;
        }
    }
    if (x < y+k)
    {
          cout << -1 << endl;
          return 0;
    }
    for (i = 0; i < n; i++)
        if ((s[i] == '#'&&i!=last)||s[i] == ')')
        {
         s2.push_back(')');
         if (s[i] == '#') 
         {
          y++;
          f.push_back(1);
         }
        } else
        if (s[i] == '(')
        {
         s2.push_back('(');
        } else
        {
         for (j = 0; j < x-y; j++)
             s2.push_back(')');
         f.push_back(x-y);
        }
    x = 0; y = 0;
    for (i = 0; i < s2.size(); i++)
    {
        if (s2[i] == ')') x++;
           else y++;
        if (x > y) flag = 0;
    }
    if (flag == 0) cout << -1 << endl;
       else 
    {
    for (i = 0; i < f.size(); i++)
        cout << f[i] << endl;
    }
	return 0;
}