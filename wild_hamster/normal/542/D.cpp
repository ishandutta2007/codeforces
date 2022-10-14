#include <omp.h>
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
#define mp make_pair
#define pb push_back
#define PI 3.14159265358979323846
#define MOD 1000000007
typedef long long ll;
using namespace std;
ll cur,k,oz,w,l,r,i,j,k1,k2,dr,n,m, t, qt, qh, md, primes[1000005], x, y, p;
string s;
vector <ll> prs;
vector <vector <ll> > cool_primes;
map <pair<ll,ll>,ll> g;
bool isp(ll x)
{
    for (int i = 0; i < prs.size() && prs[i]*prs[i] <= x; i++)
        if (x%prs[i] == 0)
           return false;
    return true;
}
ll gcd(ll a, ll b)
{
    if(a%b == 0)
           return b;
    return gcd(b,a%b);
}
ll go(ll n, ll id)
{
    if (g.count(mp(n,id)))
       return g[mp(n,id)];
    if (n == 1)
       return 1;
    ll tmp = 0;
    if (id == cool_primes.size())
    {
        if (n == 1) return 1;
        if (n-1 > 1000000 && isp(n-1))
           return 1;
        return 0;
    }
    for (int i = 0; i < cool_primes[id].size(); i++)
        if (n%cool_primes[id][i] == 0)
           tmp += go(n/cool_primes[id][i],id+1);
    tmp += go(n,id+1);
    return g[mp(n,id)] = tmp;
}
int main()
{
    //freopen("race.in","r",stdin);
    //freopen("race.out","w",stdout);
    cin >> n;
    for (i = 2; i < 1000000; i++)
        primes[i] = 1;
    for (i = 2; i < 1000000; i++)
        if (primes[i])
        {
        prs.push_back(i);
        for (j = i*i; j < 1000000; j+=i)
            primes[j] = 0;
        }
    //cout << isp(n) << endl;
    for (i = 0; i < prs.size(); i++)
    {
        k = prs[i];
        x = prs[i];
        vector <ll> kokoko;
        while (k < n)
        {
            if (n%(k+1) == 0)
               kokoko.push_back(k+1);
            k *= x;
        }
        if (kokoko.size() > 0)
           cool_primes.push_back(kokoko);
    }
    /*for (i = 0; i < cool_primes.size(); i++)
    {
        for (j = 0; j < cool_primes[i].size(); j++)
            cout << cool_primes[i][j] << " ";
        cout << endl;
    }*/
    cout << go(n,0) << endl;
    return 0;
}