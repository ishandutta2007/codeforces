#include <iostream>
using namespace std;
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		string s,ans;
		int x;
		cin >> s >> x;
		ans=s;
		for(int i=0;i<s.size();i++)
			ans[i]='1';
		for(int i=0;i<s.size();i++)
		{
			if(s[i]=='0')
			{
				if(i+x<s.size()) ans[i+x]='0';
				if(i-x>=0) ans[i-x]='0';
			}
		}
		int flag=1;
		for(int i=0;i<s.size();i++)
		{
			if(s[i]=='0') continue;
			int t=0;
			if(i+x<s.size()&&ans[i+x]=='1') t=1;
			if(i-x>=0&&ans[i-x]=='1') t=1;
			flag&=t;
		}
		if(!flag) puts("-1");
		else cout << ans << "\n";
	}
	return 0;
}