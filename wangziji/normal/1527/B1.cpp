#include <iostream>
#include <map>
using namespace std;
map <int,long long> mp;
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		string s;
		cin >> n >> s;
		int cnt=0;
		for(auto t:s) cnt+=t=='0';
		if(n%2==0||s[n/2]=='1')
		{
			if(cnt&3) puts("BOB");
			else puts("BOB");
		}
		else
		{
			if(cnt>=3)puts("ALICE");
			else puts("BOB");
		}
	}
	return 0;
}