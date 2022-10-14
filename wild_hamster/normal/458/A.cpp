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
#define tr 1000000007
#define mp make_pair
#define pb push_back
#define tA 555
#define tB 666
#define AorB 777
#define N 100499
typedef long long ll;
using namespace std;
ll n,m,j,p,l,r,x,y,k1,k2,k3,k4,k,i,w,rez,a[100500],s[100505],t[100505];
string s1,s2;
int main()
{
    cin >> s1 >> s2;
    n = s1.size();
    i = N;
    for (j = n-1; j >=0; j--)       
    if (s1[j] == '1')
            s[i--]++;
    else
        i--;   
        
    n = s2.size();
    i = N;
    for (j = n-1; j >=0; j--)       
    if (s2[j] == '1')
            t[i--]++;
    else
        i--;
    for (i = 0; i <= N; i++)       
        {
         if (s[i] > t[i] + 10)
         {
            cout << ">" << endl;
            return 0;
         }
         else
         if (t[i] > s[i] + 10)
         {
          cout << "<" << endl;
          return 0;
         }
         else
         {
          k = min(t[i],s[i]);
          t[i] -= k;
          s[i] -= k;
         }
          k = s[i] - '0';
          s[i+1] += k;
          s[i+2] += k;
          k = t[i] - '0';
          t[i+1] += k;
          t[i+2] += k;
        } 
        pair <ll,ll> x = mp(s[N],s[N+1]);
        pair <ll,ll> y = mp(t[N],t[N+1]);
        if (x > y) cout << ">" << endl;
        else if (x < y) cout << "<" << endl;
        else cout << "=" << endl;
   return 0;
}