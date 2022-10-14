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
typedef long long ll;
using namespace std;
ll i,j,n,p,m,k,k1,k2,y,x,xs,ys,zs,xf,yf,zf,x1,y1,x2,y2,x3,y3,ans,kk,l,r;
string s;
vector <string> f;
ll Abs(ll x)
{
    return x>0?x:-x;
}
string tostr(ll x)
{
    if (x == 0) return "0";
    string t;
    //t.clear();
    while (x)
    {
        t.push_back(x%10+'0');
        x/=10;
    }
    reverse(t.begin(),t.end());
    //cout << t << endl;
    return t;
}
int main()
{
    //cout << C(29,15) << endl;
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> s;
    n = s.size();
    for (i = 0; i < 125; i++)
        f.push_back(tostr(i*8));
    for (i = 0; i < 125; i++)
    {
        string t = f[i];
        m = t.size();
        j = 0;
        for (k = 0; k < n; k++)
        {
            if (s[k] == t[j])
               j++;
            if (j == m)
               break;
        }
        if (j == m)
        {
            cout << "YES" << endl;
            cout << i*8 << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}