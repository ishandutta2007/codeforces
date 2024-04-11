#include <iostream>
//#include <cmath>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <deque>
#define mp make_pair
#define pb push_back
#define tA 555
#define tB 666
#define AorB 777
#define N 100499
#define PI 3.14159265358979323846
typedef long long ll;
using namespace std;
ll n,l,r,i,j,k,x1,x2,y1,y2,m,y,v;
map <ll,ll> usedx1,usedx2,usedy1,usedy2,timex1,timex2,timey1,timey2;
vector <ll> fx1,fx2,fy1,fy2;
map <ll,ll> finder;
map <ll,pair<ll,ll> > our_pair;
string s;
ll rez[10];
void do_bad_things1(ll x, ll timer)
{
     if (usedx1[x]) return;
     usedx1[x] = 1;
     timex1[x] = timer;
     fx1.push_back(x);
     if (x%3 !=0 && x%2 != 0) return;
     if (x%3 == 0)
        do_bad_things1((2*x)/3,timer+1);
     if (x%2 == 0)
        do_bad_things1(x/2,timer+1);
}
void do_bad_things2(ll x, ll timer)
{
     if (usedx2[x]) return;
     usedx2[x] = 1;
     timex2[x] = timer;
     fx2.push_back(x);
     if (x%3 !=0 && x%2 != 0) return;
     if (x%3 == 0)
        do_bad_things2((2*x)/3,timer+1);
     if (x%2 == 0)
        do_bad_things2(x/2,timer+1);
}
void do_bad_things3(ll x, ll timer)
{
     if (usedy1[x]) return;
     usedy1[x] = 1;
     timey1[x] = timer;
     fy1.push_back(x);
     if (x%3 !=0 && x%2 != 0) return;
     if (x%3 == 0)
        do_bad_things3((2*x)/3,timer+1);
     if (x%2 == 0)
        do_bad_things3(x/2,timer+1);
}
void do_bad_things4(ll x, ll timer)
{
     if (usedy2[x]) return;
     usedy2[x] = 1;
     timey2[x] = timer;
     fy2.push_back(x);
     if (x%3 !=0 && x%2 != 0) return;
     if (x%3 == 0)
        do_bad_things4((2*x)/3,timer+1);
     if (x%2 == 0)
        do_bad_things4(x/2,timer+1);
}
int main()
{
    cin >> x1 >> x2 >> y1 >> y2;
    do_bad_things1(x1,0);
    do_bad_things2(x2,0);
    do_bad_things3(y1,0);
    do_bad_things4(y2,0);
    ll maxtime = 500;
    for (i = 0; i < fx1.size(); i++)
        for (j = 0; j < fx2.size(); j++)
        {
            //cout << fx1[i] << " " << fx2[j] << endl;
            finder[fx1[i]*fx2[j]] = timex1[fx1[i]]+timex2[fx2[j]];
            our_pair[fx1[i]*fx2[j]] = mp(fx1[i],fx2[j]);
        }
    for (i = 0; i < fy1.size(); i++)
        for (j = 0; j < fy2.size(); j++)
        {
            //cout << fy1[i] << " " << fy2[j] << endl;
            if (fy1[i]*fy2[j] == x1*x2)
            {
             cout << timey1[fy1[i]]+timey2[fy2[j]] << endl;
             cout << x1 << " " << x2 << endl << fy1[i] << " " << fy2[j] << endl;
             return 0;
            }
            ll dob = fy1[i]*fy2[j];
            if (finder[dob] > 0)
            {
             ll x = our_pair[dob].first;
             ll y = our_pair[dob].second;
             if (timex1[x]+timex2[y]+timey1[fy1[i]]+timey2[fy2[j]] < maxtime)
             {
              maxtime = timex1[x]+timex2[y]+timey1[fy1[i]]+timey2[fy2[j]];
              rez[0] = x; rez[1] = y; rez[2] = fy1[i]; rez[3] = fy2[j];
             }
            }
        }
    if (maxtime == 500)
       cout << -1 << endl;
    else
    {
        cout << maxtime << endl;
        cout << rez[0] << " " << rez[1] << endl << rez[2] << " " << rez[3] << endl;
    }
    return 0;
}