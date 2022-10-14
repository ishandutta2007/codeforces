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
#include <string>
#include <fstream>
#include <queue>
#include <bitset>
#define mp make_pair
#define pb push_back
#define PI 3.14159265358979323846
#define MOD 998244353
#define INF ((ll)1e+9)
#define x1 fldgjdflgjhrthrl
#define x2 fldgjdflgrtyrtyjl
#define y1 fldggfhfghjdflgjl
#define y2 ffgfldgjdflgjl
#define SQ 500400
#define CI 43534
typedef int ll;
using namespace std;

ll l,i,j,n,k,k1,k2,k3,m,x1,y1,x2,y2,r,x,y,z,max1;
string s1,s2,s3;
ll a[305305];
vector <ll> ans;
multiset <ll> f;
multiset <ll>::iterator itr;
ll gcd(ll a, ll b)
{
    if (b == 0)
       return a;
    return gcd(b,a%b);
}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
   cin >> n;
   for (i = 0; i < n*n; i++)
   {
    scanf("%d",&x);
    f.insert(x);
   }
   for (i = 0; i < n; i++)
   {
    itr = f.end();
    itr--;
    ll x = *itr;
    f.erase(itr);
    for (j = 0; j < ans.size(); j++)
    {
        ll y = gcd(ans[j],x);
        itr = f.find(y);
        f.erase(itr);
        itr = f.find(y);
        f.erase(itr);
    }
    ans.push_back(x);
   }
   for (i = 0; i < n; i++)
       cout << ans[i] << " ";
   cout << endl;
    return 0;
}