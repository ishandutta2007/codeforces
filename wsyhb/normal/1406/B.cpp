#include<bits/stdc++.h>
using namespace std;
const int buffer_size=1e5+5;
char buf[buffer_size],*S,*T;
inline char read_char()
{
    if(S==T) T=(S=buf)+fread(buf,1,buffer_size,stdin);
    return S!=T?*(S++):EOF;
}
inline int read_int()
{
    bool flag=false;
    char c=read_char();
    while(c<'0'||c>'9')
    {
        flag=(c=='-'?true:flag);
        c=read_char();
    }
    int x=0;
    while(c>='0'&&c<='9')
    {
        x=(x<<3)+(x<<1)+(c^48);
        c=read_char();
    }
    return flag?-x:x;
}
const int max_n=1e5+5;
int a[max_n];
vector<int> p,q;
int main()
{
	int t=read_int();
	while(t--)
	{
		p.clear(),q.clear();
		int n=read_int();
		long long ans=-1e18;
		for(int i=1;i<=n;++i)
		{
			a[i]=read_int();
			if(a[i]<0) p.push_back(-a[i]);
			else if(a[i]==0) ans=max(ans,0ll);
			else q.push_back(a[i]);
		}
		sort(p.begin(),p.end());
		sort(q.begin(),q.end());
		int x=p.size(),y=q.size();
		for(int i=0;i<=5;++i)
		{
			int j=5-i;
			if(x<i||y<j) continue;
			long long res=1;
			if(i%2==0)
			{
				for(int k=x-1;k>=x-i;--k)
					res*=p[k];
				for(int k=y-1;k>=y-j;--k)
					res*=q[k];
			}
			else
			{
				res=-1;
				for(int k=0;k<i;++k)
					res*=p[k];
				for(int k=0;k<j;++k)
					res*=q[k];
			}
			ans=max(ans,res);
		}
		printf("%lld\n",ans);
	}
	return 0;
}