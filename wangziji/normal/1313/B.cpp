#include <iostream>
using namespace std;
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int n,x,y;
		cin >> n >> x >> y;
		int s=x+y;
		if(x+y<=n)
			cout << "1 ";
		else
			cout << min(n,x+y-n+1) << ' ';
		cout << min(n,x+y-1) << "\n";
	}
	return 0;
}