#include <cstdio>
#include <algorithm>

using namespace std;

#define maxn 100010

int n, i, j, m, k;
char v[maxn];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    #endif

    scanf("%d%d\n", &n, &m);
    fgets(v+1, maxn, stdin);

    for(int i=1; i<n && m>0; ++i)
    {
        if(v[i]=='4' && v[i+1]=='7')
        {
            if(v[i-1]=='4' && i%2==0 && m>10)
            {
                m%=2;
                i=max(i-2, 0);
                continue;
            }
            --m;
            if(i%2==1)
                v[i+1]='4';
            else
                v[i]='7';
            i=max(i-2, 0);
        }
    }

    for(int i=1; i<=n; ++i)
        printf("%c", v[i]);
    printf("\n");

    return 0;
}