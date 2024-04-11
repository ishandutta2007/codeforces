#include <stdio.h>
#include <map>

using namespace std;

#define maxn 200010
#define mod 1000000007

int n, i, j, k, rez;
int mp[maxn];
long long sol;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    #endif
    scanf("%d", &n);
    for(int i=n+1; i<=2*n; ++i)
    {
        int x=i;
        for(int j=2; 1LL*j*j<=1LL*x; ++j)
        {
            while(x%j==0)
            {
                mp[j]++;
                x=x/j;
            }
        }
        mp[x]++;
    }
    for(int i=2; i<=n; ++i)
    {
        int x=i;
        for(int j=2; 1LL*j*j<=1LL*x; ++j)
        {
            while(x%j==0)
            {
                mp[j]--;
                x=x/j;
            }
        }
        mp[x]--;
    }
    sol=1;
    for(int i=2; i<=2*n; ++i)
    {
        for(int j=1; j<=mp[i]; ++j)
        {
            sol=(sol*i)%mod;
        }
    }
    rez=sol-n;
    if(rez<0)
        rez+=mod;
    printf("%d\n", rez);
    return 0;
}