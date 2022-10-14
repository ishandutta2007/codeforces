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
typedef int ll;
using namespace std;
ll i,j,n,p,m,k,k1,k2,y,x,xs,ys,zs,xf,yf,zf,x1,y1,x2,y2,x3,y3,ans,kk,a[15][15];
string s;
vector <ll> A,B;
ll Abs(ll x)
{
    return x>0?x:-x;
}
int main()
{
    //cout << C(29,15) << endl;
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> s;
    n = s.size();
    for (i = 0; i < n-1; i++)
        if (s.substr(i,2) == "AB")
           A.push_back(i);
        else
        if (s.substr(i,2) == "BA")
           B.push_back(i);
    if (A.size() == 0 || B.size() == 0)
    {
        cout << "NO" << endl;
        return 0;
    }
    if (A.size() > 3 || B.size() > 3)
    {
        cout << "YES" << endl;
        return 0;
    }
    ll flag = 0;
    for (i = 0; i < A.size(); i++)
        for (j = 0; j < B.size(); j++)
            if (Abs(A[i] - B[j]) > 1)
               flag = 1;
    if (flag)
       cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}