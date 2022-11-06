#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

#define maxn 100010
#define maxs 210

int n, m, costout, r, co, cmin;
int l[maxn], d[maxn], nr[maxn];
vector<int> v[maxs];

int main()
{
  //  freopen("c.in", "r", stdin);
  //  freopen("c.out", "w", stdout);

    scanf("%d", &n);
    for(int i=1; i<=n; ++i)
    {
        scanf("%d", &l[i]);
        ++nr[l[i]];
    }
    for(int i=1; i<=n; ++i)
        scanf("%d", &d[i]);

    for(int i=1; i<=n; ++i)
        v[d[i]].push_back(l[i]);

    for(int i=1; i<maxs; ++i)
        sort(v[i].begin(), v[i].end());

    r = n;

    cmin=maxn*maxs;

    for(int w=maxn-1; w>=0; --w)
    {
        if(nr[w]==0)
            continue;

        int cr=0;

        for(int i=1; i<maxs; ++i)
        {
            if(v[i].size()==0)
                continue;

            while(v[i][v[i].size()-1]==w)
            {
                v[i].pop_back();

                cr+=i;

                --r;

                if(v[i].size()==0)
                    break;

            }
        }

        int nec = max(0, (r - (nr[w] - 1)));
        int cc=0;

    //    printf("!%d %d %d %d\n", r, nr[w], w, nec);

        for(int i=1; i<maxs; ++i)
        {
            cc+=min(nec, int(v[i].size()))*i;
            nec-=min(nec, int(v[i].size()));
        }

        cmin=min(cc+co, cmin);

        co+=cr;
    }

    printf("%d\n", cmin);

    return 0;
}