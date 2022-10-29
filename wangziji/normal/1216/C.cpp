#include <iostream>
using namespace std;
int main(int argc, char** argv) {
	int a,b,c,d,a2,b2,c2,d2,a3,b3,c3,d3;
	cin >> a >> b >> c >> d >> a2 >> b2 >> c2 >> d2 >> a3 >> b3 >> c3 >> d3;
	if(a2<=a&&b2<=b&&c2>=c&&d2>=d)
	{
		cout << "NO";
		return 0;
	}
	if(a3<=a&&b3<=b&&c3>=c&&d3>=d)
	{
		cout << "NO";
		return 0;
	}
	if(d2>=b3&&a2<=a&&c2>=c&&a3<=a&&c3>=c&&b2<=b&&d3>=d)
	{
		cout << "NO";
		return 0;
	}
	if(d3>=b2&&a3<=a&&c3>=c&&a2<=a&&c2>=c&&b3<=b&&d2>=d)
	{
		cout << "NO";
		return 0;
	}
	if(c2>=a3&&b2<=b&&d2>=d&&b3<=b&&d3>=d&&a2<=a&&c3>=c)
	{
		cout << "NO";
		return 0;
	}
	if(c3>=a2&&b3<=b&&d3>=d&&b2<=b&&d2>=d&&a3<=a&&c2>=c)
	{
		cout << "NO";
		return 0;
	}
	cout << "YES";
	return 0;
}