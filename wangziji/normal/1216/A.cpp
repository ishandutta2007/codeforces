#include <iostream>
using namespace std;
char c[200005];
int main(int argc, char** argv) {
	int n,a=0,b=0,ans=0;
	cin >> n >> c;
	for(int i=1;i<n;i+=2)
	{
		if(c[i]!=c[i-1])
			continue;
		c[i]='a'+'b'-c[i-1];
		++ans;
	}
	cout << ans << endl << c;
	return 0;
}