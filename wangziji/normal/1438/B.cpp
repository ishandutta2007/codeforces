#include <iostream>
using namespace std;
int a[100005];
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		for(int i=1;i<=n;i++) cin >> a[i];
		int flag=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(a[i]==a[j]) flag=1;
			}
		}
		if(flag) puts("YES");
		else puts("NO");
	}
	return 0;
}