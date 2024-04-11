#include <cstdio>
#include <algorithm>

using namespace std;

#define maxn 100010

int n;
long long sol, d[maxn][3];
int v[maxn];

int main()
{
  //  freopen("data.in", "r", stdin);
  //  freopen("data.out", "w", stdout);

    scanf("%d", &n);
    for(int i=1; i<n; ++i)
        scanf("%d", &v[i]);

    for(int i=1; i<n; ++i)
    {
        if(v[i]>1)
            d[i][0]=d[i-1][0]+(v[i]/2)*2;
        else
            d[i][0]=0;

        d[i][1]=max(d[i-1][0], d[i-1][1])+((v[i]-1)/2)*2+1;

        if(v[i]>1)
            d[i][2]=max(d[i-1][1], d[i-1][2])+(v[i]/2)*2;
        else
            d[i][2]=0;

        sol=max(max(sol, d[i][0]), max(d[i][1], d[i][2]));
    }

    printf("%I64d\n", sol);

    return 0;
}