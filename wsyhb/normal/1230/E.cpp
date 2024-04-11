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
const int mod=1e9+7;
inline void add(int &a,int b)
{
    a=a+b-(a+b>=mod?mod:0);
}
inline void sub(int &a,int b)
{
    a=a-b+(a-b<0?mod:0);
}
inline void mul(int &a,int b)
{
    a=1ll*a*b%mod;
}
inline int get_sum(int a,int b)
{
    return a+b-(a+b>=mod?mod:0);
}
inline int get_dif(int a,int b)
{
    return a-b+(a-b<0?mod:0);
}
inline int get_pro(int a,int b)
{
    return 1ll*a*b%mod;
}
inline int get_power(int a,int n)
{
    int res=1;
    while(n>0)
    {
        if(n&1)
            mul(res,a);
        mul(a,a);
        n>>=1;
    }
    return res;
}
inline long long gcd(long long a,long long b)
{
    return b?gcd(b,a%b):a;
}
const int max_n=1e5+5;
long long v[max_n];
vector<int> edge[max_n];
typedef pair<long long,int> P;
vector<P> num[max_n];
map<long long,int> id[max_n];
void dfs(int x,int fa)
{
    num[x].push_back(P(v[x],1));
    id[x][v[x]]=int(num[x].size());
    for(int i=0;i<int(edge[x].size());++i)
    {
        int y=edge[x][i];
        if(y!=fa)
        {
            for(int j=0;j<int(num[x].size());++j)
            {
                long long d=gcd(num[x][j].first,v[y]);
                int p=id[y][d];
                if(p!=0)
                    num[y][p-1].second+=num[x][j].second;
                else
                {
                    num[y].push_back(P(d,num[x][j].second));
                    id[y][d]=int(num[y].size());
                }
            }
            dfs(y,x);
        }
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
        scanf("%lld",v+i);
    for(int i=1;i<=n-1;++i)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    dfs(1,0);
    int ans=0;
    for(int i=1;i<=n;++i)
        for(int j=0;j<int(num[i].size());++j)
            add(ans,get_pro(num[i][j].first%mod,num[i][j].second));
    printf("%d\n",ans);
    return 0;
}