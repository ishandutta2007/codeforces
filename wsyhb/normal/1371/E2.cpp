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
int n,p;
const int max_n=1e5+5;
int a[max_n],b[max_n],cnt[max_n],sum[max_n],suf[max_n];
//inline bool check(int x)
//{
//	for(int i=1;i<=n;++i)
//	{
//		if(x+i-1<a[i])
//			return false;
//	}
//	return true;
//}
int main()
{
	scanf("%d%d",&n,&p);
	for(int i=1;i<=n;++i)
		scanf("%d",a+i);
	sort(a+1,a+n+1);
//	int L=1,R=1e9,mid,res=1e9;
//	while(L<=R)
//	{
//		mid=(L+R)>>1;
//		if(check(mid))
//			res=mid,R=mid-1;
//		else
//			L=mid+1;
//	}
	int ans_l=0;
	for(int i=1;i<=n;++i)
		ans_l=max(ans_l,a[i]-i+1);
	for(int i=1;i<=n;++i)
	{
		b[i]=max(a[i]-ans_l+1,1);
		++cnt[b[i]];
	}
	for(int i=1;i<=n;++i)
		sum[i]=sum[i-1]+cnt[i];
	for(int i=n;i>=1;--i)
		suf[i]=max(suf[i+1],sum[i]-(i-1));
	int ans_r=ans_l-1;
	for(int i=1,j=ans_l;i<=n;++i,++j)
	{
		if(sum[i]>=p||suf[i+1]+(i-1)>=p)
		{
			ans_r=j-1;
			break;
		}
	}
	printf("%d\n",ans_r-ans_l+1);
	for(int i=ans_l;i<=ans_r;++i)
		printf("%d ",i);
	puts("");
	return 0;
}