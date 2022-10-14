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
ll k,k1,k2,k3,n,i,j,d,x,y,m,len[105],l,r,sum,a[105];
pair <ll,ll> b[105];
vector <ll> f;
double rez,p[10005],pi[10005][6];
bool ifin(ll x, ll y, ll n)
{
     if (n >= x && n <= y)
        return true;
     return false;
}
int main()
{
     cin >> n;
     for (i = 0; i < n; i++)
     {
         cin >> b[i].first >> b[i].second;
         len[i] = b[i].second - b[i].first + 1;
     }
     for (i = 1; i <= 10000; i++)
     {
     for (l = 0; l < n; l++)
     {
         for (j = 0; j < n; j++)
         if (j != l)
         {
             if (i >= b[j].first && i <= b[j].second)
             {
                   double tmp = 1./len[j];
                   for (k = 0; k < n; k++)
                       if (k != j && k != l)
                       {
                             double siz = max(min(i-b[k].first,len[k]),0LL);
                             
                             tmp *= siz/(double)len[k];
                       }
                   pi[i][l] += tmp;
             }             
         }
         f.clear();
         for (j = 0; j < n; j++)
         if (j != l && ifin(b[j].first,b[j].second,i))
            f.push_back(j);
         for (j = 0; j < f.size(); j++)
             for (k = j+1; k < f.size(); k++)
             {
                 ll v1 = f[j], v2 = f[k];
                 double tmp = 1./(len[v1]*len[v2]);
                 for (d = 0; d < n; d++)
                     if (d != v1 && d != v2 && d != l)
                     {
                           double siz = max(min(i-b[d].first,len[d]),0LL);
                             
                           tmp *= siz/(double)len[d];
                     }
                 pi[i][l] += tmp;
             }
             
         for (j = 0; j < f.size(); j++)
             for (k = j+1; k < f.size(); k++)
                 for (k1 = k+1; k1 < f.size(); k1++)
                     for (k2 = k1+1; k2 < f.size(); k2++)
             {
                 ll v1 = f[j], v2 = f[k], v3 = f[k1], v4 = f[k2];
                 double tmp = 1./(len[v1]*len[v2]*len[v3]*len[v4]);
                 for (d = 0; d < n; d++)
                     if (d != v1 && d != v2 && d != l && d != v3 && d != v4)
                     {
                           double siz = max(min(i-b[d].first,len[d]),0LL);
                             
                           tmp *= siz/(double)len[d];
                     }
                 pi[i][l] += tmp;
             }            
         
         for (j = 0; j < f.size(); j++)
             for (k = j+1; k < f.size(); k++)
                 for (k1 = k+1; k1 < f.size(); k1++)
             {
                 ll v1 = f[j], v2 = f[k], v3 = f[k1];
                 double tmp = 1./(len[v1]*len[v2]*len[v3]);
                 for (d = 0; d < n; d++)
                     if (d != v1 && d != v2 && d != l && d != v3)
                     {
                           double siz = max(min(i-b[d].first,len[d]),0LL);
                             
                           tmp *= siz/(double)len[d];
                     }
                 pi[i][l] += tmp;
             }         
     }
     }
     double rez = 0;
     /*for (i = 0; i < n; i++)
     {
         for (j = 1; j <= 10; j++)
             cout << pi[j][i] << " ";
         cout << endl;
     }*/
     for (i = 0; i < n; i++)
         for (j = b[i].first; j <= b[i].second; j++)
         {
             for (k = 1; k < j; k++)
                 rez += ((double)k*pi[k][i])/(double)len[i];
             
         }
     ll l = -5;
     for (i = 1; i <= 10000; i++)
     {
         f.clear();
         for (j = 0; j < n; j++)
             if (ifin(b[j].first,b[j].second,i))
                f.push_back(j);
         ll m = f.size();
         
             
         for (j = 0; j < f.size(); j++)
             for (k = j+1; k < f.size(); k++)
             {
                 ll v1 = f[j], v2 = f[k];
                 double tmp = 1./(len[v1]*len[v2]);
                 for (d = 0; d < n; d++)
                     if (d != v1 && d != v2 && d != l)
                     {
                           double siz = max(min(i-b[d].first,len[d]),0LL);
                             
                           tmp *= siz/(double)len[d];
                     }
                 rez += tmp*i;
             }
             
         for (j = 0; j < f.size(); j++)
             for (k = j+1; k < f.size(); k++)
                 for (k1 = k+1; k1 < f.size(); k1++)
                     for (k2 = k1+1; k2 < f.size(); k2++)
             {
                 ll v1 = f[j], v2 = f[k], v3 = f[k1], v4 = f[k2];
                 double tmp = 1./(len[v1]*len[v2]*len[v3]*len[v4]);
                 for (d = 0; d < n; d++)
                     if (d != v1 && d != v2 && d != l && d != v3 && d != v4)
                     {
                           double siz = max(min(i-b[d].first,len[d]),0LL);
                             
                           tmp *= siz/(double)len[d];
                     }
                 rez += tmp*i;
             }            
         
         for (j = 0; j < f.size(); j++)
             for (k = j+1; k < f.size(); k++)
                 for (k1 = k+1; k1 < f.size(); k1++)
             {
                 ll v1 = f[j], v2 = f[k], v3 = f[k1];
                 double tmp = 1./(len[v1]*len[v2]*len[v3]);
                 for (d = 0; d < n; d++)
                     if (d != v1 && d != v2 && d != l && d != v3)
                     {
                           double siz = max(min(i-b[d].first,len[d]),0LL);
                             
                           tmp *= siz/(double)len[d];
                     }
                 rez += tmp*i;
             } 
             
         for (j = 0; j < f.size(); j++)
             for (k = j+1; k < f.size(); k++)
                 for (k1 = k+1; k1 < f.size(); k1++)
                     for (k2 = k1+1; k2 < f.size(); k2++)
                         for (k3 = k2+1; k3 < f.size(); k3++)
             {
                 ll v1 = f[j], v2 = f[k], v3 = f[k1], v4 = f[k2], v5 = f[k3];
                 double tmp = 1./(len[v1]*len[v2]*len[v3]*len[v4]*len[v5]);
                 for (d = 0; d < n; d++)
                     if (d != v1 && d != v2 && d != v5 && d != v3 && d != v4)
                     {
                           double siz = max(min(i-b[d].first,len[d]),0LL);
                             
                           tmp *= siz/(double)len[d];
                     }
                 rez += tmp*i;
             } 
             
         
     }        
     printf ("%.10f\n",rez);
    return 0;
}