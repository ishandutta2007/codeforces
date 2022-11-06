#include <cstdio>
#include <map>
#include <set>
#include <algorithm>
#include <cstdlib>

using namespace std;

#define maxn 100010

int n, m, x, y, rez;
int v[maxn][4], lg[maxn], f[maxn];
int sol[maxn];
map<pair<int, int>, int> mp;

void back(int pz)
{
    if(pz==n)
    {
        rez=1;

        sol[n+1]=sol[1];
        sol[n+2]=sol[2];

        for(int i=1; i<=n; ++i)
            if(mp[make_pair(sol[i], sol[i+1])]==0 || mp[make_pair(sol[i], sol[i+2])]==0)
            {
                rez=0;
                return;
            }

        if(rez==1)
        {
            for(int i=1; i<=n; ++i)
                printf("%d ", sol[i]);
            printf("\n");
        }

        exit(0);

        return;
    }

    for(int i=1; i<=n; ++i)
    {
        if(f[i])
            continue;
        sol[pz+1]=i;
        f[i]=1;
        back(pz+1);
        f[i]=0;
    }
}


int main()
{
   // freopen("data.in", "r", stdin);
  //  freopen("data.out", "w", stdout);

    scanf("%d", &n);
    for(int i=1; i<=2*n; ++i)
    {
        scanf("%d%d", &x, &y);
        if(lg[x]==4 || lg[y]==4)
        {
            printf("-1\n");
            return 0;
        }
        v[x][lg[x]++]=y;
        v[y][lg[y]++]=x;
        mp[make_pair(x, y)]=1;
        mp[make_pair(y, x)]=1;
    }

    if(n<=6)
    {
        back(0);
        if(rez==0)
        {
            printf("-1\n");
            return 0;
        }
    }

    sol[1]=1;

    for(int i=0; i<4; ++i)
        for(int j=0; j<4; ++j)
        {
            if(i==j)
                continue;
            for(int k=0; k<4; ++k)
            {
                if(i==k || j==k)
                    continue;
                for(int l=0; l<4; ++l)
                {
                    if(i==l || j==l || k==l)
                        continue;

                if(mp[make_pair(v[1][i], v[1][j])]==1 && mp[make_pair(v[1][j], v[1][k])]==1 && mp[make_pair(v[1][k], v[1][l])]==1 &&
                   mp[make_pair(v[1][i], v[1][k])]==0 && mp[make_pair(v[1][j], v[1][l])]==0 && mp[make_pair(v[1][i], v[1][l])]==0)
                    {
                        sol[2]=v[1][j];
                        sol[n]=v[1][k];
                    }
                }
            }
        }

    sol[0]=sol[n];
    for(int i=2; i<n; ++i)
    {
        int x, ok=0;
        for(int j=0; j<4; ++j)
        {
            x=v[sol[i]][j];
            if(x!=sol[i-2] && x!=sol[i-1] && mp[make_pair(x, sol[i-1])]==1)
            {
                ok=1;
                sol[i+1]=x;
            }
        }
        if(ok==0)
        {
            printf("-1\n");
            return 0;
        }
    }

    sol[n+1]=sol[1];
    sol[n+2]=sol[2];

    for(int i=1; i<=n; ++i)
        if(mp[make_pair(sol[i], sol[i+1])]==0 || mp[make_pair(sol[i], sol[i+2])]==0)
        {
            printf("-1\n");
            return 0;
        }


    for(int i=1; i<=n; ++i)
        printf("%d ", sol[i]);
    printf("\n");

    return 0;
}