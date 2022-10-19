#include<bits/stdc++.h>
using namespace std;
const int N=20,mod=2520;
int T,cur,a[mod+1];
long long l,r,f[20][mod+1][50];
vector<int>dim;
inline int __lcm(int x,int y){if(!y)return x;return x/__gcd(x,y)*y;}
long long dfs(int x,int mode,int lcm,bool op)
{
    if(!x)
        return mode%lcm==0?1:0;
    if(!op&&f[x][mode][a[lcm]])
        return f[x][mode][a[lcm]];
    int maxx=op?dim[x]:9;
    long long ret=0;
    for(int i=0;i<=maxx;i++)
        ret+=dfs(x-1,(mode*10+i)%mod,__lcm(lcm,i),op&(i==maxx));
    if(!op)
        f[x][mode][a[lcm]]=ret;
    return ret;
}
long long solve(long long x)
{
    dim.clear();
    dim.push_back(-1);
    long long t=x;
    while(t)
    {
        dim.push_back(t%10);
        t/=10;
    }
    return dfs(dim.size()-1,0,1,1);
}
int main()
{
    for(int i=1;i<=mod;i++)
        if(mod%i==0)
            a[i]=++cur;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%I64d%I64d",&l,&r);
        printf("%I64d\n",solve(r)-solve(l-1));
    }
    return 0;
}