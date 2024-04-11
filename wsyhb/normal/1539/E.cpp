#include<bits/stdc++.h>
using namespace std;
namespace IO
{
    const int buf_size=1<<20;
    char buf[buf_size],*S,*T;
    inline char read_char()
    {
        if(S==T)
            T=(S=buf)+fread(buf,1,buf_size,stdin);
        return S!=T?*(S++):EOF;
    }
    inline int read_int()
    {
        char c=read_char();
        bool neg=false;
        while(c<'0'||c>'9')
        {
            neg=(c=='-');
            c=read_char();
        }
        int x=0;
        while(c>='0'&&c<='9')
        {
            x=x*10+(c^'0');
            c=read_char();
        }
        return neg?-x:x;
    }
    char fw[buf_size];
    int pw;
    inline void flush()
    {
        fwrite(fw,1,pw,stdout);
        pw=0;
    }
    inline void write_char(char x)
    {
        fw[pw++]=x;
        if(pw==buf_size)
            flush();
    }
    inline void write_int(int x)
    {
        if(!x)
        {
            write_char('0');
            return;
        }
        if(x<0)
        {
            write_char('-');
            x=-x;
        }
        static char st[26];
        int tp=0;
        while(x)
        {
            st[++tp]=x%10^'0';
            x/=10;
        }
        while(tp>0)
            write_char(st[tp--]);
    }
}
int n,m;
const int max_n=1e5+5;
int k[max_n],al[max_n],bl[max_n],ar[max_n],br[max_n];
inline bool check(int x,int L,int R)
{
	return x>=L&&x<=R;
}
inline bool check_inter(int L1,int R1,int L2,int R2)
{
	return max(L1,L2)<=min(R1,R2);
}
inline void inter(int L1,int R1,int L2,int R2,int &resL,int &resR)
{
	resL=max(L1,L2),resR=min(R1,R2);
	assert(resL<=resR);
}
int ans[max_n];
random_device rd;
uniform_int_distribution<int> p(0,1);
void dfs(int x)
{
	if(!x)
	{
		puts("Yes");
		for(int i=1;i<=n;++i)
			printf("%d%c",ans[i],i<n?' ':'\n');
		exit(0);
	}
	if(clock()>=2.4*CLOCKS_PER_SEC)
	{
		puts("No");
		exit(0);
	}
	bool fl=check(k[x],al[x],bl[x])&&check_inter(ar[x],br[x],ar[x-1],br[x-1]);
	bool fr=check(k[x],ar[x],br[x])&&check_inter(al[x],bl[x],al[x-1],bl[x-1]);
	int Al=al[x-1],Bl=bl[x-1],Ar=ar[x-1],Br=br[x-1];
	if(fl&&fr)
	{
//		if(!p(rd))
//		{
			ans[x]=0;
			inter(ar[x-1],br[x-1],ar[x],br[x],ar[x-1],br[x-1]);
			dfs(x-1);
			ar[x-1]=Ar,br[x-1]=Br;
			ans[x]=1;
			inter(al[x-1],bl[x-1],al[x],bl[x],al[x-1],bl[x-1]);
			dfs(x-1);
			al[x-1]=Al,bl[x-1]=Bl;
//		}
//		else
//		{
//			ans[x]=1;
//			inter(al[x-1],bl[x-1],al[x],bl[x],al[x-1],bl[x-1]);
//			dfs(x-1);
//			al[x-1]=Al,bl[x-1]=Bl;
//			ans[x]=0;
//			inter(ar[x-1],br[x-1],ar[x],br[x],ar[x-1],br[x-1]);
//			dfs(x-1);
//			ar[x-1]=Ar,br[x-1]=Br;
//		}
	}
	else if(fl)
	{
		ans[x]=0;
		inter(ar[x-1],br[x-1],ar[x],br[x],ar[x-1],br[x-1]);
		dfs(x-1);
		ar[x-1]=Ar,br[x-1]=Br;
	}
	else if(fr)
	{
		ans[x]=1;
		inter(al[x-1],bl[x-1],al[x],bl[x],al[x-1],bl[x-1]);
		dfs(x-1);
		al[x-1]=Al,bl[x-1]=Bl;
	}
}
int main()
{
//	freopen("input.txt","r",stdin);
	n=IO::read_int(),m=IO::read_int();
	for(int i=1;i<=n;++i)
	{
		k[i]=IO::read_int();
		al[i]=IO::read_int(),bl[i]=IO::read_int();
		ar[i]=IO::read_int(),br[i]=IO::read_int();
		bool fl=check(k[i],al[i],bl[i]),fr=check(k[i],ar[i],br[i]);
		bool Fl=check_inter(al[i-1],bl[i-1],al[i],bl[i]);
		bool Fr=check_inter(ar[i-1],br[i-1],ar[i],br[i]);
		bool flag_l=fl&&Fr,flag_r=fr&&Fl;
		if(!flag_l&&!flag_r)
		{
			puts("No");
			return 0;
		}
		if(!flag_l)
		{
			ar[i]=br[i]=k[i];
			inter(al[i-1],bl[i-1],al[i],bl[i],al[i],bl[i]);
		}
		else if(!flag_r)
		{
			al[i]=bl[i]=k[i];
			inter(ar[i-1],br[i-1],ar[i],br[i],ar[i],br[i]);
		}
	}
	dfs(n);
	puts("No");
	return 0;
}