#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
using namespace std;
map <int,int> mp;
int qwq[1000005];
signed main(int argc, char** argv) {
	int T;
	ios::sync_with_stdio(false);
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		string s;
		cin >> s;
		for(int i=0;i<s.size();i++) qwq[i]=1e9;
		int cnt=0;
		long long ans=0;
		for(int i=0;i<s.size();i++)
		{
			if(s[i]=='*') ++cnt,qwq[i]=0;
			else qwq[i]=min(qwq[i],cnt);
		}
		cnt=0;
		for(int i=s.size()-1;i>=0;i--)
		{
			if(s[i]=='*') ++cnt,qwq[i]=0;
			else qwq[i]=min(qwq[i],cnt);
		}
		for(int i=0;i<s.size();i++)
			ans+=qwq[i];
		cout << ans << "\n";
	}
	return 0;
}