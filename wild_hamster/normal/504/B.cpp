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
ll n,i,j,k1,k2,x,k,y,m,l,r,t[800500],a[200500],b[200500],c[200500],tmp[200500];
void build (ll a[], ll v, ll tl, ll tr) {
    if (tl == tr)
        t[v] = a[tl];
    else {
        int tm = (tl + tr) / 2;
        build (a, v*2, tl, tm);
        build (a, v*2+1, tm+1, tr);
        t[v] = t[v*2] + t[v*2+1];
    }
}
ll sum (ll v, ll tl, ll tr, ll l, ll r) {
    if (l > r)
        return 0;
    if (l == tl && r == tr)
        return t[v];
    ll tm = (tl + tr) / 2;
    return sum (v*2, tl, tm, l, min(r,tm))
        + sum (v*2+1, tm+1, tr, max(l,tm+1), r);
}
void update (ll v, ll tl, ll tr, ll pos, ll new_val) {
    if (tl == tr)
        t[v] = new_val;
    else {
        ll tm = (tl + tr) / 2;
        if (pos <= tm)
            update (v*2, tl, tm, pos, new_val);
        else
            update (v*2+1, tm+1, tr, pos, new_val);
        t[v] = t[v*2] + t[v*2+1];
    }
}
int main()
{
    cin >> n;
    for (i = 0; i < n; i++)
        cin >> a[i];
    for (i = 0; i < n; i++)
        cin >> b[i];
        for (i = 0; i < n; i++)
            tmp[i] = 1;
    build(tmp,1,0,n-1);
    for (i = 0; i < n; i++)
    {
        c[i] += sum(1,0,n-1,0,a[i]-1);
        //cout << c[i] << endl;
        update(1,0,n-1,a[i],0);
    }
    
    build(tmp,1,0,n-1);
    for (i = 0; i < n; i++)
    {
        c[i] += sum(1,0,n-1,0,b[i]-1);
        update(1,0,n-1,b[i],0);
    }
    for (i = n-1; i >= 1; i--)
    {
        k = n-i;
        c[i-1] += c[i]/k;
        c[i]%=k;
    }
    c[0]%=n;
    /*for (i = 0; i < n; i++)
        cout << c[i] << " " ;*/
    build(tmp,1,0,n-1);
    for (i = 0; i < n; i++)
    {
        ll l = 0, r = n-1;
        while (l < r)
        {
              ll mid = (l+r-1)/2;
              //cout << mid << " " << sum(1,0,n-1,0,mid) << endl;
              if (sum(1,0,n-1,0,mid) >= c[i]+1)
                 r = mid;
              else
                  l = mid+1;
        }
        //cout << l << endl;
        c[i] = l;
        update(1,0,n-1,l,0);
        tmp[l] = 0;
        
    /*for (j = 0; j < n; j++)
        cout << tmp[j] << " ";
    cout << endl;*/
    }
    for (i = 0; i < n; i++)
        cout << c[i] << " ";
    return 0;
}