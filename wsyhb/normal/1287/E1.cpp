#include<bits/stdc++.h>
using namespace std;
inline bool cmp(string x,string y)
{
	return x.size()<y.size();
}
int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	if(n==1)
	{
		cout<<"? 1 1"<<endl;
		string s;
		cin>>s;
		cout<<"! "<<s<<endl;
		return 0;
	}
	map<string,int> cnt;
	cout<<"? 1 "<<n<<endl;
	for(int i=1;i<=n*(n+1)/2;++i)
	{
		string s;
		cin>>s;
		sort(s.begin(),s.end());
		++cnt[s];
	}
	cout<<"? 2 "<<n<<endl;
	for(int i=1;i<=n*(n-1)/2;++i)
	{
		string s;
		cin>>s;
		sort(s.begin(),s.end());
		--cnt[s];
	}
	vector<string> S;
	for(map<string,int>::iterator it=cnt.begin();it!=cnt.end();++it)
	{
		if(it->second>0)
			S.push_back(it->first);
	}
	sort(S.begin(),S.end(),cmp);
	string ans;
	ans.push_back(S[0][0]);
	for(int i=1;i<n;++i)
	{
		int res=0;
		for(int j=0;j<(int)S[i-1].size();++j)
			res^=S[i-1][j];
		for(int j=0;j<(int)S[i].size();++j)
			res^=S[i][j];
		ans+=(char)res;
	}
	cout<<"! "<<ans<<endl;	
	return 0;
}