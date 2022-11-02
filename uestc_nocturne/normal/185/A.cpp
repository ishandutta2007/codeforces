/*
Author: elfness@UESTC
*/
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
using namespace std;
typedef long long LL;
const int P=1000000007;
struct Mat{int a[2][2];};
Mat Mul(Mat a,Mat b)
{
    Mat c;
    for(int i=0;i<2;i++)
    for(int j=0;j<2;j++)
    {
        c.a[i][j]=0;
        for(int k=0;k<2;k++)
        c.a[i][j]=(c.a[i][j]+(LL)a.a[i][k]*b.a[k][j]%P)%P;
    }
    return c;
}
int doit(LL n)
{
    Mat x,te;
    x.a[0][0]=x.a[1][1]=1;
    x.a[0][1]=x.a[1][0]=0;
    te.a[0][0]=te.a[1][1]=3;
    te.a[0][1]=te.a[1][0]=1;
    while(n)
    {
        if(n&1)x=Mul(x,te);
        n/=2;te=Mul(te,te);
    }
    return x.a[0][0];
}
LL n;
int main()
{
    while(~scanf("%I64d",&n))
    cout<<doit(n)<<endl;
}