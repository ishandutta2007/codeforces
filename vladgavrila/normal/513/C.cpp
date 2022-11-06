#include <cstdio>
#include <algorithm>

using namespace std;

#define maxn 200

int n, m, rr,  cn;
int l[maxn], r[maxn];
int st[maxn];
double sol, tcases, cases;

void back(int pas)
{
    if(pas==n+1)
    {
        double cn=1;
        int has1=0, has2=0;
        for(int i=1; i<=n; ++i)
        {
            if(st[i]==0)
                cn=cn*max(0, min(rr, r[i]+1)-l[i]);
            else
            if(st[i]==1)
            {
                ++has1;
                if(!(l[i]<=rr && rr<=r[i]))
                    cn=0;
            }
            else
            {
                ++has2;
                cn=cn*max(0, r[i]-max(rr, l[i]-1));
            }
        }
        if((has1>=2 && has2==0) || (has1>=1 && has2==1))
            cases+=cn;
        return;
    }

    for(int i=0; i<3; ++i)
    {
        st[pas]=i;
        back(pas+1);
    }
}

int main()
{
 //   freopen("c.in", "r", stdin);
  //  freopen("c.out", "w", stdout);

    scanf("%d", &n);

    for(int i=1; i<=n; ++i)
        scanf("%d%d", &l[i], &r[i]);

    for(rr=0; rr<=10001; ++rr)
    {
        cases=0;
        back(1);

        sol+=rr*cases;
        tcases+=cases;
    }
    printf("%.11lf\n", sol/tcases);

    return 0;
}