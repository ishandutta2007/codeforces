#include <iostream>
using namespace std;
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int n,k;
		cin >> n >> k;
		if(n%2&&k%2==0||n<k)
		{
			puts("NO");
			continue;
		}
		if(n<2*k&&n%2==0&&k%2==1)
		{
			puts("NO");
			continue;
		}
		puts("YES");
		if(n%2==k%2)
		{
			for(int i=1;i<k;i++)
				cout << 1 << ' ';
			cout << n-k+1 << "\n";
		}
		else
		{
			for(int i=1;i<k;i++)
			{
				cout << 2 << ' ';
				n-=2;
			}
			cout << n << "\n"; 
		}
	}
	return 0;
}