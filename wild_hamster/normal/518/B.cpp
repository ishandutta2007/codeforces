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
ll x,y,l,r,i,j,n,k,k1,k2,d,m,letters[300],q,dr;
string s,t;
int main()
{
    //freopen("thimble.in","r",stdin);
    //freopen("thimble.out","w",stdout);
    cin >> s >> t;
    for (i = 0; i < t.size(); i++)
        letters[t[i]]++;
        
    for (i = 0; i < s.size(); i++)
        if (letters[s[i]] > 0 && s[i] != '#')
        {
         k1++;
         letters[s[i]]--;
         s[i] = '#';
        }
        
    for (i = 0; i < s.size(); i++)
        if (s[i] != '#')
        {
         if (letters[s[i] - 'a' + 'A'] > 0)
         {
          letters[s[i] - 'a' + 'A']--;
          k2++;
         }
         if (letters[s[i] - 'A' + 'a'] > 0)
         {
          letters[s[i] - 'A' + 'a']--;
          k2++;
         }
        }
    cout << k1 << " " << k2 << endl;
    return 0;
}