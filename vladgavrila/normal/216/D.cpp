#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

#define maxn 1010

int n, x, m, sol, nxt, prv, p1, p2, l1, l2;
vector<int> v[maxn];

int main()
{
  //  freopen("data.in", "r", stdin);
  //  freopen("data.out", "w", stdout);

    scanf("%d", &n);
    for(int i=1; i<=n; ++i)
    {
        scanf("%d", &m);
        while(m--)
        {
            scanf("%d", &x);
            v[i].push_back(x);
        }
        sort(v[i].begin(), v[i].end());
    }

    for(int i=1; i<=n; ++i)
    {
        nxt=i+1;
        if(i==n)
            nxt=1;
        prv=i-1;
        if(i==1)
            prv=n;
        p1=p2=0;
        for(int j=0; j<v[i].size(); ++j)
        {
            l1=l2=0;

            while(p1<v[prv].size())
            {
                if(v[prv][p1]>v[i][j])
                    break;
                ++p1;
                ++l1;
            }

            while(p2<v[nxt].size())
            {
                if(v[nxt][p2]>v[i][j])
                    break;
                ++p2;
                ++l2;
            }

            if(j>0 && l1!=l2)
                ++sol;
        }
    }

    printf("%d\n", sol);

    return 0;
}