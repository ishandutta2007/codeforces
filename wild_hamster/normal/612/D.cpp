#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <string.h>
#include <map>
#include <vector>
#include <set>
using namespace std;
typedef int ll;
#define mp make_pair
#define MOD 1000000007
ll n,m,k,n1,n2,i,j, x,y,l,r, coord,p,q;
ll a[1000500], b[1000500], pb[4000500], back[4000050], t[4000050];
string s;
set<ll> f;
set<ll>::iterator itr;
map<ll,ll> compr;
vector <ll> tmp;
vector<pair<ll,ll> > gg;
ll Abs(ll x)
{
    return x>0?x:-x;
}
void error() {
    cout << "Impossible" << endl;
    exit(0);
}
int main()
{
    //freopen("input.txt","r",stdin);
    cin >> n >> k;
    for (i = 0; i < n; i++)
    {
        scanf("%d %d",&a[i],&b[i]);
        f.insert(a[i]);
        f.insert(b[i]);
    }
    for (itr = f.begin(); itr != f.end(); itr++)
    {
        back[x] = *itr;
        compr[*itr] = x++;
    }
    for (i = 0; i < n; i++)
    {
        a[i] = compr[a[i]], b[i] = compr[b[i]];
        t[a[i]]++;
        pb[b[i]]--;
    }
    ll tmpx = 0, tmpy = -1;
    y = 0;
    for (i = 0; i <= 2050505; i++)
    {
        y += t[i];      
        if (y >= k)
        {
            if (tmpx > tmpy)
                tmpx = tmpy = i;
            else
                tmpy++;
        }
        y += pb[i];
        if (y < k)
        {
            if (tmpx <= tmpy)
                gg.push_back(mp(back[tmpx], back[tmpy]));
            tmpx = 0; tmpy = -1;
        }
            
    }
    if (tmpx <= tmpy)
        gg.push_back(mp(back[tmpx], back[tmpy]));
    cout << gg.size() << endl;
    for (i = 0; i < gg.size(); i++)
        printf("%d %d\n",gg[i].first,gg[i].second);
        
    return 0;
}