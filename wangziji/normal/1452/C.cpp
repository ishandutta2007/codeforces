#include <iostream>
using namespace std;
int cnt1,cnt2;
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		string s;
		cin >> s;
		int ans=0;
		cnt1=cnt2=0;
		for(auto t:s)
		{
			if(t=='(') ++cnt1;
			if(t==')')
			{
				if(cnt1) ++ans,--cnt1;
			}
			if(t=='[') ++cnt2;
			if(t==']')
			{
				if(cnt2) ++ans,--cnt2;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}