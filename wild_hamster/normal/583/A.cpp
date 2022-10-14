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
#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define pdd pair<double,double>
#define PI 3.14159265358979323846
#define MOD 1000000007
#define MOD2 (9LL+(ll)1e+9)
#define INF ((ll)1e+9)
#define x1 fldgjdflgjhrthrl
#define x2 fldgjdflgrtyrtyjl
#define y1 fldggfhfghjdflgjl
#define y2 ffgfldgjdflgjl
#define SQ 500400
#define CI 43534
typedef long long ll;
using namespace std;
ll x,y,l,i,j,n,k,k1,k2,k3,m,x1,y1,x2,y2,r,z,max1,pnt,a[2005],b[2005],pot[2005],cur[2005],used[2005];
string s1,s2,s3;
vector <ll> eq,neq;
vector<pair<ll,ll> > f;
ll Abs(ll x)
{
    return x>0?x:-x;
}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n;
    for (i = 0; i < n*n; i++)
    {
        cin >> x >> y;
        if (!a[x] && !b[y])
        {
            cout << i+1 << " ";
            a[x] = 1;
            b[y] = 1;
        }
    }
    return 0;
}