#include <cstdio>
#include <map>
#include <set>

using namespace std;

#define maxn 200010

int n, m, nc, t, cr, nr, pz;
set<int> p;
int prv[maxn], nxt[maxn];

set<pair<int, int> > g;
map<int, int> mp;
set<int> nrd;
set<int> cint;

void add_interval(int a, int b)
{
    if(a==0)
        g.insert(make_pair(-(b-a-2), a));
    else
    if(b==n+1)
        g.insert(make_pair(-(b-a-2), a));
    else
        g.insert(make_pair(-((b-a)/2-1), a));
}

void rem_interval(int a, int b)
{
    if(a==0)
        g.erase(make_pair(-(b-a-2), a));
    else
    if(b==n+1)
        g.erase(make_pair(-(b-a-2), a));
    else
        g.erase(make_pair(-((b-a)/2-1), a));
}

int main()
{
  //  freopen("data.in", "r", stdin);
  //  freopen("data.out", "w", stdout);

    scanf("%d%d", &n, &m);

    g.insert(make_pair(-n, 0));
    nxt[0]=n+1;
    prv[n+1]=0;

    int a, b, c;

    for(int i=1; i<=m; ++i)
    {
        scanf("%d%d", &t, &nr);
        if(t==1)
        {
            cr=g.begin()->second;
            if(cr==0)
                pz=1;
            else
            if(nxt[cr]==n+1)
                pz=n;
            else
                pz=(cr+nxt[cr])/2;

            g.erase(g.begin());

            a=cr;
            b=pz;
            c=nxt[cr];

            prv[b]=a;
            nxt[a]=b;
            nxt[b]=c;
            prv[c]=b;

            add_interval(a, b);
            add_interval(b, c);

            printf("%d\n", pz);
            mp[nr]=pz;
        }
        else
        {
            cr=mp[nr];

            b=cr;
            a=prv[cr];
            c=nxt[cr];

            rem_interval(a, b);
            rem_interval(b, c);

            nxt[a]=c;
            prv[c]=a;

            add_interval(a, c);
        }
    }

    return 0;
}