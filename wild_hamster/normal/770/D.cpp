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
ll i,j,n,k,l,m,r,x,y,K,tot,h;
string s,t,s1;
ll a[100500];
char c[1005][1005];
int main() {
	//freopen("input.txt","r",stdin);
 	//freopen("output.txt","w",stdout);
    cin >> n;
    cin >> s;
    a[0] = 1;
    for (i = 1; i < n; i++)
    {
        if (s[i] == ']')
            a[i] = a[i-1] - 1;
        else
            a[i] = a[i-1] + 1;
    }
    for (i = 0; i < n; i++)
        if (s[i] == ']')
            a[i]++;
    for (i = 0; i < n; i++)
        k = max(k, a[i]);
    for (i = 0; i < n; i++)
        a[i] = k-a[i]+1;

    h = k*2+1;
    ll pnt = 0;
    for (i = 0; i < n; i++)
    {
        if (s[i] == '[')
        {
            ll tmp = k;
            c[tmp-a[i]][pnt] = '+';
            c[tmp-a[i]][pnt+1] = '-';
            c[tmp+a[i]][pnt] = '+';
            c[tmp+a[i]][pnt+1] = '-';
            for (j = tmp-a[i]+1; j <= tmp+a[i]-1; j++)
                c[j][pnt] = '|';
            pnt++;
        } else
        if (s[i] == ']')
        {
            if (s[i-1] == '[')
                pnt += 3;
            ll tmp = k;
            c[tmp-a[i]][pnt] = '+';
            c[tmp-a[i]][pnt-1] = '-';
            c[tmp+a[i]][pnt] = '+';
            c[tmp+a[i]][pnt-1] = '-';
            for (j = tmp-a[i]+1; j <= tmp+a[i]-1; j++)
                c[j][pnt] = '|';
            pnt++;
        }
    }
    for (i = 0; i < h; i++)
    {
        for (j = 0; j < pnt; j++)
            if (c[i][j] == '+' || c[i][j] == '-' || c[i][j] == '|')
                cout << c[i][j];
            else
                cout << " ";
        cout << endl;
    }
    return 0;
}