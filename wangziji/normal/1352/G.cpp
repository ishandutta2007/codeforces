#include <iostream>
using namespace std;
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		if(n<=3)
		{
			puts("-1");
			continue;
		}
		if(n==7)
		{
			puts("5 1 3 6 2 4 7 ");
			continue;
		}
		int now=0;
		while(n%4==3||n%4==2)
		{
			cout << now+1 << " " << now+4 << " " << now+2 << " " << now+5 << " " << now+3 << " ";
			now+=5;
			n-=5; 
		}
		while(n>=4)
		{
			cout << now+2 << " " << now+4 << " " << now+1 << " " << now+3 << " ";
			now+=4;
			n-=4;
		}
		if(n==1)
		{
			cout << now+1;
			n=0; 
		}
		puts("");
	}
	return 0;
}