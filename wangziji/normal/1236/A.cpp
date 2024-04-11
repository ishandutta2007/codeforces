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
		ans=min(b,c/2);
		b-=ans;
		ans+=min(a,b/2);
		cout << ans*3 << endl;
	}
	return 0;
}