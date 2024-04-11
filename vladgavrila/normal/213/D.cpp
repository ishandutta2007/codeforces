#include <cstdio>
#include <set>
#include <vector>

using namespace std;

#define maxn 1510

int n, nn, pz[maxn], st[maxn];
pair<double, double> p[maxn];
vector<int> v[maxn];

int main()
{
  //  freopen("data.in", "r", stdin);
  //  freopen("data.out", "w", stdout);

    scanf("%d", &n);

    p[1]=make_pair(-3.601321235851749, 10.057331467373021);
    p[2]=make_pair(0.466045194906253, 19.192786043799030);
    p[3]=make_pair(3.830127018922193, 3.366025403784439);
    p[4]=make_pair(10.411264148588986, 18.147501411122495);
    p[5]=make_pair(12.490381056766580, 8.366025403784439);
    nn=5;

    for(int i=2; i<=n; ++i)
    {
        for(int j=1; j<=4; ++j)
            p[nn+j]=make_pair(2*p[nn].first-p[nn-j].first, p[nn-j].second);
            nn+=4;
    }

    printf("%d\n", nn);
    for(int i=1; i<=nn; ++i)
        printf("%.10lf %.10lf\n", p[i].first, p[i].second);

    int a, b, c, d, e;
    for(int i=1; i<=n; ++i)
    {
        a=(i-1)*4+1; b=(i-1)*4+2; c=(i-1)*4+4; d=(i-1)*4+5; e=(i-1)*4+3;
        printf("%d %d %d %d %d\n", a, b, c, d, e);
        v[a].push_back(c);
        v[b].push_back(d);
        v[c].push_back(e);
        v[d].push_back(a);
        v[e].push_back(b);
    }

    int nod, st0=0;
    st[++st0]=1;
    while(st0>0)
    {
        nod=st[st0];
        if(pz[nod]==v[nod].size())
        {
            printf("%d ", nod);
            --st0;
            continue;
        }
        st[++st0]=v[nod][pz[nod]++];
    }
    printf("\n");

    return 0;
}