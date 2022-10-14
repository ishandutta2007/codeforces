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
#define MOD2 1000000009
#define INF ((ll)1e+18)
#define x1 fldgjdflgjhrthrl
#define x2 fldgjdflgrtyrtyjl
#define y1 fldggfhfghjdflgjl
#define y2 ffgfldgjdflgjl
#define N 500500
#define SUM 23423
#define MAG 1048576
#define OPEN 0
#define CLOSE 1
typedef int ll;
typedef long double ld;
using namespace std;
ll i,j,n,k,l,m,tot, flag,h,r,ans,z, K,x1,y1,x2,y2,x3,y3,x,y;
ll a[200500];
string s;
int main() {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ll ans = 0;
    ll max1 = 0;
    cin >> n >> k;
    for (i = 1; i <= n; i++)
    {
    	scanf("%d",&x);
    	if (i == k)
    	{
    		if (x != 0)
			   ans++;
    	} else
    	{
    		a[x]++;
    		max1 = max(max1,x);
    	}
    }
    for (i = 1; i <= max1; i++)
    {
    	if (a[i] == 0)
    	{
    		if (a[0] == 0)
    		{
	    		a[max1]--;
	    		ans++;
	    		a[i]++;
	    		while (a[max1] == 0)
					  max1--;
			} else
			{
				ans++;
				a[i]++;
				a[0]--;
			}
    	}
    }
    cout << ans+a[0] << endl;
    return 0;
}