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
ll i,j,n,k,l,m,tot, flag,r,ans,z, K,x1,y1,x2,y2,x3,y3,x,y,h,num,h2,timer,sz,q,nn;
string s,t,s1;
ll a[1000500], used[1000500];
int main() {
	//freopen("input.txt","r",stdin);
 	//freopen("output.txt","w",stdout);
    cin >> s >> t;
    n = s.size();
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
        a[i]--;
    }
    ll l = 0, r = n;
    while (l < r)
    {
        ll mid = (l+r+1)/2;
        ll flag = 1;
        for (i = 0; i < mid; i++)
            used[a[i]] = 1;
        s1.clear();
        for (i = 0; i < n; i++)
            if (!used[i])
            {
                s1.push_back(s[i]);
            } else
                used[i] = 0;
        m = s1.size();
        j = 0;
        for (i = 0; i < t.size(); i++)
        {
            while (j < m && s1[j] != t[i])
                j++;
            if (j == m)
            {
                flag = 0;
                break;
            }
            j++;
        }
        if (flag)
            l = mid;
        else
            r = mid-1;
    }
    cout << l << endl;
    return 0;
}