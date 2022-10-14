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
ll bits[100500][20],a[100500],i,j,n,m,x,l,y,b[100500][20],rez;
set <ll> pairs[20];
int main()
{
    cin >> n >> m;
    for (i = 0; i < n; i++)
        scanf("%I64d",&a[i]);
    for (i = 0; i < n; i++)
        for (j = 0; j < 17; j++)
            if (a[i]&(1<<j))
            {
               bits[i][j] = 1;
            }
    for (j = 0; j < 17; j++)
    {
        i = 0;
        while (i < n)
        {
              while (bits[i][j] == 0 && i < n)
              {
                    i++;
              }
              pairs[j].insert(i);
              x = i;
              while (bits[i][j] == 1 && i < n)
                    i++;
              b[x][j] = i - x;
              rez += (((i-x)*(i-x+1))/2)*(1<<j);
        }
    }
    for (i = 0; i < m; i++)
    {
        scanf("%I64d%I64d",&x,&y);
        x--;
        for (j = 0; j < 17; j++)
        {
            ll tmp = (y&(1<<j));
            if (tmp > 0) tmp = 1;
            if (tmp == bits[x][j])
               continue;
            if (tmp == 1)
            {
             if ((bits[x-1][j] == 0 || x == 0)&&(bits[x+1][j] == 0||x == n-1))
             {
              b[x][j] = 1;
              pairs[j].insert(x);
              rez += (1 << j);
             }
             if ((bits[x-1][j] == 0 || x == 0)&&(bits[x+1][j] == 1&&x < n-1))
             {
              b[x][j] = b[x+1][j] + 1;
              b[x+1][j] = 0;
              pairs[j].erase(x+1);
              pairs[j].insert(x);
              rez += (1 << j)*b[x][j];
             }
             if ((bits[x-1][j] == 1 && x > 0)&&(bits[x+1][j] == 0||x == n-1))
             {
              set<ll>::iterator itr = pairs[j].lower_bound(x);
              itr--;
              l = *(itr);
              b[l][j]++;
              rez+=(1<<j)*b[l][j];
             }
             if ((bits[x-1][j] == 1 && x > 0)&&(bits[x+1][j] == 1&&x < n-1))
             {
              set<ll>::iterator itr = pairs[j].lower_bound(x);
              itr--;
              l = *(itr);
              ll k1 = b[l][j];
              ll k2 = b[x+1][j];
              b[l][j] = k1+k2+1;
              pairs[j].erase(x+1);
              b[x+1][j] = 0;
              rez+=(1<<j)*(((k1+k2+1)*(k1+k2+2))/2 - (k1*(k1+1))/2 - (k2*(k2+1))/2);
             }
            bits[x][j] = 1;
            }
            else
            {
             if ((bits[x-1][j] == 0 || x == 0)&&(bits[x+1][j] == 0||x == n-1))
             {
              b[x][j] = 0;
              pairs[j].erase(x);
              rez -= (1 << j);
             }
             if ((bits[x-1][j] == 0 || x == 0)&&(bits[x+1][j] == 1&&x < n-1))
             {
              b[x+1][j] = b[x][j] - 1;              
              rez -= (1 << j)*b[x][j];
              b[x][j] = 0;
              pairs[j].erase(x);
              pairs[j].insert(x+1);
             }
             if ((bits[x-1][j] == 1 && x > 0)&&(bits[x+1][j] == 0||x == n-1))
             {
              set<ll>::iterator itr = pairs[j].lower_bound(x);
              itr--;
              l = *(itr);              
              rez-=(1<<j)*b[l][j];
              b[l][j]--;
             }
             if ((bits[x-1][j] == 1 && x > 0)&&(bits[x+1][j] == 1&&x < n-1))
             {
              set<ll>::iterator itr = pairs[j].lower_bound(x);
              itr--;
              l = *(itr);
              ll k1 = b[l][j] - (x-l+1);
              ll k2 = x - l;
              b[l][j] = k2;
              b[x+1][j] = k1;
              pairs[j].insert(x+1);
              rez-=(1<<j)*(((k1+k2+1)*(k1+k2+2))/2 - (k1*(k1+1))/2 - (k2*(k2+1))/2);
             }
            bits[x][j] = 0;
            }
        }
    printf("%I64d\n",rez);
    }
    return 0;
}