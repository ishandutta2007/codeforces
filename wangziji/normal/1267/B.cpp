#include <iostream>
using namespace std;
int x[500005],y[500005];
int main(int argc, char** argv) {
	string a;
	cin >> a;
	int cnt=0,lst=0;
	a+=' ';
	for(int i=0;i<a.size()-1;i++)
	{
		if(a[i]!=a[i+1])
		{
			x[++cnt]=a[i];
			y[cnt]=i+1;
		}
	}
	if(!cnt%2||y[cnt/2+1]-y[cnt/2]<2)
	{
		cout << 0;
		return 0;
	}
	int A=(cnt/2),B=cnt/2+2;
	for(int i=cnt/2;i>0;i--)
	{
		if(x[A]!=x[B]||y[A]+y[B]-y[A-1]-y[B-1]<3)
		{
			cout << 0;
			return 0;
		}
		--A,++B;
	}
	cout << y[cnt/2+1]-y[cnt/2]+1;
	return 0;
}