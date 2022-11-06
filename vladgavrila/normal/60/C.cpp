#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

#define maxs 110
#define maxn 10010
#define maxd 1000010

int n, m, i, j, k, a, b, x, y;
int val[maxs], sol[maxn], f[maxd], d[maxd];
int fol[maxs];
vector<int> v[maxn], gcd[maxn], lcm[maxn], q;

int df(int nod)
{
    fol[nod]=1;
    for(int i=0; i<v[nod].size(); ++i)
    {
        int fiu=v[nod][i];
        if(fol[fiu]==0)
        {
            int x;
            if(val[nod]==d[gcd[nod][i]])
            {
                val[fiu]=d[lcm[nod][i]];
                x=df(fiu);
            }
            else
            if(val[nod]==d[lcm[nod][i]])
            {
                val[fiu]=d[gcd[nod][i]];
                x=df(fiu);
            }
            else
                return 0;
            if(x==0)
                return 0;
        }
        else
        {
            if(d[gcd[nod][i]]>d[lcm[nod][i]] || !((val[nod]==d[gcd[nod][i]] && val[fiu]==d[lcm[nod][i]]) || (val[fiu]==d[gcd[nod][i]] && val[nod]==d[lcm[nod][i]])))
                return 0;
        }
    }
    return 1;
}


int main()
{
    #ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    #endif
    scanf("%d%d", &n, &m);

    for(int i=1; i<=n; ++i)
        sol[i]=1;

    for(int i=1; i<=m; ++i)
    {
        scanf("%d%d%d%d", &a, &b, &x, &y);
        v[a].push_back(b); gcd[a].push_back(x); lcm[a].push_back(y);
        v[b].push_back(a); gcd[b].push_back(x); lcm[b].push_back(y);
        q.push_back(x);
        q.push_back(y);
    }

    sort(q.begin(), q.end());
    vector<int> :: iterator it = unique(q.begin(), q.end());
    q.resize(it-q.begin());

    for(int poz=2; poz<=1000000; ++poz)
    {
        if(f[poz]==0)
        {
            if(1LL*poz*poz<=1LL*1000000)
                for(int pas=poz*poz; pas<=1000000; pas+=poz)
                    f[pas]=1;
            int ok=0;
            for(int i=0; i<q.size(); ++i)
            {
                int x=q[i];
                d[x]=0;
                while(x%poz==0)
                {
                    ok=1;
                    x/=poz;
                    d[q[i]]++;
                }
            }
            if(!ok)
                continue;

            memset(val, -1, sizeof(val));
            for(int i=1; i<=n; ++i)
            {
                if(val[i]==-1)
                {
                    int j=1;
                    for(j=0; j<=20; ++j)
                    {
                        memset(fol, 0, sizeof(fol));
                        val[i]=j;
                        if(df(i)==1)
                            break;
                    }
                    if(j==21)
                    {
                        printf("NO\n");
                        return 0;
                    }
                }
            }

            for(int i=1; i<=n; ++i)
                for(int j=1; j<=val[i]; ++j)
                    sol[i]*=poz;
        }
    }

    printf("YES\n");
    for(int i=1; i<=n; ++i)
        printf("%d ", sol[i]);
    printf("\n");
    return 0;
}