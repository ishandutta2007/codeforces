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
#define x1 flkdgl
#define x2 fdgdfgh
#define y1 lfdkgl
#define y2 lhkgflhkf
#define INF ((ll)1e+18)
typedef long long ll;
using namespace std;
ll k,v1,v2,z,w,l,r,i,j,n,x1,x2,y1,y2,x,y,d,m,q,sz,a[100500];
string s, t;
int main()
{
    cin >> n;
    cin >> s >> t;
    ll tmp = 0;
    for (i = 0; i < n; i++)
        if (s[i] != t[i])
        {
           a[tmp++] = i;
        }
    ll flag = 0;
    if (tmp == 1)
       flag = 2;
    else
    {    
     flag = 0;    
     l = 0; r = 0;
     k = 0;
     for (i = 0; i < n; i++)
         if (s[i] != t[i])
         {
            l = i;
            break;
         }
     if (s[l] == t[l+1])
     {
      string s1,s2;
      for (i = l; i < n; i++)
          s1.push_back(s[i]);
      for (i = l; i < n-1; i++)
          s2.push_back(t[i+1]);
      i = 0; j = 0;
      swap(s2,s1);
      while (i < s2.size())
      {
       if (s2[i] == s1[j])
       {
        i++;
        j++;
       }
       else
       i++;
       if (j == s1.size())
          break;
      }
      if (j == s1.size())
         flag++;
     }
     
     swap(s,t);
     if (s[l] == t[l+1])
     {
      string s1,s2;
      for (i = l; i < n; i++)
          s1.push_back(s[i]);
      for (i = l; i < n-1; i++)
          s2.push_back(t[i+1]);
      i = 0; j = 0;
      swap(s2,s1);
      while (i < s2.size())
      {
       if (s2[i] == s1[j])
       {
        i++;
        j++;
       }
       else
       i++;
       if (j == s1.size())
          break;
      }
      if (j == s1.size())
         flag++;
     }
    }
    cout << flag << endl;
    return 0;
}