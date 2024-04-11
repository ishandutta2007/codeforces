#include <iostream>
using namespace std;
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int n,m,x;
		int ans=1;
		cin >> n >> m >> x;
		while(n%2==0) n>>=1,ans<<=1;
		while(m%2==0) m>>=1,ans<<=1;
		if(ans>=x)
		{
			puts("YES");
		}else puts("NO");
	}
	return 0;
}