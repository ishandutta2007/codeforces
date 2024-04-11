#include<bits/stdc++.h>
using namespace std;
int n;
map<string,int> mpa;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		string s;cin>>s;
		mpa[s]++;
	}
	for(int i=1;i<=n;++i)
	{
		string s;cin>>s;
		mpa[s]--;
	}
	int ans=0;
	string s1="M";string s2="L";string s3="S";
	ans+=max(abs(mpa[s1]),max(abs(mpa[s2]),abs(mpa[s3])));
	string str3="XL";
	ans+=abs(mpa[str3]);
	string str4="XXL";
	ans+=abs(mpa[str4]);
	string str5="XXXL";
	ans+=abs(mpa[str5]);
	cout<<ans<<endl;
	return 0;
}