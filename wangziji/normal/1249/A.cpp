#include <iostream>
#include <cstring>
using namespace std;
int a[1000];
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		int ans=1;
		memset(a,0,sizeof a);
		for(int i=1;i<=n;i++)
		{
			int x;
			cin >> x;
			if(a[x-1]||a[x+1])
				ans=2;
			a[x]=1;
		}
		cout << ans << endl;
	}
	return 0;
}