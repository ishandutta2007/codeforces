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
#define INF ((ll)1e+18)
#define x1 fldgjdflgjhrthrl
#define x2 fldgjdflgrtyrtyjl
#define y1 fldggfhfghjdflgjl
#define y2 ffgfldgjdflgjl
#define SQ 500400
#define CI 43534
#define MAXN 100100
typedef int ll;
using namespace std;
ll x,y,i,j,n,k,k1,k2,k3,m,x1,y1,x2,y2,z,max1,tx,pnt,flag;
vector <ll> divisors;
ll a[500500];
int main()
{
    //freopen("input.txt","r",stdin);
    cin >> n;
    k = 0;
    for (i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    a[n] = 2;
    i = 0;
    while (i < n-1)
    {
        if (a[i] == a[i+1])
              i++;
        ll start = i;
        ll finish = start-1;
        while (a[i] != a[i+1] && i < n-1)
              finish = i++;
        finish+=2;
        //cout << start << " " << finish << endl;
        if (a[start] == a[finish-1])
        {
            k = max(k,(finish-start)/2);
            if (a[start] == 1)
            {
                for (j = start; j < finish; j++)
                    a[j] = 1;
            } else
            {
                for (j = start; j < finish; j++)
                    a[j] = 0;
            }
        } else
        {
            ll mid = (finish-start)/2;
            k = max(k,mid-1);
            if (a[start] == 1)
            {
                for (j = start; j < start+mid; j++)
                    a[j] = 1;
                for (j = start+mid; j < finish; j++)
                    a[j] = 0;
            } else
            {
                for (j = start; j < start+mid; j++)
                    a[j] = 0;
                for (j = start+mid; j < finish; j++)
                    a[j] = 1;
            }
        }
    }
    cout << k << endl;
    for (i = 0; i < n; i++)
        printf("%d ",a[i]);
    cout << endl;
    return 0;
}