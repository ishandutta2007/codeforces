#include <cstdio>
#include <cstring>
#include <set>

using namespace std;

#define maxn 200010

int n, m, cr;
set<pair<int, int> > a, b;
int v[maxn], v2[maxn], p1[maxn], p2[maxn], nr[maxn];

int main()
{
  //  freopen("data.in", "r", stdin);
  //  freopen("data.out", "w", stdout);

    scanf("%d", &n);
    for(int i=1; i<=n; ++i)
    {
        scanf("%d", &v[i]);
        p1[v[i]]=i;
    }

    for(int i=1; i<=n; ++i)
    {
        scanf("%d", &v2[i]);
        p2[v2[i]]=i;
    }

    a.insert(make_pair(1000000000, 0));
    b.insert(make_pair(1000000000, 0));

    for(int i=1; i<=n; ++i)
    {
        if(p1[i]<=p2[i])
            b.insert(make_pair(p2[i]-p1[i], i));
        else
        {
            nr[i]=p1[i]-p2[i];
            a.insert(make_pair(p1[i]-p2[i], i));
        }
    }

    for(int i=1; i<=n; ++i)
    {
     /*   for(set<pair<int, int> > :: iterator it=a.begin(); it!=a.end(); ++it)
            printf("%d %d\n", it->first, it->second);
        printf("\n");
         for(set<pair<int, int> > :: iterator it=b.begin(); it!=b.end(); ++it)
            printf("%d %d\n", it->first, it->second);
        printf("\n");*/

        printf("%d\n", min((b.begin()->first)-i+1, (a.begin()->first)+i-1));

  //      printf("\n");

        while((b.begin()->first)-i+1==0)
        {
            cr=b.begin()->second;
            b.erase(b.begin());
            a.insert(make_pair(-i+1, cr));
            nr[cr]=-i+1;

            if(b.empty())
                break;
        }

        cr=v2[i];
        a.erase(make_pair(nr[cr], cr));
        b.insert(make_pair(n-p1[cr]+i, cr));
    }

    return 0;
}