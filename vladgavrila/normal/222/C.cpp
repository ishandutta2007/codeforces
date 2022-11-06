#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

#define maxn 100010

int n, m, pc, sa, sb, x;
int f[maxn], a[maxn], b[maxn];
int lp[maxn];
vector<pair<int, int> > fa, fb;

int main()
{
 //   freopen("data.in", "r", stdin);
 //   freopen("data.out", "w", stdout);

    scanf("%d%d", &n, &m);

    for(int i=2; i<=3200; ++i)
    {
        if(f[i]==0)
        {
            lp[++lp[0]]=i;
            for(int j=i*i; j<=3200; j+=i)
                f[j]=1;
        }
    }

    for(int i=1; i<=n; ++i)
    {
        scanf("%d", &a[i]);
        x=a[i];
        for(int j=1; j<=lp[0]; ++j)
        {
            if(lp[j]*lp[j]>x)
                break;
            while(x%lp[j]==0)
            {
                x=x/lp[j];
                fa.push_back(make_pair(lp[j], i));
            }
        }
        if(x>1)
        {
             fa.push_back(make_pair(x, i));
        }
    }

    for(int i=1; i<=m; ++i)
    {
        scanf("%d", &b[i]);
        x=b[i];
        for(int j=1; j<=lp[0]; ++j)
        {
            if(lp[j]*lp[j]>x)
                break;
            while(x%lp[j]==0)
            {
                x=x/lp[j];
                fb.push_back(make_pair(lp[j], i));
            }
        }
        if(x>1)
        {
            fb.push_back(make_pair(x, i));
        }
    }

    sort(fa.begin(), fa.end());
    sort(fb.begin(), fb.end());

    sa=fa.size();
    sb=fb.size();

    for(int p1=0, p2=0; p1<sa && p2<sb; )
    {
        while(fa[p1].first<fb[p2].first)
        {
            ++p1;
            if(p1==sa)
                break;
        }
        if(p1==sa)
            break;

        while(fa[p1].first>fb[p2].first)
        {
            ++p2;
            if(p2==sb)
                break;
        }
        if(p2==sb)
            break;

        while(fa[p1].first==fb[p2].first)
        {
            a[fa[p1].second]/=fa[p1].first;
            b[fb[p2].second]/=fb[p2].first;
            ++p1; ++p2;
            if(p2==sb || p1==sa)
                break;
        }
    }

    printf("%d %d\n", n, m);

    for(int i=1; i<=n; ++i)
        printf("%d ", a[i]);
    printf("\n");

    for(int i=1; i<=m; ++i)
        printf("%d ", b[i]);
    printf("\n");


    return 0;
}