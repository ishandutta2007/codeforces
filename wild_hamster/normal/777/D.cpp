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
#define SUM 377
#define MAG 33554431
#define RED 0
#define BLUE 1
#define eps 1e-7
typedef long long ll;
typedef long double ld;
using namespace std;
ll i,j,n,k,l,m,tot, flag,r,z, K,x1,y1,x2,y2,x3,y3,x,y,h,num,h2,timer,sz,q,ans, curL, curR, SQ, P, Q, bad, N;
string s[500500];

int main() {
	//freopen("input.txt","r",stdin);
 	//freopen("output.txt","w",stdout);
 	cin >> n;
 	for (i = 0; i < n; i++)
        cin >> s[i];
    for (i = n-1; i > 0; i--)
    {
        ll x1 = s[i-1].size();
        ll x2 = s[i].size();
        for (j = 0; j < min(x1,x2); j++)
        {
            if (s[i][j] > s[i-1][j])
            {
                flag = 1;
                break;
            }
            if (s[i][j] < s[i-1][j])
            {
                flag = 0;
                break;
            }
        }
        if (j == min(x1,x2))
        {
            if (x1 > x2)
                s[i-1] = s[i-1].substr(0,x2);
        } else
        if (!flag)
        {
            s[i-1] = s[i-1].substr(0,j);
        }
    }
    for (i = 0; i < n; i++)
        cout << s[i] << endl;
 	return 0;
}