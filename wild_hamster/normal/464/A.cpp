#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <map>
#include <set>
#define tr 1000000007
#define mp make_pair
typedef long long ll;
using namespace std;
ll j,x,y,n,m,k,i;
string s;
bool increm(int n)
{
    if (s[n-1] >= (char)((int)'a'+m-1))
       {
       if (n == 1) return true;
        s[n-2] = (char)((int)s[n-2]+1);
        s[n-1] = 'a';
        return true;
       } 
    else
    {
        s[n-1] = (char)((int)s[n-1] + 1);
        return false;
    }
}
int main()
{
    cin >> n >> m;
    cin >> s;
    if (n == 1 && s[0] == (char)((int)'a'+m-1) )
    {
          cout << "NO" << endl;
          return 0;
    }
    ll tmp = 1;
    for (i = n - 1; i >= 0; i--)
    {
        if (s[i] == (char)((int)'a'+m))
        {
           increm(i+1);
           continue;
        }
        bool z = true;
        while (1) {
                  if (tmp)
                  {
                          tmp = 0;
                          if (increm(i+1)) break;
                  }
                  if (!((i > 0 && s[i] == s[i-1]) || (i > 1 && s[i] == s[i-2])))
                  {
                           x = i;
                           z = false;
                           break;
                  }
                  if (increm(i+1)) break;
              }
        if (!z) break;
        
    }
    if (s[0] > (char)((int)'a'+m-1))
    {
       cout << "NO" << endl;
       return 0;
    }
    for (i = x+1; i < n; i++)
    {
        for (j = (int)'a'; j < (int)'a'+m; j++)
            if ((i > 0 && (char)j != s[i-1]) && (i > 1 && (char)j != s[i-2]))
            {
                   s[i] = (char)j;
                   break;
            }
    }
    cout << s << endl;
    return 0;
}