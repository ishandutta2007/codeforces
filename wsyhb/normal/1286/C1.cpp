#include<bits/stdc++.h>
using namespace std;
inline bool cmp(string x,string y)
{
	return x.size()<y.size();
}
const int max_n=100+5;
int tot[max_n][26];
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
	if(n==2)
	{
		cout<<"? 1 1"<<endl;
		cout<<"? 2 2"<<endl;
		string s,t;
		cin>>s>>t;
		cout<<"! "<<s<<t<<endl;
		return 0;
	}
	int len=(n+1)/2;
	map<string,int> cnt;
	cout<<"? 1 "<<len<<endl;
	for(int i=1;i<=len*(len+1)/2;++i)
	{
		string s;
		cin>>s;
		sort(s.begin(),s.end());
		++cnt[s];
	}
	cout<<"? 2 "<<len<<endl;
	for(int i=1;i<=len*(len-1)/2;++i)
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
	for(int i=1;i<len;++i)
	{
		int res=0;
		for(int j=0;j<(int)S[i-1].size();++j)
			res^=S[i-1][j];
		for(int j=0;j<(int)S[i].size();++j)
			res^=S[i][j];
		ans+=(char)res;
	}
	cout<<"? 1 "<<n<<endl;
	for(int i=1;i<=n*(n+1)/2;++i)
	{
		string s;
		cin>>s;
		int l=s.size();
		for(int j=0;j<l;++j)
			++tot[l][s[j]-'a']; 
	}
	for(int i=len+1;i<=n;++i)
	{
		int a=n-i,b=n-(i-1),res=0;
		for(int x=0;x<26;++x)
		{
			int delta=(tot[a+1][x]-tot[a][x])-(tot[b+1][x]-tot[b][x]);
			if(delta&1)
				res^=x;
		}
		ans+=(res^(ans[(a+1)-1]-'a'))+'a';
	}
	cout<<"! "<<ans<<endl;
	return 0;
}