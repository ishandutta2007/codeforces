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
const int V=100100;
const int N=100000;
const int P=1000000007;
int Pow(int x,int y)
{
    int ret=1;
    while(y)
    {
        if(y&1)ret=(LL)ret*x%P;
        x=(LL)x*x%P;y/=2;
    }
    return ret;
}
struct List{int num,ne;}e[V*30];
int p[V],K;
void add(int x,int y)
{
    e[K].num=y;e[K].ne=p[x];p[x]=K++;
}
int s[V],n,a[V];
int main()
{
    while(~scanf("%d",&n))
    {
        memset(s,0,sizeof(s));
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            s[a[i]]++;
        }
        for(int i=N;i>=0;i--)
        s[i]+=s[i+1];
        memset(p,-1,sizeof(p));K=0;
        for(int i=N;i>=1;i--)
        for(int j=i;j<=N;j+=i)
        add(j,i);
        int ret=0;
        for(int i=1;i<=N;i++)
        {
            int tmp=1;
            int now=0;
            int last=0;
            for(int j=p[i];j!=-1;j=e[j].ne)
            {
                now++;
                int k=e[j].num;
                int nx=e[j].ne;
                if(nx==-1)last=s[k];
                else tmp=(LL)tmp*Pow(now,s[k]-s[e[nx].num])%P;;
            }
            tmp=(LL)tmp*(Pow(now,last)-Pow(now-1,last))%P;
            ret=(ret+tmp)%P;
            if(ret<0)ret+=P;
        }
        printf("%d\n",ret);
    }
}