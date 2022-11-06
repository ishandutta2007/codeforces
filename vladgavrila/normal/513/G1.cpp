#include <cstdio>
#include <algorithm>

using namespace std;

#define maxn 20

int n, k, ans, cases;
int v[maxn];

void back(int pas)
{
    if(pas==k)
    {
        ++cases;
        for(int i=1; i<=n; ++i)
            for(int j=i+1; j<=n; ++j)
                if(v[i]>v[j])
                    ++ans;
        return;
    }
    for(int i=1; i<=n; ++i)
        for(int j=i; j<=n; ++j)
        {
            reverse(v+i, v+j+1);
            back(pas+1);
            reverse(v+i, v+j+1);
        }
}

int main()
{
   // freopen("g.in", "r", stdin);
  //  freopen("g.out", "w", stdout);

    scanf("%d%d", &n, &k);
    for(int i=1; i<=n; ++i)
        scanf("%d", &v[i]);

    back(0);

    printf("%.9lf\n", double(ans)/cases);

    return 0;
}