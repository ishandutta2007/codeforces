#include <iostream>
using namespace std;
int main(int argc, char** argv) {
	string s;
	cin >> s;
	for(int i=0;i<s.size();i++) s[i]-='A';
	for(int i=2;i<s.size();i++)
	{
		if(s[i]!=(s[i-1]+s[i-2])%26)
		{
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	return 0;
}