#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cstring>
#include <stdio.h>
#include <sstream>
#include <time.h>
using namespace std;
typedef long long ll;
typedef double db;
#define tr 1000000007
#define pb push_back
#define mp make_pair
#define fi first
#define se second
vector <ll> azaza;
ll max1,i,j,k,x,n,y,lp,rp,p,l,r,ql,qr,m,M_cnt,k1,k2,ost,ur,a[300500],b[100500];
int main()
{
string s, s1;
cin >> s;
s.append("WUB");
i = 0;
k = 0;
while (i < s.size() )
    {
         
         if (s[i]=='W'&&s[i+1]=='U'&&s[i+2]=='B') 
            {
            i+=3;
            if (s1.size()) 
               {
               if (k == 0) cout << s1;
               else cout << " " << s1;
               k = 1;
               s1.clear();
               }
            }
         else 
         {
         s1.pb(s[i]);
         i++;
         }
    }
return 0;
}