#include <iostream>
using namespace std;
int a[5005];
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		int s=0,mx=0;
		for(int i=1;i<=n;i++)
			cin >> a[i];
		for(int i=1;i<=n;i++)
			s+=a[i],mx=max(mx,a[i]);
		if(s<mx+mx) puts("T");
		else
		{
			if(s&1) puts("T");
			else puts("HL");
		}
	}
	return 0;
}