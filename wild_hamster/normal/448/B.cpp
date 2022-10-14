#include <iostream>
//#include <cmath>
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
ll a[100500],b[100500],z,cnt,tmp,l,x1,x2,x3,x4,x5,x6,r,n,m,x,y,k,j,p,k1,k2,i,cur;
ll rez;
string s,t,s2;
ll Abs(ll x)
{
 if (x < 0) return -x;
 return x;
}

int main()
{
   cin >> s >> t;
   z = 1;
   for (i = 0; i < s.size(); i++)
       a[s[i]]++;
   for (i = 0; i < t.size(); i++)
   {
       a[t[i]]--;
       if (a[t[i]] < 0) z = 0;
   }
   if (!z) cout << "need tree" << endl;
      else
   {
   ll z1 = 0;
   j = 0;
    for (i = 0; i < s.size(); i++)
    {
        if (s[i] == t[j]) j++;
    }
   if (j == t.size()) cout << "automaton" << endl;
      else if (t.size()==s.size())
           cout << "array" << endl;
      else cout << "both" << endl;
   }
   return 0;
}