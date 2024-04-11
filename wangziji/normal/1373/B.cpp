#include <iostream>
using namespace std;
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		string a;
		cin >> a;
		int x=0,y=0;
		for(auto c:a)
			x+=c=='0',y+=c=='1';
		if(min(x,y)&1) puts("DA");
		else puts("NET");
	}
	return 0;
}