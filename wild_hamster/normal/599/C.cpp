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
#define N 118228
typedef long long ll;
using namespace std;
ll l,i,j,n,k,k1,k2,k3,m,x1,y1,x2,y2,x,y,r,z,max1,tx,flag,timer,start,finita,ans;
ll a[N],b[N],c[N],d[N];
vector <pii> f;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
        f.push_back(mp(a[i],i));
    }
    sort(f.begin(),f.end());
    i = 0; j = 0;
    while (i < n)
    {
        ll tmp = -1;
        ll hyu = a[i];
        while (1)
        {
        while (f[j].first < hyu && j < n)
        {
            tmp = max(tmp,f[j].second);
            j++;
        }
        if (i >= tmp)
           break;
           for (k1 = i; k1 <= tmp; k1++)
               hyu = max(hyu,a[k1]);
        i = max(i,tmp);
        }
        i++;
        k++;
    }
    cout << k << endl;
    return 0;
}