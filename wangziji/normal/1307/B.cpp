#include <iostream>
using namespace std;
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int n,m;
		cin >> n >> m;
		int mx=0,flag=0;
		for(int i=1;i<=n;i++)
		{
			int t;
			cin >> t;
			mx=max(mx,t);
			if(t==m) flag=1;
		}
		if(flag) puts("1");
		else cout << max((m-1)/mx+1,2) << "\n";
	}
	return 0;
}