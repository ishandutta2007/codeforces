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
    bool flag_EOF;
    inline int read_int()
    {
        char c=read_char();
        bool neg=false;
        while(c<'0'||c>'9')
        {
            if(c==EOF)
            {
                flag_EOF=true;
                return 0;
            }
            neg=(c=='-');
            c=read_char();
        }
        int x=0;
        while(c>='0'&&c<='9')
        {
            x=x*10+(c^48);
            c=read_char();
        }
        return neg?-x:x;
    }
}
const int max_n=1e3+5;
const int max_k=1e3+5;
bitset<max_n<<1> a[max_k<<1];
int t[max_n<<1],pos[max_n],b[max_k<<1],x[max_n<<1];
inline int color_id(char c)
{
	if(c=='W')
		return 0;
	if(c=='R')
		return 1;
	if(c=='Y')
		return 2;
	return 3;
}
int main()
{
	int n=IO::read_int(),k=IO::read_int(),cnt=0;
	for(int i=1;i<=n;++i)
		t[i<<1]=1,t[i<<1|1]=2;
	for(int i=1;i<=k;++i)
	{
		char op1=IO::read_char();
		while(op1!='m'&&op1!='R'&&op1!='Y')
			op1=IO::read_char();
		char op2=IO::read_char();
		int m=IO::read_int();
		for(int j=1;j<=m;++j)
			pos[j]=IO::read_int();
		if(op1=='m')
		{
			char res=IO::read_char();
			while(res!='W'&&res!='R'&&res!='Y'&&res!='B')
				res=IO::read_char();
			int c=color_id(res);
			++cnt;
			for(int j=1;j<=m;++j)
			{
				int p=pos[j];
				a[cnt][p<<1]=t[p<<1]&1;
				a[cnt][p<<1|1]=t[p<<1]>>1;
			}
			b[cnt]=c&1;
			++cnt;
			for(int j=1;j<=m;++j)
			{
				int p=pos[j];
				a[cnt][p<<1]=t[p<<1|1]&1;
				a[cnt][p<<1|1]=t[p<<1|1]>>1;
			}
			b[cnt]=c>>1;
		}
		else if(op1=='R')
		{
			if(op2=='Y')
			{
				for(int j=1;j<=m;++j)
				{
					int p=pos[j];
					swap(t[p<<1],t[p<<1|1]);
				}
			}
			else
			{
				for(int j=1;j<=m;++j)
				{
					int p=pos[j];
					t[p<<1|1]^=t[p<<1];
				}
			}
		}
		else
		{
			for(int j=1;j<=m;++j)
			{
				int p=pos[j];
				t[p<<1]^=t[p<<1|1];
			}
		}
	}
	int r=1;
	for(int i=2;i<=2*n+1&&r<=cnt;++i)
	{
		int k=r;
		while(k<=cnt&&!a[k][i])
			++k;
		if(k>cnt)
			continue;
		if(k!=r)
		{
			swap(a[r],a[k]);
			swap(b[r],b[k]);
		}
		for(int j=1;j<=cnt;++j)
		{
			if(j!=r&&a[j][i])
			{
				a[j]^=a[r];
				b[j]^=b[r];
			}
		}
		++r;
	}
	for(int i=r;i<=cnt;++i)
	{
		if(b[i])
		{
			puts("NO");
			return 0;
		}
	}
	for(int i=1;i<=r-1;++i)
	{
		int j=2;
		while(!a[i][j])
			++j;
		x[j]=b[i];
//		for(int k=j+1;k<=2*n+1;++k)
//		{
//			if(a[i][k])
//				x[j]^=x[k];
//		}
	}
	puts("YES");
	for(int i=1;i<=n;++i)
	{
		int c=x[i<<1|1]<<1|x[i<<1];
		putchar(".RYB"[c]);
	}
	putchar('\n');
    return 0;
}