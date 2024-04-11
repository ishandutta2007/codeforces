#include <omp.h>
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
#define mp make_pair
#define pb push_back
#define PI 3.14159265358979323846
#define MOD 1000000007
typedef long long ll;
using namespace std;
ll k,oz,w,l,r,i,j,k1,k2,dr,n,m, qt, qh, md,  x, y, p, a[1005][1005], c[30];
string s,t;
vector <ll> ans;
int main()
{
    //freopen("race.in","r",stdin);
    //freopen("race.out","w",stdout);
    cin >> n;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            cin >> a[i][j];
    for (i = 0; i < n; i++)
    {
        ll flag = 1;
        for (j = 0; j < n; j++)
        {
            if (a[i][j] == 1 || a[i][j] == 3)
               flag = 0;
            if (a[j][i] == 2 || a[j][i] == 3)
               flag = 0;
        }
        if (flag)
           ans.push_back(i+1);
    }
    cout << ans.size() << endl;
    for (i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    cout << endl;
    return 0;
}