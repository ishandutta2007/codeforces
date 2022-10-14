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
#define INF ((ll)1e+9)
#define x1 fldgjdflgjhrthrl
#define x2 fldgjdflgrtyrtyjl
#define y1 fldggfhfghjdflgjl
#define y2 ffgfldgjdflgjl
#define bull 500400
typedef long long ll;
using namespace std;
ll i,j,n,k,k1,k2,k3,m,x1,y1,x2,y2,h,x,y;
string s1,s2,s3,s;
ll a[100500], used[100500];
vector <ll> f,g;
int main()
{

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //ios_base::sync_with_stdio(0);
    //printf("%.3f\n",15.5554);
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] < 1 || a[i] > n || used[a[i]] == 1)
           a[i] = 0;
        if (a[i] >= 1 && a[i] <= n)
           used[a[i]] = 1;
    }
    for (i = 0; i < n; i++)
        if (a[i] == 0)
           f.push_back(i);
    for (i = 1; i <= n; i++)
        if (!used[i])
           g.push_back(i);
    for (i = 0; i < f.size(); i++)
        a[f[i]] = g[i];
    for (i = 0; i < n; i++)
        cout << a[i] << " ";
    return 0;
}