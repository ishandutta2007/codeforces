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
ll i,j,n,k,l,m,tot, flag,r,z, K,x1,y1,x2,y2,x3,y3,x,y,h,num,h2,timer,sz,q,nn, hs, ml,cnt;
string s,t,s1;
ll a[300500], used[300500];
vector<pii> g[105000];
set<pii> gr[100500];
set<pii>::iterator itr;
string ans[100500];
ll trans(string x)
{
    return (x[0]-'A')*676+(x[1]-'A')*26+x[2]-'A';
}
string rev(ll x)
{
    string tmp;
    tmp.push_back(x/676+'A');
    x%=676;
    tmp.push_back(x/26+'A');
    x%=26;
    tmp.push_back(x+'A');
    return tmp;
}
vector<ll> f;
int main() {
	//freopen("input.txt","r",stdin);
 	//freopen("output.txt","w",stdout);
 	cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> s >> t;
        string tmp = s.substr(0,2);
        tmp.push_back(t[0]);
        g[trans(s)].push_back(mp(trans(tmp), i));
        ans[i] = s.substr(0,3);
    }
    for (i = 0; i < 676*26; i++)
    {
        if (g[i].size() == 1)
        {
            gr[i].insert(g[i][0]);
            gr[g[i][0].X].insert(mp(i, g[i][0].Y));
        }
        if (g[i].size() > 1)
        {
            for (j = 0; j < g[i].size(); j++)
            {
                ll v = g[i][j].X;
                if (used[v])
                {
                    cout << "NO" << endl;
                    return 0;
                }
                used[v] = 1;
                ans[g[i][j].Y] = rev(g[i][j].X);
                f.push_back(g[i][j].X);
            }
        }
    }
    i = 0;
    while (i < f.size())
    {
        int x = f[i];
        i++;
        for (itr = gr[x].begin(); itr != gr[x].end(); itr++)
        {
            ll to = (*itr).X;
            if (used[to])
            {
                //cout << rev(x) << " " << rev(to) << endl;
                cout << "NO" << endl;
                return 0;
            }
            used[to] = 1;
            ans[(*itr).Y] = rev(to);
            gr[(*itr).X].erase(mp(x, (*itr).Y));
            f.push_back(to);
        }
    }
    cout << "YES" << endl;
    for (i = 0; i < n; i++)
        cout << ans[i] << endl;
    return 0;
}