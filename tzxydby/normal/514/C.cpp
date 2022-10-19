#include<bits/stdc++.h>
using namespace std;
const int N=600005;
const long long MOD=1000000007;
long long p[N]={1};
set<long long>h;
long long Hash(string s)
{
	long long sum=0;
	for(int i=0;i<s.size();i++)
		sum=(257*sum+s[i])%MOD;
	return sum; 	
} 
int main()
{
	ios::sync_with_stdio(false);
	int n,m;
	string s;
	for(int i=1;i<N;i++)
		p[i]=257*p[i-1]%MOD;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>s;
		h.insert(Hash(s));
	}
	for(int i=1;i<=m;i++)
	{
		cin>>s;
		long long y=Hash(s);
		bool flag=0;
		for(int j=0;j<s.size();j++)
		{
			for(int k='a';k<='c';k++)
			{
				if(k==s[j])
					continue;
				long long x=(y+p[s.size()-j-1]*(k-s[j])+3*MOD)%MOD;
				if(h.find(x)!=h.end())
					flag=1;
			}
		}
		if(flag)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}