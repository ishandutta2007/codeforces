#include <iostream>
using namespace std;
int A[100005];
int main(int argc, char** argv) {
	int a,b,c,x,y,z;
	int n;
	cin >> n;
	cout << "? 1 2" << endl;
	cin >> a;
	cout << "? 1 3" << endl;
	cin >> b;
	cout << "? 2 3" << endl;
	cin >> c;
	A[1]=(a+b+c)/2-c;
	A[2]=a-A[1];
	A[3]=b-A[1];
	for(int i=4;i<=n;i++)
	{
		cout << "? 1 " << i << endl;
		cin >> A[i];
		A[i]-=A[1];
	}
	cout << "! "; 
	for(int i=1;i<=n;i++)
		cout << A[i] << " ";
	cout << endl;
	return 0;
}