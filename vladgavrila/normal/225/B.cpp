#include <cstdio>
#include <vector>

using namespace std;

#define maxn 1010

int n, s,k, m;
long long tot, cr, fib[maxn];
vector<int> sol;

int main()
{
  //  freopen("data.in", "r", stdin);
  //  freopen("data.out", "w", stdout);

    scanf("%d%d", &s, &k);


    fib[1]=1;
    cr=0;

    for(n=2; ; ++n)
    {
        cr=cr+fib[n-1]-fib[max(n-k-1, 0)];
        if(cr<=s)
            fib[n]=cr;
        else
            break;
    }

    fib[1]=0;

    for(int i=n-1; i>0; --i)
    {
        if(fib[i]<=s)
        {
            sol.push_back(fib[i]);
            s-=fib[i];
        }
    }

    if(s)
        return 11;

    printf("%d\n", sol.size());

    for(int i=0; i<sol.size(); ++i)
        printf("%d ", sol[i]);
    printf("\n");

   /* for(int i=0; i<(1<<n); ++i)
    {
        tot=0;
        for(int j=0; j<n; ++j)
            if((i>>j)&1)
                tot+=fib[j+1];

        if(tot==s)
        {
            for(int j=0; j<n; ++j)
                if((i>>j)&1)
                    sol.push_back(fib[j+1]);
        }
    }

    printf("%d\n", sol.size());

    for(int i=0; i<sol.size(); ++i)
        printf("%d ", sol[i]);
    printf("\n");*/

    return 0;
}