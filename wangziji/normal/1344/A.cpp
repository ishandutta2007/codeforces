#include <iostream>
using namespace std;
int vis[200005];
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		int flag=1;
		for(int i=0;i<n;i++) vis[i]=0;
		for(int i=1;i<=n;i++)
		{
			int x;
			cin >> x;
			x%=n;
			x+=n;
			x%=n;
			if(vis[(x+i-1)%n]) flag=0;
			vis[(x+i-1)%n]=1;
		}
		if(flag) puts("YES");
		else puts("NO");
	}
	return 0;
}