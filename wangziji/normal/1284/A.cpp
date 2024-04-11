#include <iostream>
using namespace std;
string a[500],b[500];
int main(int argc, char** argv) {
	int n,m;
	cin >> n >> m;
	for(int i=0;i<n;i++)
		cin >> a[i];
	for(int i=0;i<m;i++)
		cin >> b[i];
	int T;
	cin >> T;
	while(T--)
	{
		int x;
		cin >> x;
		cout << a[(x-1)%n] << b[(x-1)%m] << endl;
	}
	return 0;
}