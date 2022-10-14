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
#include <time.h>
#include <string>
#include <fstream>
#include <queue>
#include <bitset>
#include <cstdlib>
#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define pdd pair<double,double>
#define pii pair<ll,ll>
#define PI 3.14159265358979323846
#define MOD 1000000007
#define MOD2 (33LL+(ll)1e+17)
#define INF (1+(ll)1e+9)
#define x1 fldgjdflgjhrthrl
#define x2 fldgjdflgrtyrtyjl
#define y1 fldggfhfghjdflgjl
#define y2 ffgfldgjdflgjl
#define SQ 500400
#define CI 43534
#define N 228228
typedef long long ll;
using namespace std;
ll l,i,j,n,k,k1,k2,k3,m,x1,y1,x2,y2,x,y,r,z,max1,tx,flag,diameter;
vector <ll> divisors;
ll a[N], b[N];
string s;
ll c[105][300];
int main()
{
    //freopen("input.txt","r",stdin);
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> s;
        for (j = 0; j < s.size(); j++)
            c[i][s[j]] = 1;
        for (j = 'a'; j <= 'z'; j++)
            b[i] += c[i][j];
        a[i] = s.size();
    }
    ll ans = 0;
    for (i = 'a'; i <= 'z'; i++)
        for (j = i+1; j <= 'z'; j++)
        {
            ll sum = 0;
            for (k = 0; k < n; k++)
            {
                if (c[k][i] + c[k][j] == b[k])
                   sum += a[k];
            }
            ans = max(ans,sum);
        }
    cout << ans << endl;
    return 0;
}