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
#include <fstream>
#include <queue>
#define mp make_pair
#define pb push_back
#define PI 3.14159265358979323846
#define MOD 1000000007
#define INF ((ll)1e+9)
#define x1 fldgjdflgjhrthrl
#define x2 fldgjdflgrtyrtyjl
#define y1 fldggfhfghjdflgjl
#define y2 ffgfldgjdflgjl
typedef int ll;
using namespace std;
ll fr[40],i,j,x1,y1,x2,y2,n,k,k1,k2,m,y,x,p,q;
string s;
ll a[100500];
struct node
{
    ll letters[27];
    ll w, color;
};
node t[500500];
void build(ll v, ll tl, ll tr)
{
    if (tl == tr)
    {
        t[v].letters[a[tl]] = 1;
        t[v].w = 1;
        t[v].color = a[tl];
        return;
    }
    ll tm = (tl+tr)/2;
    build(v*2,tl,tm);
    build(v*2+1,tm+1,tr);
    for (int i = 0; i < 26; i++)
        t[v].letters[i] = t[v*2].letters[i] + t[v*2+1].letters[i];
    t[v].w = t[v*2].w + t[v*2+1].w;
}
void get(ll v, ll tl, ll tr, ll l, ll r)
{
    if (l > r)
       return;
    if (l == tl && r == tr)
    {
        for (int j = 0; j < 26; j++)
            fr[j] += t[v].letters[j];
        return;
    } else
    {
        if (t[v].color != -1)
        {
            t[v*2].color = t[v].color;
            t[v*2+1].color = t[v].color;
            ll col = t[v].color;
            for (int j = 0; j < 26; j++)
                t[v*2].letters[j] = t[v*2+1].letters[j] = 0;
            t[v*2].letters[col] = t[v*2].w;
            t[v*2+1].letters[col] = t[v*2+1].w;
            t[v].color = -1;
        }
        ll tm = (tl+tr)/2;
        get(v*2,tl,tm,l,min(r,tm));
        get(v*2+1,tm+1,tr,max(l,tm+1),r);
    }
}
void update(ll v, ll tl, ll tr, ll l, ll r, ll val)
{
    if (l > r)
       return;
    if (l == tl && r == tr)
    {
        for (int j = 0; j < 26; j++)
            t[v].letters[j] = 0;
        t[v].color = val;
        t[v].letters[val] = t[v].w;
        return;
    } else
    {
        if (t[v].color != -1)
        {
            t[v*2].color = t[v].color;
            t[v*2+1].color = t[v].color;
            for (int j = 0; j < 26; j++)
                t[v*2].letters[j] = t[v*2+1].letters[j] = 0;
            ll col = t[v].color;
            t[v*2].letters[col] = t[v*2].w;
            t[v*2+1].letters[col] = t[v*2+1].w;
            t[v].color = -1;
        }
        ll tm = (tl+tr)/2;
        update(v*2,tl,tm,l,min(r,tm),val);
        update(v*2+1,tm+1,tr,max(l,tm+1),r,val);
        for (int j = 0; j < 26; j++)
            t[v].letters[j] = t[v*2].letters[j] + t[v*2+1].letters[j];
    }
}
int main()
{
    cin >> n >> q;
    cin >> s;
    for (i = 0; i <= 4*n; i++)
    {
        t[i].w = 0;
        t[i].color = -1;
        for (j = 0; j < 26; j++)
            t[i].letters[j] = 0;
    }
    for (i = 0; i < n; i++)
        a[i] = s[i] - 'a';
    build(1,0,n-1);
    for (i = 0; i < q; i++)
    {
        ll test;
        ll l,r;
        cin >> l >> r >> test;
        l--; r--;
        for (j = 0; j < 26; j++)
            fr[j] = 0;
        get(1,0,n-1,l,r);
        if (test == 1)
        {
         ll lft = l;
         for (j = 0; j < 26; j++)
         if(fr[j])
         {
            update(1,0,n-1,lft,lft+fr[j]-1,j);
            lft += fr[j];
         }
        } else
        {

         ll rgt = r;
         for (j = 0; j < 26; j++)
         if (fr[j])
         {
            //cout << r-fr[j]+1 << " " << r << " " << char(j+'a') << endl;
            update(1,0,n-1,r-fr[j]+1,r,j);
             r -= fr[j];
         }
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < 26; j++)
            fr[j] = 0;
        get(1,0,n-1,i,i);
        for (j = 0; j < 26; j++)
            if (fr[j] == 1)
               cout << (char)(j+'a');
    }
    cout << endl;
    return 0;
}