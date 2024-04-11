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
typedef long long ll;
using namespace std;
int n,m,j,p,l,r,x,y,dp[1000500][7],k1,k2,k3,k4,k,i,cur,kokoko;
string s;
bool eq(int x, char c)
{
     if (c == '?') return true;
     if (x == 0 && c == '0') return true;
     if (x == 1 && c == '1') return true;
     if (x == 2 && c == '2') return true;
     if (x == 3 && c == '*') return true;
     return false;
}
int main()
{
   cin >> s;
   n = s.size();
   if (n == 1)
   {
         if (s[0] == '?') cout << 2 << endl;
         else if(s[0] == '0'||s[0] == '*') cout << 1 << endl;
         else cout << 0 << endl;
         return 0;
   }
   if (eq(1,s[0])&&eq(3,s[1])) dp[2][0]++;
   if (eq(3,s[0])&&eq(3,s[1])) dp[2][0]++;
   if (eq(3,s[0])&&eq(1,s[1])) dp[2][1] = 1;
   if (eq(3,s[0])&&eq(2,s[1])) dp[2][2] = 1;
   if (eq(0,s[0])&&eq(0,s[1])) dp[2][3] = 1;
   if (eq(0,s[0])&&eq(1,s[1])) dp[2][4] = 1;
   for (i = 2; i < n; i++)
   {
       if (eq(0,s[i])) dp[i+1][3] = dp[i][1]+dp[i][3];
       if (eq(1,s[i])) {dp[i+1][4] = dp[i][1]+dp[i][3]; dp[i+1][1] = dp[i][0];}
       if (eq(2,s[i])) dp[i+1][2] = dp[i][0];
       if (eq(3,s[i])) dp[i+1][0] = (dp[i][0]+dp[i][2])%tr+dp[i][4];
       for (j = 0; j < 5; j++)
           dp[i+1][j] %= tr;
   }
   ll rez = ((dp[n][0]+dp[n][1])%tr+dp[n][3])%tr;
   //if (n > 30) rez*=2;
   cout << rez << endl;
   return 0;
}