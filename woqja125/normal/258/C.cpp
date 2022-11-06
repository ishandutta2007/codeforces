#include<stdio.h>
#include<algorithm>
#include<vector>
const int MOD = 1000000007;
int a[100001];
int c[100001];
int pow(int x, int r)
{
    int t=x, a=1;
    while(r)
    {
        if(r%2 == 1) a=1ll*a*t%MOD;
        t = 1ll*t*t%MOD;
        r/=2;
    }
    return a;
}
int main()
{
    int n, i, j;
    scanf("%d", &n);
    for(i=1; i<=n; i++)scanf("%d", a+i);
    std::sort(a+1, a+1+n);
    for(i=1; i<=n; i++) c[a[i]]++;
    for(i=1; i<=100000; i++) c[i] = c[i-1] + c[i];
    int ans = 1;
    for(i=a[n]; i>=2; i--)
    {
        std::vector<int> di;
        for(j=1; 1ll*j*j<i; j++)
        {
            if(i%j == 0)
            {
                di.push_back(j);
                di.push_back(i/j);
            }
        }
        if(1ll*j*j == i) di.push_back(j);
        std::sort(di.begin(), di.end());
        int t = 1;
        for(j=0; j<di.size()-1; j++)
        {
            t = 1ll*t*pow(j+1, c[di[j+1]-1]-c[di[j]-1])%MOD;
    //      printf("*%d\n", t);
        }
        ans = (0ll + MOD + ans - 1ll*t*pow(j, c[100000]-c[di[j]-1]))%MOD;
        t = 1ll*t*pow(j+1, c[100000]-c[di[j]-1])%MOD;
    //  printf("&%d %d\n", i, t);
        ans += t;
        ans %= MOD;
    }
    printf("%d", ans);
    return 0;
}