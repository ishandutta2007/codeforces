#include <cstdio>
#include <algorithm>

using namespace std;

#define maxn 100100

int n, sol;
int v[maxn], mxp[maxn], mnp[maxn];

int main()
{
    scanf("%d", &n);

    for(int i=1; i<=n; ++i)
    {
        scanf("%d", &v[i]);
        mxp[i]=max(mxp[i-1], v[i]);
    }

    sol=1;
    mnp[n]=v[n];
    for(int i=n-1; i>0; --i)
    {
        mnp[i]=min(mnp[i+1], v[i]);

        if(mnp[i+1]>=mxp[i])
            ++sol;
    }

    printf("%d\n", sol);

    return 0;
}