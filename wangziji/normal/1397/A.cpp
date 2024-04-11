#include <iostream>
#include <cstring>
using namespace std;
int cnt[1005];
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		memset(cnt,0,sizeof cnt);
		for(int i=1;i<=n;i++)
		{
			string s;
			cin >> s;
			for(auto x:s) ++cnt[x];
		}
		int flag=1;
		for(int i=1;i<=200;i++)
		{
			if(cnt[i]%n!=0) flag=0;
		}
		if(!flag) puts("NO");
		else puts("YES");
	}
	return 0;
}