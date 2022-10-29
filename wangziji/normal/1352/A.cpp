#include <iostream>
using namespace std;
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		string s;
		cin >> s;
		int cnt=0;
		for(auto x:s)
		{
			if(x!='0')
			{
				++cnt;
			}
		}
		cout << cnt << "\n";
		for(int i=0;i<s.size();i++)
		{
			if(s[i]!='0')
			{
				cout << s[i];
				for(int j=i+1;j<s.size();j++)
					cout << '0';
				cout << " ";
			}
		}
		puts("");
	}
	return 0;
}