#include <iostream>
using namespace std;
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		long long a,b,c;
		cin >> a >> b >> c;
		if(a<c) cout << 1 << " ";
		else cout << -1 << " ";
		if(a*b>c) cout << b << "\n";
		else cout << -1 << "\n";
	}
	return 0;
}