#include <cstdio>
#include <set>
using namespace std;

#define inf 1000000

int n, m, x, xsol, tp, ng;
pair<int, int> cr;

pair<int, int> cmmdc(int a, int b)
{
    if(a==1 && b==1)
        return make_pair(1, 0);

    if(a==1)
        return make_pair(b, b-1);
    if(b==1)
        return make_pair(a, a-2);

    if(a==0 || b==0)
        return make_pair(-inf, -inf);

    pair<int, int> sol;
    if(a>b)
    {
        sol=cmmdc(a%b, b);
        sol.first+=a/b;
        sol.second+=a/b-1;
    }
    else
    {
        sol=cmmdc(a, b%a);
        sol.first+=b/a;
        sol.second+=b/a-1;
        if(a==1)
            sol.second--;
    }
    return sol;
}

int reconst(int a, int b)
{
    if(a==1 && b==1)
    {
        printf("T");
        return 1;
    }

    int ras;
    if(a>b)
    {
        ras=reconst(a-b, b);
        if(a-b<=b)
            ras=1-ras;
    }
    else
    {
        ras=reconst(a, b-a);
        if(b-a<=a)
            ras=1-ras;
    }

    if(ras==1)
        printf("T");
    else
        printf("B");

    return ras;
}


int main()
{
  //  freopen("data.in", "r", stdin);
 //   freopen("data.out", "w", stdout);

    scanf("%d%d", &n, &x);
    ng=inf;
    for(int i=1; i<=x; ++i)
    {
        cr=cmmdc(i, x);
        if(cr.first==n && cr.second<ng)
        {
            ng=cr.second;
            xsol=i;
            tp=1;
        }
        cr=cmmdc(x, i);
        if(cr.first==n && cr.second<ng)
        {
            ng=cr.second;
            xsol=i;
            tp=2;
        }
    }

    if(ng==inf)
    {
        printf("IMPOSSIBLE\n");
        return 0;
    }

    printf("%d\n", ng);
    if(tp==1)
        ng=reconst(xsol, x);
    else
        ng=reconst(x, xsol);

    return 0;
}