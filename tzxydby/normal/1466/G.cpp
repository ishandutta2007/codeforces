#include<bits/stdc++.h>
using namespace std;
const int N=100005,mod=1e9+7;
int n,m,k,q,p[N],sum[26][N];
string s,t;
vector<string>a;
vector<int>kmp(string &s)
{
	int n=s.size();
	vector<int>f(n,0);
	for(int i=1,j=0;i<n;i++)
	{
		while(j&&s[j]!=s[i])
			j=f[j-1];
		if(s[j]==s[i])
			j++;
		f[i]=j;
	}
	return f;
}
vector<int>sol(vector<int>&f,int n)
{
	vector<int>a(n+1,0);
	int p=f.back();
	while(p)
	{
		a[p]=1;
		p=f[p-1];
	}
	a[p]=1;
	return a;
}
int main()
{
	cin>>n>>q>>s>>t;
	a.push_back(s);
	for(auto c:t)
	{
		if(a.back().size()>=1e6)
			break;
		string x=a.back();
		a.push_back(x+c+x);
	}
	for(int i=0;i<26;i++)
		for(int j=0;j<n;j++)
			sum[i][j+1]=(sum[i][j]*2+(t[j]-'a'==i))%mod;
	p[0]=1;
	for(int i=1;i<=n;i++)
		p[i]=p[i-1]*2%mod;
	while(q--)
	{
		cin>>k>>t;
		m=t.size();
		int r=0;
		while(a[r].size()<m)
			r++;
		if(r>k)
		{
			cout<<0<<endl;
			continue;
		}
		string s1=t+"@"+a[r],s2=a[r]+"@"+t;
		auto f1=kmp(s1),f2=kmp(s2),v1=sol(f1,m),v2=sol(f2,m);
		int ans=0;
		for(auto v:f1)
			if(v==m)
				ans++;
		ans=1ll*ans*p[k-r]%mod;
		for(int i=0;i<m;i++)
		{
			if(!v1[i]||!v2[m-i-1])
				continue;
			int x=t[i]-'a';
			ans=(ans+sum[x][k])%mod;
			ans=(ans+mod-1ll*sum[x][r]*p[k-r]%mod)%mod;
		}
		cout<<ans<<endl;
	}
	return 0;
}