#include <iostream>
using namespace std;
int main(int argc, char** argv) {
	int a,b,c,d;
	cin >> a >> b >> c >> d;
	if(a+b==c+d)
		cout << "YES";
	else if(a+c==b+d)
		cout << "YES";
	else if(a+d==b+c)
		cout << "YES";
	else if(a==b+c+d||b==a+c+d||c==a+b+d||d==a+b+c)
		cout << "YES";
	else
		cout << "NO";
	return 0;
}