#include <cstdio>
#include <algorithm>

using namespace std;

#define maxn 100010

int n, m;
int v[maxn], mn[maxn], mx[maxn];

int main()
{
    scanf("%d", &n);
    for(int i=1; i<=n; ++i)
        scanf("%d", &v[i]);

    mn[1]=v[2]-v[1];
    mx[1]=v[n]-v[1];

    mn[n]=v[n]-v[n-1];
    mx[n]=v[n]-v[1];

    for(int i=2; i<n; ++i)
    {
        mn[i]=min(v[i]-v[i-1], v[i+1]-v[i]);
        mx[i]=max(v[n]-v[i], v[i]-v[1]);
    }

    for(int i=1; i<=n; ++i)
        printf("%d %d\n", mn[i], mx[i]);

    return 0;
}