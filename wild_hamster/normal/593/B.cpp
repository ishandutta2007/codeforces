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
vector <pii> f;
int main()
{
    //freopen("input.txt","r",stdin);
    cin >> n;
    cin >> x1 >> x2;
    for (i = 0; i < n; i++)
    {
        ll k,b;
        cin >> k >> b;
        f.push_back(mp(k*x1+b,k*x2+b));
    }
    sort(f.begin(),f.end());
    for (i = 0; i < f.size()-1; i++)
        if (f[i].second > f[i+1].second)
        {
            cout << "YES" << endl;
            return 0;
        }
    cout << "NO" << endl;
    return 0;
}