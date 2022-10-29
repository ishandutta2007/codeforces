#include <iostream>
#include <cmath>
using namespace std;
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int a,b,c,d;
		cin >>a  >>b >> c >> d;
		int ans=abs(a-b);
		int x,y;
		x=min(abs(a-(c-d)),abs(a-(c+d)));
		if(a>=c-d&&a<=c+d)x=0;
		y=min(abs(b-(c-d)),abs(b-(c+d)));
		if(b>=c-d&&b<=c+d)y=0;
		//cout << x << " " << y << endl;
		cout << min(ans,x+y)  << endl;
	}
	return 0;
}