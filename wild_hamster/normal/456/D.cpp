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
ll z[400500],rez,cnt,tmp,l,r,n,m,k,j,p,k1,k2,i;
ll a[500000],dp[500000];

string s;
struct node
{
  ll alph[26];
  ll parent;
  ll c[5];
  ll level;     
};
vector <ll> levels[100005];
node t[100500];
int main()
{
   cin >> n >> k;
   for (i = 0; i < 100500; i++)
   {
       for (j = 0; j < 26; j++)
           t[i].alph[j] = 0;
       for (j = 0; j < 5; j++)
           t[i].c[j] = 0;
   }
       
   t[0].level = 0;
   cnt = 1;
   ll maxlevel = 0;
   levels[0].push_back(0);
   for (i = 0; i < n; i++)
   {
      cin >> s;
      tmp = 0;
      for (j = 0; j < s.size(); j++)
      {
          if (t[tmp].alph[s[j]-'a'] == 0)
          {
           t[tmp].alph[s[j]-'a'] = cnt;
           t[cnt].level = t[tmp].level+1;
           maxlevel = max(maxlevel,t[tmp].level+1);
           t[cnt].parent = tmp;
           levels[t[tmp].level+1].push_back(cnt);
           tmp = cnt;
           cnt++;
          } else
          tmp = t[tmp].alph[s[j]-'a'];
      }
   }
   for (i = maxlevel; i >= 1; i--)
   {
       for (j = 0; j < levels[i].size(); j++)
       if (i % 2 == 1)
       {
        //  cout << levels[i][j] << endl;
          node cur = t[levels[i][j]];
          node par = t[t[levels[i][j]].parent];
          if (cur.c[1] == 0&&cur.c[2] == 0&&cur.c[3] == 0&&cur.c[4]==0) par.c[3] = 1; else
          if (cur.c[2] == 1) par.c[2] = 1; else
          if (cur.c[3] == 1&&cur.c[4] == 1) par.c[2] = 1; else
          if (cur.c[3] == 1) par.c[3] = 1; else
          if (cur.c[4] == 1) par.c[4] = 1; else
          par.c[1] = 1; 
          
          t[t[levels[i][j]].parent] = par;   
       } else
       {
        // cout << levels[i][j] << endl;
          node cur = t[levels[i][j]];
          node par = t[t[levels[i][j]].parent];
          if (cur.c[1] == 0&&cur.c[2] == 0&&cur.c[3] == 0&&cur.c[4]==0) par.c[4] = 1; else
          if (cur.c[1] == 1) par.c[1] = 1; else
          if (cur.c[3] == 1&&cur.c[4] == 1) par.c[1] = 1; else
          if (cur.c[3] == 1) par.c[3] = 1; else
          if (cur.c[4] == 1) par.c[4] = 1; else
          par.c[2] = 1;           
          t[t[levels[i][j]].parent] = par;  
       }       
   }
   node cur = t[0];
   node par = t[0];
   for (i = 1; i <= 4; i++)
       par.c[i] = 0;
          if (cur.c[1] == 0&&cur.c[2] == 0&&cur.c[3] == 0&&cur.c[4]==0) par.c[4] = 1; else
          if (cur.c[1] == 1) par.c[1] = 1; else
          if (cur.c[3] == 1&&cur.c[4] == 1) par.c[1] = 1; else
          if (cur.c[3] == 1) par.c[3] = 1; else
          if (cur.c[4] == 1) par.c[4] = 1; else
          par.c[2] = 1;           
          t[0] = par;  
   //for (i = 1; i <= 4; i++)
   //    cout << t[0].c[i] << " ";
   if (t[0].c[1] == 1||(t[0].c[3] == 1&&k%2 == 1))
   cout << "First" << endl;
   else cout << "Second" << endl;
//   cout << maxlevel << endl;
   return 0;
}