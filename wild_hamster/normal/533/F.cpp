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
#define MOD (((ll)1e+15)+7)
#define x1 flkdgl
#define x2 fdgdfgh
#define y1 lfdkgl
#define y2 lhkgflhkf
#define INF ((ll)1e+18)
typedef long long ll;
using namespace std;
ll k,v1,v2,z,w,l,r,i,j,n,x1,x2,y1,y2,x,y,m,pr[50],powr[200500],q[50],fir[300];
ll hash[200500];
vector <ll> ans;
string s,t;
ll binpow(ll x, ll y)
{
 if (y == 0)
    return 1;
 ll tmp = binpow(x,y/2);
 if (y%2 == 1)
    return (((tmp*tmp)%MOD)*x)%MOD; 
 return (tmp*tmp)%MOD;
}
int main()
{
    cin >> n >> m;
    powr[0] = 1;
    for (i = 1; i <= n; i++)
        powr[i] = (powr[i-1]*31LL)%MOD;
    cin >> s >> t;
    for (i = 0; i < m; i++)
    {
        q[t[i]-'a'+1] = (q[t[i]-'a'+1] + powr[m-i-1])%MOD;
        if (fir[t[i]] == 0)
        fir[t[i]] = i+1;
    }
    ll tmp = 0;
    for (i = 0; i < m; i++)
        tmp = (tmp*31LL + s[i] - 'a' + 1) %MOD;
    hash[0] = tmp;
    for (i = m; i < n; i++)
    {
        hash[i-m+1] = (hash[i-m] - (s[i-m]-'a'+1)*powr[m-1] + 100LL*MOD)%MOD;
        hash[i-m+1] = hash[i-m+1]*31LL + s[i] - 'a' + 1;
        hash[i-m+1] %= MOD;
    }
    for (i = 0; i < n-m+1; i++)
    {
        ll hsh = 0;
        for (j = 1; j <= 26; j++)
            pr[j] = 0;
        for (j = 'a'; j <= 'z'; j++)
            if (fir[j] != 0)
            {
             pr[j-'a'+1] = s[i+fir[j]-1] - 'a' + 1;
             hsh = (hsh+q[j-'a'+1]*(s[i+fir[j]-1] - 'a' + 1))%MOD;
            }
        ll flag = 1;
        for (j = 1; j <= 26; j++)
        if (pr[j] != 0)
        {
            ll v = j;
            ll to = pr[j];
            if (pr[to] != 0 && pr[to] != v)
               flag = 0;
            else
            pr[to] = v;
        }
        if (hsh == hash[i] && flag)
           ans.push_back(i+1);
    }
    cout << ans.size() << endl;
    for (i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    cout << endl;
    return 0;
}