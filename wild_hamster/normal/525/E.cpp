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
ll x,y,w,l,r,i,j,n,t,k,k1,k2,d,m,q,dr,a[100505],b[100505],c[100050],fact[30];
map <pair<ll,ll>,ll> f1[30],f2[30];
map <pair<ll,ll>,ll>::iterator itr;
vector <ll> f;
int main()
{
    fact[1] = 1;
    for (i = 2; i <= 19; i++)
        fact[i] = fact[i-1]*i;
    //cout << fact[19] << endl;
    cin >> n >> k >> r;
    for (i = 1; i <= n; i++)
        cin >> a[i];
    f1[0][mp(0,0)] = 1;
    k1 = 0;
    for (i = 1; i <= n/2; i++)
    {
        for (itr = f1[i-1].begin(); itr != f1[i-1].end(); itr++)
        {
            pair <ll,ll> tmp = (*itr).first;
            ll cnt = (*itr).second;
            if (a[i] <= 18)
               f1[i][mp(fact[a[i]]+tmp.first,tmp.second+1)] += cnt;
            f1[i][mp(a[i]+tmp.first,tmp.second)] += cnt;
            f1[i][mp(tmp.first,tmp.second)] += cnt;
        }
        k1 = i;
    }
    f2[n/2][mp(0,0)] = 1;
    k2 = n/2;
    for (i = n/2+1; i <= n; i++)
    {
        for (itr = f2[i-1].begin(); itr != f2[i-1].end(); itr++)
        {
            pair <ll,ll> tmp = (*itr).first;
            ll cnt = (*itr).second;
            if (a[i] <= 18)
               f2[i][mp(fact[a[i]]+tmp.first,tmp.second+1)] += cnt;
            f2[i][mp(a[i]+tmp.first,tmp.second)] += cnt;
            f2[i][mp(tmp.first,tmp.second)] += cnt;
        }
        k2 = i;
    }
    ll rez = 0;
    for (itr = f1[k1].begin(); itr != f1[k1].end(); itr++)
    {
        pair <ll,ll> tmp = (*itr).first;
        ll cnt = (*itr).second;
        //cout << tmp.first << " " << tmp.second << " " << cnt << endl;
        for (i = 0; i <= k-tmp.second; i++)
            rez += f2[k2][mp(r-tmp.first,i)]*cnt;
    }
    cout << rez << endl;
    return 0;
}