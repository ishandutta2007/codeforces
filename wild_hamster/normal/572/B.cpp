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
#include <fstream>
#include <queue>
#define mp make_pair
#define pb push_back
#define PI 3.14159265358979323846
#define MOD 1000000007
#define INF ((ll)1e+15)
#define x1 fldgjdflgjhrthrl
#define x2 fldgjdflgrtyrtyjl
#define y1 fldggfhfghjdflgjl
#define y2 ffgfldgjdflgjl
#define bull 500400
typedef long long ll;
using namespace std;
ll i,j,n,k,k1,k2,k3,m,x1,x,y,y1,x2,y2,x3,y3,h,z,l1,l2,l3;
string s1,s2,s3,s,t;
map <ll,ll> S, B;
map<ll,ll>::iterator itr;
ll gcd(ll a, ll b)
{
    if (a%b == 0)
       return b;
    return gcd(b,a%b);
}
int main()
{

   // freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);
    cin >> n >> m;
    for (i = 0; i < n; i++)
    {
        char c;
        cin >> c >> k1 >> k2;
        if (c == 'B')
           B[k1] += k2;
        else
            S[k1] += k2;
    }
    k = m;
    vector <pair<ll,ll> > f;
    while (k && !S.empty())
    {

          itr = S.begin();
          f.push_back(mp(itr->first,itr->second));
        k--;
        S.erase(itr);
    }
    reverse(f.begin(),f.end());
    for (i = 0; i < f.size(); i++)
        cout << "S " << f[i].first << " " << f[i].second << endl;
    k = m;
    while (k && !B.empty())
    {

          itr = B.end();
         itr--;
        cout << "B " << itr->first << " " << itr->second << endl;
        k--;
        B.erase(itr);
    }
    return 0;
}