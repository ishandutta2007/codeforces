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
#include <assert.h>
#include <list>
#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define pdd pair<double,double>
#define pii pair<ll,ll>
#define PI 3.14159265358979323846
#define MOD 1000000007
#define MOD2 1000000009
#define INF ((ll)1e+18)
#define x1 fldgjdflgjhrthrl
#define x2 fldgjdflgrtyrtyjl
#define y1 fldggfhfghjdflgjl
#define y2 ffgfldgjdflgjl
#define N 131072
#define SUM 377
#define MAG 33554431
#define RED 0
#define BLUE 1
#define ALP 26
typedef long long ll;
typedef long double ld;
using namespace std;
ll i,j,n,k,l,m,tot, flag,r,ans,z, K,sx,sy,x;
string s,t,s1;
ll pre[100500], a[100500];
int main() {
	//freopen("input.txt","r",stdin);
 	//freopen("output.txt","w",stdout);
    for (i = 0; i < 20000; i++)
    {
        for (j = 0; j <= 14; j++)
            if ((i&(1<<j))!=0)
                pre[i]++;
    }
    cin >> n >> k;
    for (i = 0; i < n; i++)
    {
        cin >> x;
        a[x]++;
    }
    if (k == 0)
    {
        for (i = 0; i <= 10000; i++)
            ans += a[i]*(a[i]-1);
    } else
    {
        for (i = 0; i <= 10000; i++)
            for (j = 0; j <= 10000; j++)
                if (pre[i^j] == k)
                    ans += a[i]*a[j];
    }
    cout << ans/2 << endl;
    return 0;
}