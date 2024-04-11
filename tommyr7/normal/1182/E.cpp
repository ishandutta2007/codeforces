#include <bits/stdc++.h>
using namespace std;
#define modp 1000000006
#define modp1 1000000007
long long n;
int f1,f2,f3,c;
int a[3][3],now[3];
int power(int a,long long b)
{
    int res=1,now=a;
    long long left=b;
    while (left>0)
    {
        if (left%2==1) res=(1LL*res*now)%modp1;
        now=(1LL*now*now)%modp1;
        left/=2;
    }
    return res;
}
void multiply1()
{
    int res[3];
    memset(res,0,sizeof(res));
    for (int i=0;i<3;i++)
        for (int j=0;j<3;j++)
            res[i]=(res[i]+(1LL*a[i][j]*now[j]%modp))%modp;
    for (int i=0;i<3;i++)
        now[i]=(res[i]%modp+modp)%modp;
}
void multiply2()
{
    int res[3][3];
    memset(res,0,sizeof(res));
    for (int i=0;i<3;i++)
        for (int j=0;j<3;j++)
            for (int k=0;k<3;k++)
                res[i][k]=(res[i][k]+(1LL*a[i][j]*a[j][k]%modp))%modp;
    for (int i=0;i<3;i++)
        for (int j=0;j<3;j++)
            a[i][j]=(res[i][j]%modp+modp)%modp;
}
int calc(int A,int B,int C)
{
    now[0]=C,now[1]=B,now[2]=A;
    a[0][0]=1,a[0][1]=1,a[0][2]=1;
    a[1][0]=1,a[1][1]=0,a[1][2]=0;
    a[2][0]=0,a[2][1]=1,a[2][2]=0;
    long long left=n-3;
    while (left>0)
    {
        if (left%2==1) multiply1();
        left/=2;
        multiply2();
    }
    return (now[0]%modp+modp)%modp;
}
int main()
{
    scanf("%lld%d%d%d%d",&n,&f1,&f2,&f3,&c);
    f1=(1LL*f1*c)%modp1;
    f2=(1LL*f2*c)%modp1;
    f2=(1LL*f2*c)%modp1;
    f3=(1LL*f3*c)%modp1;
    f3=(1LL*f3*c)%modp1;
    f3=(1LL*f3*c)%modp1;
    int ans=1;
    ans=(1LL*ans*power(f1,calc(1,0,0)))%modp1;
    ans=(1LL*ans*power(f2,calc(0,1,0)))%modp1;
    ans=(1LL*ans*power(f3,calc(0,0,1)))%modp1;
    ans=(1LL*ans*power(power(c,modp1-2),n))%modp1;
    printf("%d\n",(ans+modp1)%modp1);
    return 0;
}