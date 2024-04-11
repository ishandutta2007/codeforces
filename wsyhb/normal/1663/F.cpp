#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s,t;
	cin>>s;
	int len=s.size();
	if(len==4)
	{
		puts("none");
		return 0;
	}
	if(len==3)
		t="the";
	else if(len==5)
		t="buffy";
	else if(len==6)
		t="slayer";
	else
	{
		assert(len==7);
		t="vampire";
	}
	string ans;
	ans.resize(len);
	for(int i=0;i<len;++i)
		ans[i]=((s[i]-'a')+(t[i]-'a'))%26+'a';
	cout<<ans<<endl;
	return 0;
}