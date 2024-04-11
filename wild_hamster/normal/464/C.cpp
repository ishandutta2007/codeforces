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
ll j,x,y,n,m,cnt,i,sixs[10],b[30];
ll val[300],len[300];
vector <string> s;
string k,r;
ll x10(ll x)
{
 if (x == 0) return 1;
  ll tmp = x10(x/2);
 if (x%2)
    return (((10LL*tmp)%tr)*tmp)%tr;
 return (tmp*tmp)%tr;
}
int main()
{
   // cout << x10(1000000006) << endl;
    cin >> k;
    r = "0->";
    r.append(k);
    //cout << r << endl;
    s.push_back(r);
    cin >> n;

    for (i = 0; i < n; i++)
        {
             cin >> k;
             s.push_back(k);
        }
    for (i = '0'; i <= '9'; i++)
    {
        val[i] = i - '0';
        len[i] = 1;
    }
    //cout << s.size() << endl;
    for (i = n; i >= 0; i--)
    {
        ll l=0,v=0;
        for (j = 3; j < s[i].size(); j++)
        {
            
            l = (l+len[s[i][j]])%(tr-1);
            if (j > 3) v = ((x10(len[s[i][j]])*v)%tr + val[s[i][j]])%tr;
            else v = val[s[i][j]];
        }
        len[s[i][0]] = l;
        val[s[i][0]] = v;
    }
    cout << val['0'] << endl;
    return 0;
}