#include<bits/stdc++.h>
using namespace std;
int n;
const int max_n=1e6+5;
struct Binary
{
	int v[max_n];
	inline Binary(int x=0)
	{
		for(int i=n-1;i>=0;--i)
			v[i]=0;
		int now=0;
		while(x)
		{
			v[now++]=x&1;
			x>>=1;
		}
		assert(now<=n);
	}
	inline Binary(const char *s)
	{
		for(int i=n-1;i>=0;--i)
			v[i]=s[n-1-i]^'0';
	}
	inline void print()
	{
		for(int i=n-1;i>=0;--i)
			putchar(v[i]^'0');
		putchar('\n');
	}
	inline Binary plus_1()
	{
		static Binary res;
		res=*this;
		for(int i=0;i<=n-1;++i)
		{
			if(!res.v[i])
			{
				for(int j=i;j>=0;--j)
					res.v[j]^=1;
				return res;
			}
		}
		assert(false);
		return Binary();
	}
}l,r,x,y,ans;
inline bool operator < (const Binary &a,const Binary &b)
{
	for(int i=n-1;i>=0;--i)
	{
		if(a.v[i]!=b.v[i])
			return a.v[i]<b.v[i];
	}
	return false;
}
inline bool operator <= (const Binary &a,const Binary &b)
{
	for(int i=n-1;i>=0;--i)
	{
		if(a.v[i]!=b.v[i])
			return a.v[i]<b.v[i];
	}
	return true;
}
inline bool operator != (const Binary &a,const Binary &b)
{
	for(int i=n-1;i>=0;--i)
	{
		if(a.v[i]!=b.v[i])
			return true;
	}
	return false;
}
inline Binary operator ^ (const Binary &a,const Binary &b)
{
	static Binary res;
	for(int i=n-1;i>=0;--i)
		res.v[i]=a.v[i]^b.v[i];
	return res;
}
char sl[max_n],sr[max_n];
int main()
{
	scanf("%d%s%s",&n,sl,sr);
	if(n==1)
	{
		printf("%s\n",sr);
		return 0;
	}
	l=Binary(sl),r=Binary(sr);
	bool flag_same=true;
	for(int i=n-1;i>=2;--i)
	{
		if(flag_same)
		{
			if(l.v[i]==r.v[i])
				x.v[i]=y.v[i]=l.v[i];
			else
			{
				assert(l.v[i]==0&&r.v[i]==1);
				x.v[i]=0,y.v[i]=1;
				flag_same=false;
			}
		}
		else
			x.v[i]=1,y.v[i]=0;
	}
	x.v[0]=1,y.v[0]=0;
	for(int p=0;p<=1;++p)
		for(int q=0;q<=1;++q)
		{
			x.v[1]=p,y.v[1]=q;
			if(l<=x&&x<=y&&y<=r)
				ans=max(ans,x^y^Binary(p==q));
		}
	if(l!=r&&(!l.v[0]||l.plus_1()!=r))
		ans=max(ans,Binary(1));
	if(!r.v[0]&&l!=r&&l.plus_1()!=r)
		ans=max(ans,r.plus_1());
	else
		ans=max(ans,r);
	ans.print();
	return 0;
}