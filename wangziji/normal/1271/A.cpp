#include <iostream>
using namespace std;
int main(int argc, char** argv) {
	int a,b,c,d,e,f;
	int ans=0;
	cin >> a >> b >> c >> d >> e >> f;
	for(int i=0;i<=d;i++)
	{
		if(i<=a)
		{
			ans=max(ans,i*e+min(d-i,min(b,c))*f);
		}
	}
	cout << ans;
	return 0;
}