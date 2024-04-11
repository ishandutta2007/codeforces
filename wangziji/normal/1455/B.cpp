#include <iostream>
using namespace std;
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int x;
		cin >> x;
		int qwq=0,ans=0;
		for(int i=1;i<=100000;i++)
		{
			qwq+=i;
			++ans;
			if(qwq>=x) break;
		}
		if(qwq==x) cout << ans << "\n";
		else if(qwq==x+1) cout << ans+1 << "\n";
		else cout << ans << "\n";
	}
	return 0;
}