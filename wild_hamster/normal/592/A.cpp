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
#define MAXN 100100
typedef long long ll;
using namespace std;
ll l,i,j,n,k,k1,k2,k3,m,x1,y1,x2,y2,x,y,r,z,max1,tx,flag;
vector <ll> divisors;
ll a[100500];
char c[15][15];
string s,t;
int main()
{
   // freopen("input.txt","r",stdin);
   for (i = 0; i < 8; i++)
       for (j = 0; j < 8; j++)
           cin >> c[i][j];
   k1 = 9, k2 = 9;
   for (i = 0; i < 8; i++)
       for (j = 0; j < 8; j++)
       {
        if (c[i][j] == 'W')
        {
            ll flag = 1;
            for (k = 0; k < i; k++)
                if (c[k][j] != '.')
                   flag = 0;
            if (flag)
               k1 = min(k1,i);
        } else
        if (c[i][j] == 'B')
        {
            ll flag = 1;
            for (k = i+1; k < 8; k++)
                if (c[k][j] != '.')
                   flag = 0;
            //cout << i << " " << j << flag << endl;
            if (flag)
               k2 = min(k2,7-i);
        }
       }
   if (k1 <= k2)
      cout << "A" << endl;
   else
       cout << "B" << endl; 
    return 0;
}