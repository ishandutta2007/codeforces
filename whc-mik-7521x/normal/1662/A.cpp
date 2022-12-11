#include<bits/stdc++.h>
#define ll long long
#define lll __int128
#define db double
#define ld long double
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
namespace IO
{
	const int SZ=1<<20;
	char gchar()
	{
	    static char buf[SZ];
	    static int i=SZ;
	    if(i==SZ)i=0,fread(buf,1,SZ,stdin);
	    return buf[i++];
	}
	void pchar(char c)
	{
	    static char buf[SZ];
	    static int i=0;
	    if(c)buf[i++]=c;
	    if(!c||i==SZ)fwrite(buf,1,i,stdout),i=0;
	}
	void pstr(string s,char end='\n')
	{
		for(char c:s)pchar(c);
		pchar(end);
	}
	template<typename T>void read(T &x)
	{
	    x=0;int f=1;
	    static char c;
	    while((c=gchar())>'9'||c<'0')if(c=='-')f=-1;
	    x=c-'0';
	    while((c=gchar())>='0'&&c<='9')
			x=(x<<1)+(x<<3)+(c^48);
		x*=f;
	}
	template<typename T>void i_write(T x)
	{
	    if(x>9)i_write(x/10);
	    pchar(x%10+'0');
	}
	template<typename T>void write(T x,char end='\n')
	{
	    if(x<0)pchar('-'),x=-x;
	    if(x>9)i_write(x/10);
	    pchar(x%10+'0');
	    pchar(end);
	}
}
using IO::read;
using IO::write;
const int N=110;
int t,n,b[N],d[N],mx[20];
int main()
{
	read(t);
	while(t--)
	{
		read(n);
		for(int i=1;i<=10;i++)mx[i]=0;
		for(int i=1;i<=n;i++)read(b[i]),read(d[i]),mx[d[i]]=max(mx[d[i]],b[i]);
		int ans=0;
		for(int i=1;i<=10;i++)
			if(!mx[i])ans=-1;
			else if(ans!=-1)ans+=mx[i];
		if(ans==-1)IO::pstr("MOREPROBLEMS"s);
		else write(ans);
	}
	IO::pchar(0);
	return 0;
}