#include <cstdio>
#include <algorithm>

using namespace std;

int n, x, sol;
int v[4];

int main()
{
//    freopen("data.in", "r", stdin);
//    freopen("data.out", "w", stdout);

    scanf("%d", &n);
    for(int i=1; i<=n; ++i)
    {
        scanf("%d", &x);
        if(x==4)
            ++sol;
        else
            ++v[x];
    }

    sol+=v[3];
    v[1]=max(0, v[1]-v[3]);

    sol+=(v[2]/2+v[2]%2);
    if(v[2]%2==1)
        v[1]=max(0, v[1]-2);

    sol+=v[1]/4;
    if(v[1]%4!=0)
        ++sol;

    printf("%d\n", sol);

    return 0;
}