#include<bits/stdc++.h>
using namespace std;
const int P=1e9+7;
inline void add(int &a,int b)
{
    a=a+b-(a+b>=P?P:0);
}
inline int get_sum(int a,int b)
{
    return a+b-(a+b>=P?P:0); 
}
inline int get_dif(int a,int b)
{
    return a-b+(a-b<0?P:0);
}
inline int get_pro(int a,int b)
{
    return 1ll*a*b%P;
}
const int max_n=1e6+5;
char s[max_n];
int f[max_n],g[max_n],sum[max_n],pre[max_n],suf[max_n],p[max_n];
int main()
{
    int n,k;
    scanf("%d%d%s",&n,&k,s+1);
    int cnt=0;
    p[0]=1;
    for(int i=1;i<=n;++i)
    {
        if(s[i]=='W')
            cnt=0;
        else
            ++cnt;
        if(cnt>=k)
            f[i]=get_dif(get_dif(p[i-k],pre[i-k]),get_dif(sum[i-1],sum[i-k]));
        sum[i]=get_sum(sum[i-1],f[i]);
        if(s[i]=='X')
        {
            pre[i]=get_sum(get_sum(pre[i-1],pre[i-1]),f[i]);
            p[i]=get_sum(p[i-1],p[i-1]);
        }
        else
        {
            pre[i]=get_sum(pre[i-1],f[i]);
            p[i]=p[i-1];
        }
    }
    cnt=0;
    p[n+1]=1;
    for(int i=n;i>=1;--i)
    {
        if(s[i]=='B')
            cnt=0;
        else
            ++cnt;
        if(cnt>=k)
            g[i]=get_dif(get_dif(p[i+k],suf[i+k]),get_dif(sum[i+1],sum[i+k]));
        sum[i]=get_sum(sum[i+1],g[i]); 
        if(s[i]=='X')
        {
            suf[i]=get_sum(get_sum(suf[i+1],suf[i+1]),g[i]);
            p[i]=get_sum(p[i+1],p[i+1]);
        }
        else
        {
            suf[i]=get_sum(suf[i+1],g[i]);
            p[i]=p[i+1];
        }
    }
    int ans=0;
    for(int i=1;i<=n;++i)
        add(ans,get_pro(f[i],suf[i+1]));
    printf("%d\n",ans);
    return 0;
}