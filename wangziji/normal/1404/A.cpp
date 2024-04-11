#include <iostream>
using namespace std;
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int n,k;
		string s;
		cin >> n >> k >> s;
		s=' '+s;
		int flag=1;
		for(int i=k+1;i<=n;i++)
		{
			if(s[i]=='1')
			{
				if(s[(i-1)%k+1]=='0') flag=0;
				else s[(i-1)%k+1]='1';
			}
			if(s[i]=='0')
			{
				if(s[(i-1)%k+1]=='1') flag=0;
				else s[(i-1)%k+1]='0';
			}
		}
		for(int i=k+1;i<=n;i++)
		{
			if(s[i]=='1') s[(i-1)%k+1]='1';
			else if(s[i]=='0') s[(i-1)%k+1]='0';
		}
	//	cout << s << "\n";
		if(!flag) puts("NO");
		else
		{
			int mn=0,mx=0;
			for(int i=1;i<=k;i++)
			{
				if(s[i]=='0') --mn,--mx;
				if(s[i]=='1') ++mx,++mn;
				if(s[i]=='?') --mn,++mx;
			}
			if(mx<0||mn>0) puts("NO");
			else puts("YES");
		}
	}
	return 0;
}