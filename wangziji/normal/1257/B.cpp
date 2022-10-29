#include <iostream>
using namespace std;
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int x,y;
		cin >> x >> y;
		if(x==2) x=3;
		if(x>=4)
			puts("YES");
		else
		{
			if(x>=y)
				puts("YES");
			else
				puts("NO");
		}
	}
	return 0;
}