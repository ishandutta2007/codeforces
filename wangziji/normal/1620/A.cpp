#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		string s;
		int E=0,N=0;
		cin >> s;
		
		for(auto t:s)
		{
			if(t=='E') ++E;
			else ++N;
		}
		if(E==s.size()-1&&s.size()>1)
		{
			cout << "NO\n";
		}
		else cout << "YES\n";
	}
	return 0;
}