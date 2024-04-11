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
#include <unordered_map>
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
#define N 1000000
#define SUM 377
#define MAG 33554431
#define RED 0
#define BLUE 1
#define ALP 26
typedef int ll;
typedef long double ld;
using namespace std;
ll i,j,k,l,m,r,x,y,K,tot,h,H,sz,cur,sum;
ll n;
int a[100500], pos[55], b[100500];
set<pii> f;
set<pii>::iterator itr;
int main() {
	//freopen("input.txt","r",stdin);
 	//freopen("output.txt","w",stdout);
    cin >> n >> m;
    if (m != 1)
    {
        cout << "Yes" << endl;
        return 0;
    }
    for (i = 0; i < n; i++)
        cin >> a[i];
    for (j = 0; j < m; j++)
        cin >> b[j];
    k = 0;
    for (i = 0; i < n; i++)
    {
        if (a[i] == 0)
            a[i] = b[0];
    }
    for (i = 0; i < n-1; i++)
        if (a[i] > a[i+1])
    {
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;
    return 0;
}