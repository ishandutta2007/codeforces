#include <iostream>
//#include <cmath>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <map>
#include <set>
#define tr 1000000007
#define mp make_pair
typedef long long ll;
using namespace std;
ll sum,x1,x2,a1,b1,k,j,x,y,n,m,rez1,rez2,rez,cnt,d,i,b,a[600000],part[600000];
vector <ll> f,g;
string s;
int main()
{
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    if (sum%3 != 0)
    {
     cout << 0 << endl;
     return 0;
    }
    part[0] = 0;
    for (i = 0; i < n; i++)
        part[i+1] = part[i] + a[i];
    for (i = 0; i < n; i++)
        if (part[i+1] == sum/3) 
        f.push_back(i);
    for (i = 0; i < n; i++)
        if (part[n] - part[i] == sum/3)
        g.push_back(i);
    rez = 0;
   /* for (i = 0; i < f.size(); i++)
        cout << f[i] << " ";
        cout << endl;
    for (i = 0; i < g.size(); i++)
        cout << g[i] << " ";
        cout << endl;*/
    for (i = 0; i < f.size(); i++)
        rez += g.end() - upper_bound(g.begin(),g.end(),f[i]+1);
    cout << rez << endl;
    //system("pause");
    return 0;
}