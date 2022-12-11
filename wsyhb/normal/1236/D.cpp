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
const int max_n=1e5+5;
const int max_m=1e5+5;
vector<int> row[max_n],col[max_m];
int main()
{
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=k;++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		row[x].push_back(y);
		col[y].push_back(x);
	}
	for(int i=1;i<=n;++i)
		sort(row[i].begin(),row[i].end());
	for(int i=1;i<=m;++i)
		sort(col[i].begin(),col[i].end());
	int a=1,b=1,d=0;
	int la=1,lb=1,ra=n,rb=m;
	long long cnt=1;
	while(1)
	{
//		fprintf(stderr,"a=%d b=%d d=%d la=%d ra=%d lb=%d rb=%d\n",a,b,d,la,ra,lb,rb);
		int ta=a,tb=b;
		if(d==0)
		{
			int x=upper_bound(row[a].begin(),row[a].end(),b)-row[a].begin();
			if(x<int(row[a].size()))
				tb=min(row[a][x]-1,rb);
			else
				tb=rb;
			la=a+1;
		}
		else if(d==1)
		{
			int x=upper_bound(col[b].begin(),col[b].end(),a)-col[b].begin();
			if(x<int(col[b].size()))
				ta=min(col[b][x]-1,ra);
			else
				ta=ra;
			rb=b-1;
		}
		else if(d==2)
		{
			int x=lower_bound(row[a].begin(),row[a].end(),b)-row[a].begin()-1;
			if(x>=0&&x<int(row[a].size()))
				tb=max(row[a][x]+1,lb);
			else
				tb=lb;
			ra=a-1;
		}
		else if(d==3)
		{
			int x=lower_bound(col[b].begin(),col[b].end(),a)-col[b].begin()-1;
			if(x>=0&&x<int(col[b].size()))
				ta=max(col[b][x]+1,la);
			else
				ta=la;
			lb=b+1;
		}
		if(a==1&&b==1&&ta==1&&tb==1&&d==0)
		{
			d=1;
			continue;
		}
		if(ta==a&&tb==b)
			break;
		cnt+=abs(ta-a)+abs(tb-b);
		a=ta,b=tb;
		d=(d+1)&3;
	}
	if(cnt==1ll*n*m-k)
		puts("Yes");
	else
		puts("No");
    return 0;
}