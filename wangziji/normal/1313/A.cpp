#include <iostream>
using namespace std;
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int a,b,c;
		cin >> a >> b >> c;
		int ans=0;
		if(a) --a,++ans;
		if(b) --b,++ans;
		if(c) --c,++ans;
		if(a<b) swap(a,b);
		if(b<c) swap(b,c);
		if(a<b) swap(a,b);
		//cout << a << " " << b << " " << c << endl;
		if(a&&b) --a,--b,++ans;
		if(a&&c) --a,--c,++ans;
		if(c&&b) --c,--b,++ans;
		if(a&&b&&c) --a,--b,--c,++ans;
		cout << ans << "\n";
	}
	return 0;
}