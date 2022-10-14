#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>
#include <deque>
#include <stack>
#include <stdio.h>
#include <map>
#include <set>
#include <time.h>
#include <string>
#include <fstream>
#include <queue>
#include <bitset>
#include <cstdlib>
#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define pdd pair<double,double>
#define pii pair<ll,ll>
#define PI 3.14159265358979323846
#define MOD 1000000007
#define MOD2 (33LL+(ll)1e+17)
#define INF (1+(ll)1e+9)
#define x1 fldgjdflgjhrthrl
#define x2 fldgjdflgrtyrtyjl
#define y1 fldggfhfghjdflgjl
#define y2 ffgfldgjdflgjl
#define SQ 500400
#define CI 43534
#define N 228228
typedef long long ll;
using namespace std;
ll l,i,j,n,k,k1,k2,k3,m,x1,y1,x2,y2,x,y,r,z,max1,tx,flag;
string s,t;
ll a[100500];
map<string,ll> f;
map<string,ll>::iterator itr;
vector<pair<ll,string> > g;
int main()
{
   cin >> s;
   cin >> n;
   for (i = 0; i < n; i++)
   {
    string s1,s2;
    cin >> s1;
    string diya;
    cin >> diya;
    if (diya == "likes")
    {
        cin >> s2 >> t;
        s2 = s2.substr(0,s2.size()-2);
        if (s1 == s)
        {
            if (s2 != s)
               f[s2] -= 5;
        }
        if (s2 == s)
        {
            if (s1 != s)
               f[s1] -= 5;
        }
    } else
    if (diya == "commented")
    {
        cin >> t >> s2 >> t;
        s2 = s2.substr(0,s2.size()-2);
        if (s1 == s)
        {
            if (s2 != s)
               f[s2] -= 10;
        }
        if (s2 == s)
        {
            if (s1 != s)
               f[s1] -= 10;
        }
    } else
    {
        cin >> t >> s2 >> t;
        s2 = s2.substr(0,s2.size()-2);
        if (s1 == s)
        {
            if (s2 != s)
               f[s2] -= 15;
        }
        if (s2 == s)
        {
            if (s1 != s)
               f[s1] -= 15;
        }
    }
    if (s1 != s)
       f[s1] += 0;
    if (s2 != s)
       f[s2] += 0;
   }
   for (itr = f.begin(); itr != f.end(); itr++)
   {
    g.push_back(mp((*itr).second,(*itr).first));
   }
   sort(g.begin(),g.end());
   for (i = 0; i < g.size(); i++)
       cout << g[i].second << endl;
    return 0;
}