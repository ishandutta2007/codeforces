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
const int V=1020;
int ret[3*V];
int L[3*V][10020],R[3*V][10020];
int tmp[2][20020];
const int N=5005;
int a[V];
void init(int k,int l,int r)
{
    if(l==r)
    {
        ret[k]=0;
        memset(L[k],0,sizeof(L[k]));
        memset(R[k],0,sizeof(R[k]));
        L[k][N-a[l]]=1;
        L[k][N+a[l]]=1;
        R[k][N-a[l]]=1;
        R[k][N+a[l]]=1;
        return;
    }
    int mid=(l+r)/2;
    init(k*2,l,mid);
    init(k*2+1,mid+1,r);
    ret[k]=(ret[k*2]+ret[k*2+1])%P;
    for(int j=0;j<=2*N;j++)
    ret[k]=(ret[k]+(LL)R[k*2][j]*L[k*2+1][2*N-j])%P;
    int fl=0,te=1;
    memset(L[k],0,sizeof(L[k]));
    memset(tmp[0],0,sizeof(tmp[0]));tmp[0][N]=1;
    for(int i=l;i<=r;i++)
    {
        te=1-fl;
        memset(tmp[te],0,sizeof(tmp[te]));
        for(int j=0;j<=2*N;j++)
        if(tmp[fl][j]!=0)
        {
            if(j+a[i]<=2*N)
            {
                tmp[te][j+a[i]]+=tmp[fl][j];
                tmp[te][j+a[i]]%=P;
            }
            if(j-a[i]>=0)
            {
                tmp[te][j-a[i]]+=tmp[fl][j];
                tmp[te][j-a[i]]%=P;
            }
        }
        for(int j=0;j<=2*N;j++)
        L[k][j]=(L[k][j]+tmp[te][j])%P;
        fl=te;
    }
    memset(R[k],0,sizeof(R[k]));
    memset(tmp[0],0,sizeof(tmp[0]));tmp[0][N]=1;
    fl=0;
    for(int i=r;i>=l;i--)
    {
        te=1-fl;
        memset(tmp[te],0,sizeof(tmp[te]));
        for(int j=0;j<=2*N;j++)
        if(tmp[fl][j]!=0)
        {
            if(j+a[i]<=2*N)
            {
                tmp[te][j+a[i]]+=tmp[fl][j];
                tmp[te][j+a[i]]%=P;
            }
            if(j-a[i]>=0)
            {
                tmp[te][j-a[i]]+=tmp[fl][j];
                tmp[te][j-a[i]]%=P;
            }
        }
        for(int j=0;j<=2*N;j++)
        R[k][j]=(R[k][j]+tmp[te][j])%P;
        fl=te;
    }
}
int n;
int main()
{
    while(~scanf("%d",&n))
    {
        for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
        init(1,1,n);
        printf("%d\n",ret[1]);
    }
    return 0;
}