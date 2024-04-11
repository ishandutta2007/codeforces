#include <iostream>
using namespace std;
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int n,x,y;
		cin >> n >> x >> y;
		int ans=0;
		for(int i=1;i<=x;i++)
		{
			int t;
			cin >> t;
			ans|=t==n;
		}
		for(int i=1;i<=y;i++)
		{
			int t;
			cin >> t;
		}
		if(ans) puts("YES");
		else puts("NO");
	}
	return 0;
}