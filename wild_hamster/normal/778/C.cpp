#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>
#include <deque>
#include <stack>
#include <stdio.h>
#include <map>
#include <set>
#include <time.h>
#include <string>
#include <fstream>
#include <queue>
#include <bitset>
#include <cstdlib>
#include <assert.h>
#include <list>
#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define pdd pair<double,double>
#define pii pair<ll,ll>
#define PI 3.14159265358979323846
#define MOD 1000000007
#define MOD2 1000000009
#define INF ((ll)1e+18)
#define x1 fldgjdflgjhrthrl
#define x2 fldgjdflgrtyrtyjl
#define y1 fldggfhfghjdflgjl
#define y2 ffgfldgjdflgjl
#define N 131072
#define SUM 377
#define MAG 33554431
#define RED 0
#define BLUE 1
#define ALP 26
typedef int ll;
typedef long double ld;
using namespace std;
ll i,j,n,k,l,m,tot, flag,r,ans,z, K,x1,y1,x2,y2,x3,y3,x,y,h,num,h2,timer,sz,q,nn, hs, ml,cnt;
string s,t,s1;
ll a[300500];
vector<pair<ll, char> > g[300500], f[300500];
vector<ll> levels[300500];
vector<pair<ll, char> > vec, vec1;
bool cmp(pair<ll,char> x, pair<ll,char> y)
{
    return x.Y < y.Y;
}
void dfs(ll v, ll lvl, ll p = -1)
{
    ml = max(ml, lvl);
    levels[lvl].push_back(v);
    for (int i = 0; i < g[v].size(); i++)
    {
        ll to = g[v][i].X;
        if (to != p)
        {
            f[v].push_back(g[v][i]);
            dfs(to,lvl+1,v);
        }
    }
}
ll go(vector<pair<ll, char> > &vec)
{
    ll sz = vec.size();
    if (sz == 0)
        return 0;
    ll ans = 0;
    ll k = 1;
    for (int i = 0; i+1 < sz; i++)
    {
        if (vec[i].Y == vec[i+1].Y)
            k++;
        else
        {
            ans += k-1;
            if (k > 1)
            {
                vector<pair<ll, char> > t;
                for (int j = i-k+1; j <= i; j++)
                {
                    for (int l = 0; l < f[vec[j].X].size(); l++)
                    {
                        t.push_back(f[vec[j].X][l]);
                    }
                }
                sort(t.begin(), t.end(), cmp);
                ans += go(t);
                k = 1;
            }
        }
    }
    if (k > 1)
    {
        ans += k-1;
        vector<pair<ll, char> > t;
        for (int j = sz-k; j < sz; j++)
        {
            for (int l = 0; l < f[vec[j].X].size(); l++)
            {
                t.push_back(f[vec[j].X][l]);
            }
        }
        sort(t.begin(), t.end(), cmp);
        ans += go(t);
        k = 1;
    }
    return ans;
}
int main() {
	//freopen("input.txt","r",stdin);
 	//freopen("output.txt","w",stdout);
    cin >> n;
    for (i = 0; i < n-1; i++)
    {
        char c;
        scanf("%d %d %c",&x,&y,&c);
        g[x].push_back(mp(y,c));
        g[y].push_back(mp(x,c));
    }
    dfs(1, 0);
    for (i = 0; i < ml; i++)
    {
        ll tmp = 0;
        for (j = 0; j < levels[i].size(); j++)
        {

            vec.clear();
            ll v = levels[i][j];
            tmp += f[v].size();
            for (k = 0; k < f[v].size(); k++)
            {
                ll to = f[v][k].X;
                for (l = 0; l < f[to].size(); l++)
                    vec.push_back(f[to][l]);
            }
            sort(vec.begin(), vec.end(), cmp);
            tmp += go(vec);

        }
        if (tmp > ans)
        {
            ans = tmp;
            tot = i+1;
        }
    }
    cout << n-ans << endl << tot << endl;
    return 0;
}