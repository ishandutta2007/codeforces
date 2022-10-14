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
#define MAXN 100100
typedef int ll;
using namespace std;
ll sum,x,y,l,i,j,n,k,k1,k2,k3,m,x1,y1,x2,y2,r,z,max1,pnt,N,K,ii;
ll a[100500], used[100500];
vector <ll> primes;
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n;
    for (i = 0; i < n; i++)
        cin >> a[i];
    for (i = 0; i < n; i++)
    {
        if (i%2 == 0)
        {
            for (j = 0; j < n; j++)
                if (!used[j] && a[j] <= k)
                {
                    used[j] = 1;
                    k++;
                }
        } else
        {
            for (j = n-1; j >= 0; j--)
                if (!used[j] && a[j] <= k)
                {
                    used[j] = 1;
                    k++;
                }
        }
        if (k == n)
           break;
    }
    cout << i << endl;
    return 0;
}