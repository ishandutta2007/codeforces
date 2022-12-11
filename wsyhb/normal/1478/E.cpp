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
const int P=1e9+7;
inline void add(int &a,int b)
{
    a=a+b-(a+b>=P?P:0);
}
inline void sub(int &a,int b)
{
    a=a-b+(a-b<0?P:0);
}
inline void mul(int &a,int b)
{
    a=1ll*a*b%P;
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
const int max_n=2e5+5;
char s[max_n],f[max_n];
const int max_q=2e5+5;
int l[max_q],r[max_q],cnt[max_n<<2],lazy[max_n<<2];
void build(int p,int l,int r)
{
	lazy[p]=0;
	if(l==r)
	{
		cnt[p]=f[l]-'0';
		return;
	}
	int mid=(l+r)>>1;
	build(p<<1,l,mid);
	build(p<<1|1,mid+1,r);
	cnt[p]=cnt[p<<1]+cnt[p<<1|1];
}
inline void push_down(int p,int l,int r,int mid)
{
	if(lazy[p]==1)
	{
		cnt[p<<1]=cnt[p<<1|1]=0;
		lazy[p<<1]=lazy[p<<1|1]=1;
	}
	else
	{
		cnt[p<<1]=mid-l+1,cnt[p<<1|1]=r-mid;
		lazy[p<<1]=lazy[p<<1|1]=2;
	}
	lazy[p]=0;
}
int res;
void query(int p,int l,int r,int a,int b)
{
	if(a<=l&&r<=b)
	{
		res+=cnt[p];
		return;
	}
	int mid=(l+r)>>1;
	if(lazy[p])
		push_down(p,l,r,mid);
	if(a<=mid)
		query(p<<1,l,mid,a,b);
	if(b>mid)
		query(p<<1|1,mid+1,r,a,b);
}
void modify_0(int p,int l,int r,int a,int b)
{
	if(a<=l&&r<=b)
	{
		cnt[p]=0;
		lazy[p]=1;
		return;
	}
	int mid=(l+r)>>1;
	if(lazy[p])
		push_down(p,l,r,mid);
	if(a<=mid)
		modify_0(p<<1,l,mid,a,b);
	if(b>mid)
		modify_0(p<<1|1,mid+1,r,a,b);
	cnt[p]=cnt[p<<1]+cnt[p<<1|1];
}
void modify_1(int p,int l,int r,int a,int b)
{
	if(a<=l&&r<=b)
	{
		cnt[p]=r-l+1;
		lazy[p]=2;
		return;
	}
	int mid=(l+r)>>1;
	if(lazy[p])
		push_down(p,l,r,mid);
	if(a<=mid)
		modify_1(p<<1,l,mid,a,b);
	if(b>mid)
		modify_1(p<<1|1,mid+1,r,a,b);
	cnt[p]=cnt[p<<1]+cnt[p<<1|1];
}
bool Flag;
void check(int p,int l,int r)
{
	if(l==r)
	{
		if(cnt[p]!=s[l]-'0')
			Flag=false;
		return;
	}
	int mid=(l+r)>>1;
	if(lazy[p])
		push_down(p,l,r,mid);
	check(p<<1,l,mid);
	if(Flag)
		check(p<<1|1,mid+1,r);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,q;
		scanf("%d%d%s%s",&n,&q,s+1,f+1);
		for(int i=1;i<=q;++i)
			scanf("%d%d",l+i,r+i);
		build(1,1,n);
		bool flag=false;
		for(int i=q;i>=1;--i)
		{
			res=0;
			query(1,1,n,l[i],r[i]);
			int len=r[i]-l[i]+1;
//			printf("l=%d r=%d len=%d res=%d\n",l[i],r[i],len,res);
			if(len&1)
			{
				if(res<=len/2)
					modify_0(1,1,n,l[i],r[i]);
				else
					modify_1(1,1,n,l[i],r[i]);
			}
			else
			{
				if(res==len/2)
				{
					flag=true;
					break;
				}
				if(res<len/2)
					modify_0(1,1,n,l[i],r[i]);
				else
					modify_1(1,1,n,l[i],r[i]);
			}
		}
		if(flag)
		{
			puts("NO");
			continue;
		}
		Flag=true;
		check(1,1,n);
		if(Flag)
			puts("YES");
		else
			puts("NO");
	}
    return 0;
}