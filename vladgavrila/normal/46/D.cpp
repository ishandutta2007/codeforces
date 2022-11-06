#include <cstdio>

using namespace std;

#define maxn 110010

int n, m, l, L, b, f;
int p[maxn];
long long sp[maxn];
int nr1, r1[maxn], lg[maxn];

long long sum(int i, int j)
{
    if(i<0)
        i=0;
    if(j>=L)
        j=L-1;

    if(i==0)
        return sp[j];
    return sp[j]-sp[i-1];
}

void park(int l)
{
    ++nr1;
    lg[nr1]=l;
    for(int i=0; i<=L-l; ++i)
    {
        if(sum(i-b, i+l+f-1)==0)
        {
            for(int j=i; j<i+l; ++j)
                p[j]=1;
            sp[0]=p[0];
            for(int j=1; j<=L; ++j)
                sp[j]=sp[j-1]+p[j];
            r1[nr1]=i;
            return;
        }
    }

    r1[nr1]=-1;
}

void rem(int pz)
{
    ++nr1;
    int rr=r1[pz], ll=lg[pz];
    for(int i=rr; i<rr+ll; ++i)
        p[i]=0;

    sp[0]=p[0];
    for(int j=1; j<=L; ++j)
        sp[j]=sp[j-1]+p[j];
}

int main()
{
   // freopen("d.in", "r", stdin);
   // freopen("D.out", "w", stdout);

    int tp;

    scanf("%d%d%d", &L, &b, &f);
    scanf("%d", &n);
    for(int i=1; i<=n; ++i)
    {
        scanf("%d%d", &tp, &l);
        if(tp==1)
        {
            park(l);
            printf("%d\n", r1[nr1]);
        }
        else
            rem(l);
   //     for(int j=0; j<=L; ++j)
   //         printf("%d ", p[j]);
    //    printf("\n");
    }

    return 0;
}