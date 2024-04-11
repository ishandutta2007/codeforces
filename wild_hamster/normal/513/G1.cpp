#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>
#include <deque>
#include <time.h>
#include <stack>
#include <stdio.h>
#include <map>
#include <set>
#include <string>
#define mp make_pair
#define pb push_back
#define PI 3.14159265358979323846
#define MOD 1000000007
typedef long long ll;
using namespace std;
ll k,k1,k2,k3,n,i,j,d,x,y,m,a[105],l1,r1,l2,r2,l3,r3,l4,r4,sum,b[105];
vector <ll> f;

int main()
{
     cin >> n >> k;
     for (i = 0; i < n; i++)
         cin >> a[i];
     if (k == 4)
     for (l1 = 0; l1 < n; l1++)
         for (r1 = l1; r1 < n; r1++)
     for (l2 = 0; l2 < n; l2++)
         for (r2 = l2; r2 < n; r2++)
     for (l3 = 0; l3 < n; l3++)
         for (r3 = l3; r3 < n; r3++)
     for (l4 = 0; l4 < n; l4++)
         for (r4 = l4; r4 < n; r4++)
     {
         m++;
         for (i = 0; i < n; i++)
             b[i] = a[i];
         reverse(b+l1,b+r1+1);
         reverse(b+l2,b+r2+1);
         reverse(b+l3,b+r3+1);
         reverse(b+l4,b+r4+1);
         for (i = 0; i < n; i++)
             for (j = i+1; j < n; j++)
                 if (b[i] > b[j])
                    sum++;
     } else
     if (k == 3)
     for (l1 = 0; l1 < n; l1++)
         for (r1 = l1; r1 < n; r1++)
     for (l2 = 0; l2 < n; l2++)
         for (r2 = l2; r2 < n; r2++)
     for (l3 = 0; l3 < n; l3++)
         for (r3 = l3; r3 < n; r3++)
     for (l4 = 0; l4 < n; l4++)
         for (r4 = l4; r4 < n; r4++)
     {
         m++;
         for (i = 0; i < n; i++)
             b[i] = a[i];
         reverse(b+l1,b+r1+1);
         reverse(b+l2,b+r2+1);
         reverse(b+l3,b+r3+1);
         //reverse(b+l4,b+r4+1);
         for (i = 0; i < n; i++)
             for (j = i+1; j < n; j++)
                 if (b[i] > b[j])
                    sum++;
     } else
     if (k == 2)
     for (l1 = 0; l1 < n; l1++)
         for (r1 = l1; r1 < n; r1++)
     for (l2 = 0; l2 < n; l2++)
         for (r2 = l2; r2 < n; r2++)
     for (l3 = 0; l3 < n; l3++)
         for (r3 = l3; r3 < n; r3++)
     for (l4 = 0; l4 < n; l4++)
         for (r4 = l4; r4 < n; r4++)
     {
         m++;
         for (i = 0; i < n; i++)
             b[i] = a[i];
         reverse(b+l1,b+r1+1);
         reverse(b+l2,b+r2+1);
         //reverse(b+l3,b+r3+1);
         //reverse(b+l4,b+r4+1);
         for (i = 0; i < n; i++)
             for (j = i+1; j < n; j++)
                 if (b[i] > b[j])
                    sum++;
     } else
     if (k == 1)
     for (l1 = 0; l1 < n; l1++)
         for (r1 = l1; r1 < n; r1++)
     for (l2 = 0; l2 < n; l2++)
         for (r2 = l2; r2 < n; r2++)
     for (l3 = 0; l3 < n; l3++)
         for (r3 = l3; r3 < n; r3++)
     for (l4 = 0; l4 < n; l4++)
         for (r4 = l4; r4 < n; r4++)
     {
         m++;
         for (i = 0; i < n; i++)
             b[i] = a[i];
         reverse(b+l1,b+r1+1);
         //reverse(b+l2,b+r2+1);
         //reverse(b+l3,b+r3+1);
         //reverse(b+l4,b+r4+1);
         for (i = 0; i < n; i++)
             for (j = i+1; j < n; j++)
                 if (b[i] > b[j])
                    sum++;
     }
     printf ("%.10f\n",(double)sum/m);
    return 0;
}