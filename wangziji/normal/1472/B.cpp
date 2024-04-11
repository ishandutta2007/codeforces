#include <iostream>
using namespace std;
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int s=0,flag=0;
		int n;
		cin >> n;
		for(int i=1;i<=n;i++)
		{
			int x;
			cin >> x;
			s+=x;
			if(x==1) flag=1;
		}
		if(s&1)
		{
			puts("NO");
		}
		else if(flag||s%4==0) puts("YES");
		else puts("NO");
	}
	return 0;
}