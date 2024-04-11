#include <iostream>
using namespace std;
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int x,y;
		cin >> x >> y;
		int qwq=min(x,y)+1;
		if(x<=qwq&&y<=qwq)
		{
			cout << x+y << "\n";
		 } 
		else cout << max(x,y)-qwq+x+y << "\n";
	}
	return 0;
}