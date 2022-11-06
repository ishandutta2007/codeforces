#include <cstdio>
#include <algorithm>

using namespace std;

#define maxn 150010

int n, m, q0, a, b;
int q[maxn];
int s[maxn];
double c, sp[maxn];
double sol, best, mn, mx;
double aint[4*maxn][3];

void build(int nod, int left, int right)
{
    if(left==right)
    {
        aint[nod][0]=aint[nod][1]=s[left]/2.0-sp[left];
        aint[nod][2]=0;
        return;
    }

    int med=(left+right)/2;

    build(nod*2, left, med);
    build(nod*2+1, med+1, right);

    aint[nod][0]=max(aint[nod*2][0], aint[nod*2+1][0]);
    aint[nod][1]=min(aint[nod*2][1], aint[nod*2+1][1]);
    aint[nod][2]=max(aint[nod*2][2], aint[nod*2+1][2]);
    aint[nod][2]=max(aint[nod][2], aint[nod*2+1][0]-aint[nod*2][1]);
}

void query(int nod, int left, int right, int qleft, int qright)
{
    if(qleft<=left && right<=qright)
    {
        q[++q0]=nod;
        return;
    }

    int med=(left+right)/2;

    if(qleft<=med)
        query(nod*2, left, med, qleft, qright);

    if(med<qright)
        query(nod*2+1, med+1, right, qleft, qright);
}

int main()
{
 //   freopen("data.in", "r", stdin);
 //   freopen("data.out", "w", stdout);

    scanf("%d%d%lf", &n, &m, &c);
    for(int i=1; i<=n; ++i)
        scanf("%d", &s[i]);
    for(int i=2; i<=n; ++i)
    {
        scanf("%lf", &sp[i]);
        sp[i]=c*sp[i]/100.0+sp[i-1];
    }

    build(1, 1, n);

    for(int pas=1; pas<=m; ++pas)
    {
        q0=0;
        best=0;

        mn=200000000;
        mx=-200000000;

        scanf("%d%d", &a, &b);
        query(1, 1, n, a, b);

        for(int i=1; i<=q0; ++i)
        {
            best=max(best, aint[q[i]][2]);
            mx=max(mx, aint[q[i]][0]);
            if(i>1)
                best=max(best, aint[q[i]][0]-mn);
            mn=min(mn, aint[q[i]][1]);
        }

        sol+=best;
    }

    printf("%.6lf\n", sol);
    return 0;
}