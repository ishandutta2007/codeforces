#include <iostream>
using namespace std;
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		int lst=0;
		cin >> lst;
		int ans=0;
		for(int i=2;i<=n;i++)
		{
			int x;
			cin >> x;
			if(x>=lst) ++ans;
			lst=x;
		}
		if(!ans) puts("NO");
		else puts("YES");
	}
	return 0;
}