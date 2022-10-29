#include <iostream>
using namespace std;
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int a,b,c;
		cin >> a >> b >> c;
		if(!(b&1))
		{
			if(b)
			{
				cout << 1;
				--b;
			}
		}
		if(a||b) cout << 0;
		for(int i=1;i<=a;i++)
			cout << 0;
		int now=1;
		for(int i=1;i<=b;i++)
		{
			cout << now;
			now^=1;
		} 
		for(int i=1;i<=c;i++)
			cout << 1;
		if(!a&&!b) cout << 1;
		puts("");
	}
	return 0;
}