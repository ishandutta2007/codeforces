#include<bits/stdc++.h>
using namespace std;
int n,k;
const int max_n=1500+5;
string s[max_n];
inline long long trans(const string &s)
{
	long long res=0;
	for(int i=0;i<k;++i)
		res=res*3+(s[i]=='S'?0:(s[i]=='E'?1:2));
	return res;
}
int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>k;
	for(int i=1;i<=n;++i)
		cin>>s[i];
	map<long long,int> cnt;
	long long ans=0;
	for(int i=1;i<=n;++i)
	{
		for(int j=i+1;j<=n;++j)
		{
			string t;
			for(int x=0;x<k;++x)
			{
				if(s[i][x]==s[j][x])
					t+=s[i][x];
				else
					t+='S'+'E'+'T'-s[i][x]-s[j][x];
			}
			ans+=cnt[trans(t)];
		}
		++cnt[trans(s[i])];
	}
	printf("%lld\n",ans);
	return 0;
}