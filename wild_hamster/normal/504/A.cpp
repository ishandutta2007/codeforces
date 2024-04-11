#include <iostream>
//#include <cmath>
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
string s;
ll n,i,j,k1,k2,x,k,y,m,l,r,c,t,sum,xors[100500];
vector <pair<ll,ll> > rez;
struct rak
{
       ll degree,s,num;
};
rak a[200005];
bool ff(rak x, rak y)
{
     if (x.degree < y.degree) return true;
     if (x.degree > y.degree) return false;
     if (x.s < y.s) return true;
     return false;     
}
set <ll> verts,verts2;
set <ll>::iterator itr;
int main()
{
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> a[i].degree >> a[i].s;
        a[i].num = i;
        //xors[i] = a[i].s;
    }
    for (i = 0; i < n; i++)
    {
        if (a[i].degree == 1)
        {
         a[i].degree--;
         ll v = a[i].s^xors[i];
         rez.pb(mp(i,v));
         a[v].degree--;
         verts.insert(v);
         xors[v]^=i;
        }
    }
    while (!verts.empty())
    {
    for (itr = verts.begin(); itr!=verts.end(); itr++)
    {
        ll v = (*itr);
        if (a[v].degree == 1)
        {
         ll next = xors[v]^a[v].s;
         xors[next] ^= v;
         verts2.insert(next);
         rez.pb(mp(v,next));
         a[v].degree--;
         a[next].degree--;
        }
    }
    verts.clear();
    for (itr = verts2.begin(); itr!=verts2.end(); itr++)
    {
        ll v = (*itr);
        verts.insert(v);
    }
    verts2.clear();
}
cout << rez.size() << endl;
for (i = 0; i < rez.size(); i++)
    cout << rez[i].first << " " << rez[i].second << endl;
    return 0;
}