#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(int argc, char** argv) {
	ios::sync_with_stdio(false),cin.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		string s,t;
		cin >> s >> t;
		sort(s.begin(),s.end());
		if(t=="abc")
		{
			int l=0,r=0;
			for(int i=0;i<s.size();i++)
			{
				if(s[i]=='b')
				{
					if(!l) l=i;
				}
				else if(s[i]=='c') r=i;
			}
			if(s[0]=='a'&&l&&r)reverse(s.begin()+l,s.begin()+r+1);
		}
		cout << s << "\n";
	}
	return 0;
}