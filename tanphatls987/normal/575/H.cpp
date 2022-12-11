#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;
const int MAXN = 2000006;

int gt[MAXN], N;

int power(int a, int N)
{
    if (N==0) return 1;
    int x = power(a,N/2);
    x=(x*1ll*x)%MOD;
    if (N&1) x=(x*1ll*a)%MOD;
    return x;
}

int inv(int t)
{
    return power(t,MOD-2);
}

int C(int k, int n)
{
    return (gt[n]*1ll*((inv(gt[k])*1ll*inv(gt[n-k]))%MOD))%MOD;
}

int main()
{
    scanf("%d",&N);
    gt[0]=1;
    for(int i=1; i<=2*N+5; i++) gt[i]=(gt[i-1]*1ll*i)%MOD;
    int res = 0;
    for(int i=0; i<=N; i++)
    {
        int t = C(i+1,N+i+1);
        res+=t;
        if (res>=MOD) res-=MOD;
    }
    printf("%d\n",res);
    return 0;
}