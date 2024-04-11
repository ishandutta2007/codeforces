#include <iostream>
using namespace std;
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int a,b,c;
		cin >> a >> b >> c;
		int ans=0;
		while(max(a,b)<=c)
		{
			++ans;
			if(a>b) b+=a;
			else a+=b;
		}
		cout << ans << "\n";
	}
	return 0;
}