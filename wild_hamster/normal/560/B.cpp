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
#define MOD 1000000007LL
#define INF ((ll)1e+15)
#define x1 fldgjdflgjhrthrl
#define x2 fldgjdflgrtyrtyjl
#define y1 fldggfhfghjdflgjl
#define y2 ffgfldgjdflgjl
typedef long long ll;
using namespace std;
ll i,j,n,k,k1,k2,m,x,y,l,r;
ll a[10],b[10];
string s1,s2;
int main()
{
    cin >> n >> m;
    cin >> a[0] >> a[1];
    cin >> b[0] >> b[1];
    for (i = 0; i < 2; i++)
        for (j = 0; j < 2; j++)
            if ((a[i]+b[j] <= n && max(a[(i+1)%2],b[(j+1)%2]) <= m)||(a[i]+b[j] <= m && max(a[(i+1)%2],b[(j+1)%2]) <= n))
            {
                cout << "YES" << endl;
                return 0;
            }
    cout << "NO" << endl;
    return 0;
}