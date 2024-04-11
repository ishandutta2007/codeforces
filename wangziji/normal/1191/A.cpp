#include <iostream>
using namespace std;
char a[10]={'D','A','C','B'};
int main(int argc, char** argv) {
	int n;
	cin >> n;
	char ans='z';
	int t=0;
	for(int i=0;i<=2;i++)
	{
		if(a[(n+i)%4]<ans)
			ans=a[(n+i)%4],t=i;
	}
	cout << t << " " << ans;
	return 0;
}