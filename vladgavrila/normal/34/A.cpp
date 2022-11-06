#include <stdio.h>

using namespace std;

#define maxn 1010

int n, i, j, k, sol, a, b;
int v[maxn];

int ab(int a)
{
    if(a>0) return a;
    return -a;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    #endif
    scanf("%d", &n);
    for(int i=1; i<=n; ++i)
        scanf("%d", &v[i]);
    a=n;
    b=1;
    sol=ab(v[n]-v[1]);
    for(int i=1; i<n; ++i)
    {
        if(ab(v[i]-v[i+1])<sol)
        {
            sol=ab(v[i]-v[i+1]);
            a=i;
            b=i+1;
        }
    }
    printf("%d %d\n", a, b);
    return 0;
}