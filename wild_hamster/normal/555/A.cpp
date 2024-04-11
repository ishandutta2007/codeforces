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
ll ans,x,i,j,n,k,k1,k2,m,d,v,y,z,a[155500],b[155000];
vector <ll> f;
int main()
{
    cin >> n >> m;
    ans = m-1;
    for (i = 0; i < m; i++)
    {
        cin >> x;
        f.clear();
        for (j = 0; j < x; j++)
        {
            cin >> y;
            f.push_back(y);
        }
        ll flag = 0;
        reverse(f.begin(),f.end());
        if (f[x-1] == 1)
        while (f[x-1] + 1 == f[x-2] && x >= 2)
              x--;
        ans += (x-1)*2;
        

    }
    cout << ans << endl;
    return 0;
}