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
#define INF ((ll)1e+9)
#define x1 fldgjdflgjhrthrl
#define x2 fldgjdflgrtyrtyjl
#define y1 fldggfhfghjdflgjl
#define y2 ffgfldgjdflgjl
#define SQ 500400
#define CI 43534
#define MAXN 100100
typedef int ll;
using namespace std;
ll x,y,l,i,j,n,k,k1,k2,k3,m,x1,y1,x2,y2,r,z,max1,tx,flag;
vector <ll> divisors,ans;
ll min_path[5][5];
string s,s1;
ll a[105],b[1050],c[1050];
pair<ll,ll> dp[10050];
int main()
{
    //freopen("input.txt","r",stdin);
    ll x,t,a,b,da,db;
    cin >> x >> t >> a >> b >> da >> db;
    if (x == 0)
    {
        cout << "YES" << endl;
        return 0;
    }
    for (i = 0; i < t; i++)
        if (a-i*da == x || b - i*db == x)
        {
            cout << "YES" << endl;
            return 0;
        }
    for (i = 0; i < t; i++)
        for (j = 0; j < t; j++)
            if (a + b - i*da - j*db == x)
            {
                cout << "YES" << endl;
                return 0;
            }
    cout << "NO" << endl;
    return 0;
}