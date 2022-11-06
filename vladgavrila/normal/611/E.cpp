#include <cstdio>
#include <set>

using namespace std;

#define maxn 200010

int sol, n, m, a, b, c;
multiset<int> g;
int v[maxn];

int best()
{
    if(g.size()==0)
        return -1;
    return *g.rbegin();
}

int bestBeat(int val)
{
    multiset<int> :: iterator it = g.upper_bound(val);
    if(it!=g.begin())
    {
        --it;
        return *it;
    }
    return -1;
}

void defeat(int x)
{
    if(bestBeat(x)!=-1)
        g.erase(g.find(bestBeat(x)));
}

int main()
{
    scanf("%d", &n);
    scanf("%d%d%d", &a, &b, &c);

    if(a>b)
        swap(a, b);
    if(b>c)
        swap(b, c);
    if(a>b)
        swap(a, b);

    for(int i=1; i<=n; ++i)
    {
        int x;
        scanf("%d", &x);
        if(x>a+b+c)
        {
            printf("-1\n");

            return 0;
        }
        g.insert(x);
    }

    while(best() > b+c)
    {
        defeat(a+b+c);
        ++sol;
    }

    while(best() > a+c)
    {
        defeat(b+c);
        defeat(a);
        ++sol;
    }

    while(best() > c && best() > a+b)
    {
        defeat(a+c);
        defeat(b);
        ++sol;
    }

    if(a+b > c)
    {
        while(best() > c)
        {
            defeat(a+b);
            defeat(c);
            ++sol;
        }
    }

    while(g.size()>0)
    {
        if(bestBeat(a)==-1 || bestBeat(b)==-1)
        {
            defeat(a+b);
            defeat(c);
        }
        else
        {
            defeat(c);
            defeat(b);
            defeat(a);
        }
        ++sol;
    }

    printf("%d\n", sol);

    return 0;
}