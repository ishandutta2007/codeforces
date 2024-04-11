#include <cstdio>
#include <iostream>
#include <map>
#include <set>

using namespace std;

#define maxn 11
#define maxl 2010
#define b1 13
#define b2 7
#define mod1 666013
#define mod2 1000007

int n, m, x, nok, ok, h1, h2;
int l[maxn], r[maxn], lg[maxn];
string s, t[maxn];
int sz[maxn], v[maxn][maxl];
map<pair<int, int>, int> mp[maxn];
set<pair<int, int> > g;
pair<int, int> h;

void solve(int i)
{
    map<pair<int, int>, int> :: iterator it;
    h=make_pair(0, 0);

    for(int j=i; j<m; ++j)
    {
        h.first=(h.first*b1+s[j])%mod1;
        h.second=(h.second*b2+s[j])%mod2;

        if(g.find(h)!=g.end())
            continue;

        g.insert(h);

        ok=1;
        for(int k=1; k<=n; ++k)
        {
            it=mp[k].find(h);
            if(it==mp[k].end())
                x=0;
            else
                x=it->second;

            if(x>r[k])
            {
                ok=0;
                break;
            }
            if(x<l[k])
                return;
        }
        nok+=ok;
    }
}

int main()
{
  //  freopen("g.in", "r", stdin);
  //  freopen("g.out", "w", stdout);

    cin>>s;
    cin>>n;
    for(int i=1; i<=n; ++i)
    {
        cin>>t[i];
        cin>>l[i]>>r[i];
        lg[i]=t[i].size();
        for(int j=0; j<lg[i]; ++j)
        {
            h=make_pair(0, 0);
            for(int k=j; k<lg[i]; ++k)
            {
                h.first=(h.first*b1+t[i][k])%mod1;
                h.second=(h.second*b2+t[i][k])%mod2;
                ++mp[i][h];
            }
        }
    }

    m=s.size();
    for(int i=0; i<m; ++i)
        solve(i);

    cout<<nok<<"\n";

    return 0;
}