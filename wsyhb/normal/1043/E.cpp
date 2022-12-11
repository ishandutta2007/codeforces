#include<bits/stdc++.h>
using namespace std;
namespace IO
{
    const int buffer_size=1e5+5;
    char buf[buffer_size],*S,*T;
    bool flag_EOF;
    inline char read_char()
    {
        if(S==T)
            T=(S=buf)+fread(buf,1,buffer_size,stdin);
        return S!=T?*(S++):EOF;
    }
    inline int read_int()
    {
        int flag=1;
        char c=read_char();
        while(c<'0'||c>'9')
        {
            if(c==EOF)
            {
                flag_EOF=true;
                return 0;
            }
            flag=(c=='-'?-1:1);
            c=read_char();
        }
        int x=0;
        while(c>='0'&&c<='9')
        {
            x=x*10+(c^48);
            c=read_char();
        }
        return x*flag;
    }
    char st[13];
    int _top;
    void Write(int x)
    {
        if(!x)
        {
            putchar('0');
            return;
        }
        if(x<0)
        {
            putchar('-');
            x=-x;
        }
        while(x)
        {
            st[++_top]=x%10+'0';
            x/=10;
        }
        while(_top>0)
            putchar(st[_top--]);
    }
}
const int max_n=3e5+5;
int x[max_n],y[max_n],pos[max_n];
long long ans[max_n];
inline bool cmp(int a,int b)
{
    return y[a]-x[a]<y[b]-x[b];
}
int main()
{
    int n=IO::read_int(),m=IO::read_int();
    for(int i=1;i<=n;++i)
        x[i]=IO::read_int(),y[i]=IO::read_int(),pos[i]=i;
    sort(pos+1,pos+n+1,cmp);
    long long sum=0;
    for(int j=1,i=pos[j];j<=n;++j,i=pos[j])
    {
        ans[i]=1ll*(j-1)*x[i]+1ll*(n-j)*y[i]+sum;
        sum+=y[i];
    }
    sum=0;
    for(int j=n,i=pos[j];j>=1;--j,i=pos[j])
    {
        ans[i]+=sum;
        sum+=x[i];
    }
    for(int i=1;i<=m;++i)
    {
        int u=IO::read_int(),v=IO::read_int();
        int score=min(x[u]+y[v],x[v]+y[u]);
        ans[u]-=score,ans[v]-=score;
    }
    for(int i=1;i<=n;++i)
        printf("%lld%c",ans[i],i<n?' ':'\n');
    return 0;
}