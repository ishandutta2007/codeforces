#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int x,n,m;
		cin >> x >> n >> m;
		while(n--)
		{
			if(x/2+10<=x) x=x/2+10;
		}
		if(x>10*m) puts("NO");
		else puts("YES");
	}
	return 0;
}