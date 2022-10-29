#include <iostream>
using namespace std;
int a[10],b[10];
int main(int argc, char** argv) {
	int n;
	cin >> n;
	int ans=0;
	for(int i=1;i<=6;i++)
		a[i]=n&(1<<6-i);
	b[6]=a[1],b[5]=a[6],b[4]=a[4],b[3]=a[3],b[2]=a[5],b[1]=a[2];
	for(int i=1;i<=6;i++)
		if(b[i]) ans|=(1<<i-1);
	cout << ans;
	return 0;
}