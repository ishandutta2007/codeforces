#include <iostream>
using namespace std;
int a[100005],b[100005];
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		int flag=1;
		for(int i=1;i<=n;i++)
			cin >> a[i];
		for(int i=1;i<=n;i++)
			cin >> b[i];
		for(int i=2;i<=n;i++)
			if(a[i]<a[i-1]) flag=0;
		for(int i=2;i<=n;i++)
			if(b[i]!=b[i-1]) flag=1;
		if(flag) puts("Yes");
		else puts("No");
	}
	return 0;
}