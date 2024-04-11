#include <iostream>
using namespace std;
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int a,b,c,d;
		cin >> a >> b >> c >> d;
		if((b-a)%(c+d)!=0)
			puts("-1");
		else cout << (b-a)/(c+d) << "\n";
	}
	return 0;
}