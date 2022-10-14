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
ll i,j,n,k,l,m,r,x,y,K;
string s,t,s1;
ll sum(ll x)
{
    ll ans = 0;
    while (x)
    {
        ans += x%10;
        x /= 10;
    }
    return ans;
}
int main() {
	//freopen("input.txt","r",stdin);
 	//freopen("output.txt","w",stdout);
    cin >> n;
    x = 1;
    k = sum(n); K = n;
    for (i = 0; i < 18; i++)
    {
        x = x*10;
        if (n%x != x-1)
            n = (n/x)*x-1;
        if (n == -1)
            break;
        if (sum(n) > k)
        {
            k = sum(n);
            K = n;
        }
    }
    cout << K << endl;
    return 0;
}