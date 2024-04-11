#include<bits/stdc++.h>
using namespace std;
const int N=1000005,mx=1000002;
int n,m,x[N],y[N];
long long ans;
string a,b,s;
vector<int>cal(string s)
{
	int n=s.size();
	vector<int>z(n,0);
	int l=0,r=0;
	for(int i=1;i<n;i++)
	{
		if(i>r)
		{
			l=r=i;
			while(r<n&&s[r-l]==s[r])
				r++;
			z[i]=r-l;
			r--;
		}
		else
		{
			int k=i-l;
			if(z[k]<r-i+1)
				z[i]=z[k];
			else
			{
				l=i;
				while(r<n&&s[r-l]==s[r])
					r++;
				z[i]=r-l;
				r--;
			}
		}
	}
	return z;
}
struct bit
{
	long long b[N];
	void init()
	{
		for(int i=0;i<=mx;i++)
			b[i]=0;
	}
	void add(int x,long long v)
	{
		x++;
		for(int i=x;i<=mx;i+=i&(-i))
			b[i]+=v;
	}
	long long ask(int x)
	{
		x++;
		long long v=0;
		for(int i=x;i;i-=i&(-i))
			v+=b[i];
		return v;
	}
}b1,b2;
int main()
{
	ios::sync_with_stdio(0);
	cin>>n>>m>>a>>b>>s;
	string ma=s+"@"+a;
	vector<int>za=cal(ma);
	for(int i=0;i<n;i++)
		x[i]=za[m+i+1];
	string rs=s;reverse(rs.begin(),rs.end());
	string rb=b;reverse(rb.begin(),rb.end());
	string mb=rs+"@"+rb;
	vector<int>zb=cal(mb);
	for(int i=0;i<n;i++)
		y[i]=zb[mb.size()-i-1];
	b1.init(),b2.init();
	for(int i=0;i<n;i++)
	{
		if(x[i]==m)
			x[i]--;
		if(y[i]==m)
			y[i]--;
	}
	for(int i=0;i<n;i++)
	{
		if(x[i])
		{
			b1.add(x[i],1);
			b2.add(x[i],x[i]);
		}
		int p=i-m+1;
		if(p>=0&&x[p])
		{
			b1.add(x[p],-1);
			b2.add(x[p],-x[p]);
		}
		if(y[i])
		{
			long long v1=b1.ask(mx-1)-b1.ask(max(0,m-y[i]-1));
			long long v2=b2.ask(mx-1)-b2.ask(max(0,m-y[i]-1));
			ans+=v1*y[i]+v2-(m-1)*v1;
		}
	}
	cout<<ans<<endl;
	return 0;
}