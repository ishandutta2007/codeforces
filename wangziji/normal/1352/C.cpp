#include <iostream>
using namespace std;
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int n,k;
		cin >> n >> k;
		int ans=k/(n-1)*n;
		k%=n-1;
		if(k==0) --ans;
		cout << ans+k << "\n";
	}
	return 0;
}