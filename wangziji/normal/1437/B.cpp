#include <iostream>
using namespace std;
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		string a;
		cin >> n >> a;
		int ans=0;
		for(int i=1;i<n;i++)
			ans+=a[i]==a[i-1];
		cout << (ans+1)/2 << "\n";
	}
	return 0;
}