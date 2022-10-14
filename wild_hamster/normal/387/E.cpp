#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <deque>
#define tr 1000000007
#define mp make_pair
#define pb push_back
#define tA 555
#define tB 666
#define AorB 777
#define N 100499
typedef long long ll;
using namespace std;
ll n,i,j,d,m,x,r,y,p,k,max1,c[1000500],pos[1000500],a[1005000],b[1000500],used[1005],mt[1600],e,l,rez;
ll t[1000500];
string s1,s2,s;
set <ll> dniwe;
int main()
{
    cin >> n >> m;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
        pos[a[i]] = i + 1;
    }
    for (i = 1; i <= n; i++)
        c[i] = 1;
    for (i = 0; i < m; i++)
    {
        cin >> x;
        c[x] = 0;
    }
    dniwe.insert(0);
    dniwe.insert(n+1);
    for (i = 1; i <= n; i++)
    {
        if (c[i] == 1)
        {
           set<ll>::iterator itr = dniwe.upper_bound(pos[i]);
            r = *(itr--);
            l = *(itr);
            rez += r-l-1;
            for (j = r-1; j >= 0; j = (j&(j+1))-1)
            {
                rez -= t[j];
            }
            for (j = l; j >= 0; j = (j&(j+1))-1)
            {
                rez += t[j];
            }
            for (j = pos[i]; j <= n; j|=(j+1))
                t[j]++;
        }
        //cout << l << " " << r << endl;        
        if (c[i] == 0) dniwe.insert(pos[i]);
    }
    cout << rez << endl;
    return 0;
}