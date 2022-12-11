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
	inline void Write(int x)
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
int A[4][4],B[4][4];
typedef pair<int,int> P;
map<P,int> vis;
int main()
{
	long long k;
	int a,b;
	cin>>k>>a>>b;
	for(int i=1;i<=3;++i)
		for(int j=1;j<=3;++j)
			cin>>A[i][j];
	for(int i=1;i<=3;++i)
		for(int j=1;j<=3;++j)
			cin>>B[i][j];
	long long ans1=0,ans2=0;
	vis[P(a,b)]=1;
	if(a!=b)
	{
		if((a==3&&b==2)||(a==2&&b==1)||(a==1&&b==3))
			++ans1;
		else
			++ans2;
	}
	int cir=0;
	long long now=k+1;
	for(int i=2;i<=k;++i)
	{
		int x=A[a][b],y=B[a][b];
		a=x,b=y;
		if(a!=b)
		{
			if((a==3&&b==2)||(a==2&&b==1)||(a==1&&b==3))
				++ans1;
			else
				++ans2;
		}
		if(vis[P(a,b)]!=0)
		{
			cir=i-vis[P(a,b)];
			now=i+1;
			break;
		}
		vis[P(a,b)]=i;
	}
	while(now<=k&&(k-now+1)%cir!=0)
	{
		int x=A[a][b],y=B[a][b];
		a=x,b=y;
		if(a!=b)
		{
			if((a==3&&b==2)||(a==2&&b==1)||(a==1&&b==3))
				++ans1;
			else
				++ans2;
		}
		++now;
	}
	int cnt1=0,cnt2=0;
	for(int i=1;i<=cir;++i)
	{
		int x=A[a][b],y=B[a][b];
		a=x,b=y;
		if(a!=b)
		{
			if((a==3&&b==2)||(a==2&&b==1)||(a==1&&b==3))
				++cnt1;
			else
				++cnt2;
		}
	}
	if(cir>0)
	{
		ans1+=1ll*(k-now+1)/cir*cnt1;
		ans2+=1ll*(k-now+1)/cir*cnt2;
	}
	cout<<ans1<<" "<<ans2<<endl;
	return 0;
}