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
typedef long long ll;
using namespace std;
ll x,y,l,i,j,n,k,k1,k2,k3,m,x1,y1,x2,y2,r,z,max1,tx,pnt,flag;
vector <ll> divisors,ans;
string s;
char c[500];
int main()
{
    //freopen("input.txt","r",stdin);
    cin >> n >> m;
    for (i = 'a'; i <= 'z'; i++)
        c[i] = i;
    cin >> s;
    for (i = 0; i < m; i++)
    {
        char x,y;
        cin >> x >> y;
        for (j = 'a'; j <= 'z'; j++)
            if (c[j] == x)
               c[j] = y;
            else
            if (c[j] == y)
               c[j] = x;
    }
    for ( i = 0; i < s.size(); i++)
        s[i] = c[s[i]];
    cout << s << endl;
    return 0;
}