#pragma GCC target("avx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#include<bits/stdc++.h>
using namespace std;
const int N=200005,M=505;
struct st
{
	string s;
	int c[30];
	void rd()
	{
		cin>>s;
		for(int i=0;i<26;i++)
			c[i]=0;
		for(int i=0;i<s.size();i++)
			c[s[i]-'a']++;
	}
	bool operator<(const st k)const
	{
		for(int i=0;i<26;i++)
			if(c[i]!=k.c[i])
				return c[i]<k.c[i];
		return s<k.s;
	}
}a[N];
string s[N];
int ok(int x,int y)
{
	for(int i=0;i<26;i++)
		if(a[x].c[i]!=a[y].c[i])
			return 0;
	return 1;
}
int n,m;
long long ans;
int main()
{
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		a[i].rd();
	m=a[1].s.size();
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		s[i]=a[i].s;
	if(n<=4000)
	{
		for(int l=1;l<=n;)
		{
			int r=l;
			while(r<=n&&ok(l,r))
				r++;
			ans+=1337ll*(r-l)*(n-r+1);
			r--;
			for(int i=l;i<=r;i++)
			{
				for(int j=i+1;j<=r;j++)
				{
					int x=m,y=1,f1=1,f2=1;
					for(int k=0;k<m;k++)
						if(s[i][k]!=s[j][k])
							x=min(x,k),y=max(y,k);
					for(int k=x;k<y;k++)
					{
						if(s[i][k]>s[i][k+1])
							f1=0;
						if(s[j][k]>s[j][k+1])
							f2=0;
					}
					if(f1||f2)
						ans++;
					else
						ans+=2;
				}
			}
			l=r+1;
		}
	}
	else
	{
		for(int l=1;l<=n;)
		{
			int r=l;
			while(r<=n&&ok(l,r))
				r++;
			ans+=1337ll*(r-l)*(n-r+1);
			r--;
			ans+=1ll*(r-l+1)*(r-l);
			for(int i=0;i<m;i++)
			{
				for(int j=i+1;j<m;j++)
				{
					for(int p=l;p<=r;p++)
					{
						string t=s[p];
						sort(t.begin()+i,t.begin()+j+1);
						if(t[i]!=s[p][i]&&t[j]!=s[p][j]&&binary_search(s+l,s+r+1,t))
							ans--;	
					}
				}
			}
			l=r+1;
		}
	}
	printf("%lld\n",ans);
	return 0;
}