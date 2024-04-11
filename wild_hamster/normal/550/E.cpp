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
ll i,j,n,p,m,k,k1,k2,y,x,xs,ys,zs,xf,yf,zf,x1,y1,x2,y2,x3,y3,kk,l,r,a[100005];
string s;
vector <string> f;
vector <ll> edges;
vector <pair<ll,ll> > ans;
int main()
{
    //cout << C(29,15) << endl;
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
        k += 1-a[i]%2;
    }
    if (n == 1)
    {
        if (a[0] == 0)
        {
           cout << "YES" << endl;
           cout << 0 << endl;
        } else
        cout << "NO" << endl;
        return 0;
    }
    if (n == 2)
    {
        if (a[0] == 1 && a[1] == 0)
        {
           cout << "YES" << endl;
           cout << "1->0" << endl;
        } else
        cout << "NO" << endl;
        return 0;
    }
    if (a[n-1] == 1 || (k == 2 && a[n-1] == 0 && a[n-2] == 0))
    {
        cout << "NO" << endl;
        return 0;
    }
    if (a[n-3] == 0 && a[n-2] == 0 && a[n-1] == 0)
    {
        if (n == 3)
        {
            cout << "YES" << endl;
           cout << "(0->0)->0" << endl;
           return 0;
        }
        cout << "YES" << endl;
        cout << "((";
        for (i = 0; i < n-3; i++)
        {
            if (i != 0)
               cout << "->";
            cout << a[i];
        }
        cout << ")->(0->0))->0" << endl;
        return 0;
    }
    if (a[n-2] == 0 && a[n-1] == 0)
    {
        cout << "YES" << endl;
        j = n-3;
        while (a[j] == 1 && j >= 0)
              j--;
        j--;
        cout << "(";
        if (j >= 0)
        {
            cout << "(";
           for (i = 0; i <= j; i++)
           {
            if (i != 0)
               cout << "->";
            cout << a[i];
           }
           cout << ")->";
        }
        cout << "(0->((";
        for (i = j+2; i < n-2; i++)
        {
            if (i!=j+2)
               cout << "->";
            cout << a[i];
        }
        cout << ")->0)))->0" << endl;
        return 0;
    }
    if (a[n-1] == 0)
    {
        cout << "YES" << endl;
        cout << "((";
        for (i = 0; i < n-2; i++)
        {
            if (i != 0)
               cout << "->";
            cout << a[i];
        }
        cout << ")->1)->0" << endl;
    }
    return 0;
}